-- All customers who never placed an order
WITH orders_by_user AS
(SELECT
    customer_id,
    count(order_id) AS order_count
FROM
    orders
GROUP BY
    customer_id)
SELECT
    c.customer_id,
    c.name,
    c.email,
    o.order_count
FROM
    customers c
LEFT JOIN orders_by_user o ON
    o.customer_id = c.customer_id
WHERE
    o.order_count IS NULL;

-- Country with the highest number of active customers
WITH orders_by_user AS
(
SELECT
    customer_id,
    count(order_id) AS order_count
FROM
    orders
GROUP BY
    customer_id)
SELECT
    c.country,
    count(c.customer_id) AS customer_number
FROM
    customers c
INNER JOIN orders_by_user o ON
    o.customer_id = c.customer_id
GROUP BY
    c.country
ORDER BY
    customer_number DESC
LIMIT 1;

-- Products ordered more than 65_000 times but haven't been ordered since 2023-09-10
SELECT
    p.product_id,
    p.product_name,
    sum(o.quantity_ordered) AS order_amount
FROM
    products p
LEFT JOIN orderdetails o ON
    o.product_id = p.product_id
WHERE
    NOT EXISTS (
    SELECT
        1
    FROM
        orders
    WHERE
        order_date > '2023-09-10'::date
        AND orders.order_id = o.order_id
)
GROUP BY
    p.product_id
HAVING
    sum(o.quantity_ordered) >= 6500
ORDER BY
    order_amount DESC;

-- For each product, find the customer that ordered it the most
WITH product_x_customer AS (
SELECT
    od.product_id,
    sum(od.quantity_ordered) AS purchase_qty,
    o.customer_id,
    ROW_NUMBER() OVER (PARTITION BY od.product_id
ORDER BY
    sum(od.quantity_ordered) DESC) AS pos
FROM
    orderdetails od
JOIN orders o
ON
    o.order_id = od.order_id
GROUP BY
    od.product_id,
    o.customer_id)
SELECT
    p.product_name,
    c.name,
    c.email
FROM
    products p
JOIN product_x_customer pxc
ON
    pxc.product_id = p.product_id
JOIN customers c
ON
    c.customer_id = pxc.customer_id
WHERE
    pxc.pos = 1;

-- Find the month with the most product ordered
SELECT
    date_trunc('month', o.order_date)::date AS YYYY_MM,
    sum(od.quantity_ordered * p.price) AS sales
FROM
    orders o
JOIN orderdetails od
ON
    o.order_id = od.order_id
JOIN products p
ON
    p.product_id = od.product_id
GROUP BY
    date_trunc('month', o.order_date)::date
ORDER BY
    sales DESC
LIMIT 1;

-- Tag with the highest amount of purchases
SELECT
    t.tag_id,
    t.tag_name,
    sum(od.quantity_ordered) AS sales
FROM
    tags t
JOIN customertags ct
ON
    t.tag_id = ct.tag_id
JOIN orders o
ON
    o.customer_id = ct.customer_id
JOIN orderdetails od
ON
    o.order_id = od.order_id
GROUP BY
    t.tag_id,
    t.tag_name
ORDER BY
    sales DESC
LIMIT 1;

-- Products purchased by both 'Ashley' and 'Karen'
SELECT
    DISTINCT p.product_id,
    p.product_name
FROM
    products p
JOIN orderdetails od
ON
    od.product_id = p.product_id
JOIN orders o
ON
    o.order_id = od.order_id
WHERE
    EXISTS (
    SELECT
        1
    FROM
        customertags ct
    JOIN tags t ON
        t.tag_id = ct.tag_id
    WHERE
        ct.customer_id = o.customer_id
        AND t.tag_name = 'Ashley')
    AND EXISTS (
    SELECT
        1
    FROM
        customertags ct
    JOIN tags t ON
        t.tag_id = ct.tag_id
    WHERE
        ct.customer_id = o.customer_id
        AND t.tag_name = 'Karen')
ORDER BY
    p.product_id;

-- Products purchased at least once by a customer with the 'Ashley' tag
-- Optimization notes:
-- This single index is able to reduce the execution time reported by EXPLAIN
-- ANALYZE down to 220 ms from the original 710 ms. However, it might have a
-- negative impact when inserting new rows, specially since this is the largest
-- table and has multiple rows inserted into it with each order
DROP INDEX IF EXISTS orderdetails_order_index;
CREATE INDEX orderdetails_order_index ON orderdetails(order_id);
SELECT
    DISTINCT p.product_id,
    p.product_name
FROM
    tags t
JOIN customertags ct
ON
    t.tag_id = ct.tag_id
-- -- These two indexes shave around 50 ms from the query according to EXPLAIN
-- -- ANALYZE, proably not worth the extra cost when inserting new rows, which is
-- -- why they are commented out
-- DROP INDEX IF EXISTS orders_foreign_key;
-- CREATE INDEX orders_foreign_key ON orders(customer_id);
-- DROP INDEX IF EXISTS orderdetails_foreign_key;
-- CREATE INDEX orderdetails_foreign_key ON orderdetails(product_id);
JOIN orders o
ON
    o.customer_id = ct.customer_id
JOIN orderdetails od
ON
    o.order_id = od.order_id
JOIN products p
ON
    od.product_id = p.product_id
-- There is no index added to the tag_name. We are checking for equality and not
-- doing full-text search so a GIN would be unnecessary overhead, and the table
-- is small enough that sequential search might be faster than indexing.
WHERE
    t.tag_name = 'Ashley'
ORDER BY
    p.product_id;
