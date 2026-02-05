DROP FUNCTION IF EXISTS pythag(
    NUMERIC,
    NUMERIC,
    NUMERIC
);
CREATE FUNCTION pythag(
    x NUMERIC,
    y NUMERIC,
    z NUMERIC,
    OUT NUMERIC
) AS $$SELECT
    SQRT((x * x) + (y * y) + (z * z)) ::NUMERIC(
        16,
        6
    );
$$LANGUAGE SQL;
DROP INDEX IF EXISTS idx_event_desc;
DROP INDEX IF EXISTS idx_event_title;
DROP MATERIALIZED VIEW IF EXISTS enceladus_events;
CREATE MATERIALIZED VIEW enceladus_events AS SELECT
    (master_plan.time_stamp AT TIME ZONE 'UTC'),
    (master_plan.time_stamp AT TIME ZONE 'UTC') ::DATE AS DATE,
    event_types.description AS event,
    master_plan.title,
    master_plan.description,
    to_tsvector(master_plan.description) AS search_dc,
    to_tsvector(title) AS search_tl
FROM
    master_plan
INNER JOIN event_types
    ON event_types.event_id = master_plan.event_id
WHERE
    target_id = 28
ORDER BY
    time_stamp;
CREATE INDEX idx_event_desc
ON enceladus_events USING GIN(search_dc);
CREATE INDEX idx_event_title
ON enceladus_events USING GIN(search_tl);
