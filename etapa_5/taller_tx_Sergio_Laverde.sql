-- This solution is non-conventional and uses implicit transactions, which are a
-- feature of SQL. Explicitly, PostgreSQL says:
-- > PostgreSQL actually treats every SQL statement as being executed within a
-- > transaction. If you do not issue a BEGIN command, then each individual
-- > statement has an implicit BEGIN and (if successful) COMMIT wrapped around
-- > it.
-- https://www.postgresql.org/docs/18/tutorial-transactions.html

-- We create a constraint to ensure balance cannot be negative
ALTER TABLE account ADD CONSTRAINT check_positive_balance CHECK (balance >= 0);
-- We then create a function to handle the transfer
CREATE OR REPLACE
FUNCTION transfer_deposit(sender TEXT, recipient TEXT, amount INTEGER)
RETURNS void
AS $$
DECLARE
-- Add variables to store recipient and sender
sender_id INT;
recipient_id INT;

BEGIN
-- Fail early if amount is non-positive
IF amount <= 0 THEN RAISE EXCEPTION 'Amount must be positive';
END IF;

-- Assign variable for sender
SELECT
    a.id
INTO
    STRICT
    sender_id
FROM
    account a
JOIN "users" u
ON
    a.user_id = u.id
WHERE
    u.email = sender
FOR
UPDATE;

    -- Fail if sender does not exist
    IF sender_id IS NULL THEN RAISE EXCEPTION 'Sender not found';
END IF;

-- Assign variable for recipient
SELECT
    a.id
INTO
    STRICT
    recipient_id
FROM
    account a
JOIN "users" u
ON
    a.user_id = u.id
WHERE
    u.email = recipient
FOR
UPDATE;

    -- Fail if recipient does not exist
    IF recipient_id IS NULL THEN RAISE EXCEPTION 'Recipient not found';
END IF;

-- Do the transfer
-- These two statements shouldn't fail
UPDATE
    account a
SET
    balance = balance - amount
WHERE
    a.user_id = sender_id;

UPDATE
    account a
SET
    balance = balance + amount
WHERE
    a.user_id = recipient_id;
RAISE NOTICE 'Transference was successful';
END;

$$ LANGUAGE plpgsql;

-- Since this function call constitutes a single statement, it is wrapped in an
-- implicit transaction. In case of an error, the implicit transaction will be
-- rolled back. This satisfies the requirements without the need for explicit
-- "COMMIT" or "ROLLBACK" anywhere
SELECT transfer_deposit('bill.johnson@fmail.com', 'craig.williams@hmail.com', 100);
-- See also https://stackoverflow.com/questions/1171749/what-does-a-transaction-around-a-single-statement-do#1171807

-- It fails as it whould when either user does not exist, or when the amount
-- exceeds the balance
SELECT transfer_deposit('aaa', 'craig.williams@hmail.com', 100);

SELECT transfer_deposit('bill.johnson@fmail.com', 'bbbbbb', 100);

SELECT transfer_deposit('bill.johnson@fmail.com', 'craig.williams@hmail.com', 1000);
