DROP TABLE IF EXISTS master_plan;
DROP TABLE IF EXISTS teams;
DROP TABLE IF EXISTS spass_types;
DROP TABLE IF EXISTS targets;
DROP TABLE IF EXISTS requests;
DROP TABLE IF EXISTS event_types;
DROP TABLE IF EXISTS import.master_plan_import;
CREATE SCHEMA IF NOT EXISTS import;
CREATE TABLE import.master_plan_import(
    start_time_utc TEXT,
    duration TEXT,
    DATE TEXT,
    team TEXT,
    spass_type TEXT,
    target TEXT,
    request_name TEXT,
    library_definition TEXT,
    title TEXT,
    description TEXT
);
CREATE TABLE teams(
    team_id serial PRIMARY KEY,
    description TEXT
);
CREATE TABLE spass_types(
    spass_id serial PRIMARY KEY,
    description TEXT
);
CREATE TABLE targets(
    target_id serial PRIMARY KEY,
    description TEXT
);
CREATE TABLE requests(
    request_id serial PRIMARY KEY,
    description TEXT
);
CREATE TABLE event_types(
    event_id serial PRIMARY KEY,
    description TEXT
);
CREATE TABLE master_plan(
    id serial PRIMARY KEY,
    time_stamp timestamptz NOT NULL,
    title TEXT,
    description TEXT,
    team_id INT REFERENCES teams(team_id),
    spass_id INT REFERENCES spass_types(spass_id),
    target_id INT REFERENCES targets(target_id),
    request_id INT REFERENCES requests(request_id),
    event_id INT REFERENCES event_types(event_id)
);
