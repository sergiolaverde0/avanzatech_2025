DROP TABLE IF EXISTS cda;
DROP TABLE IF EXISTS master_plan CASCADE;
DROP TABLE IF EXISTS teams;
DROP TABLE IF EXISTS spass_types;
DROP TABLE IF EXISTS targets;
DROP TABLE IF EXISTS requests;
DROP TABLE IF EXISTS event_types;
DROP TABLE IF EXISTS import.master_plan_import;
DROP TABLE IF EXISTS import.cda_import;
CREATE SCHEMA IF NOT EXISTS import;
CREATE TABLE import.cda_import(
    event_id TEXT,
    impact_event_time TEXT,
    impact_event_julian_date TEXT,
    qp_amplitude TEXT,
    qi_amplitude TEXT,
    qt_amplitude TEXT,
    qc_amplitude TEXT,
    spacecraft_sun_distance TEXT,
    spacecraft_saturn_distance TEXT,
    spacecraft_x_velocity TEXT,
    spacecraft_y_velocity TEXT,
    spacecraft_z_velocity TEXT,
    counter_number TEXT,
    particle_mass TEXT,
    particle_charge TEXT
);
CREATE TABLE import.master_plan_import(
    start_time_utc TEXT,
    duration TEXT,
    date TEXT,
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
    time_stamp timestamp NOT NULL,
    title TEXT,
    description TEXT,
    team_id INT REFERENCES teams(team_id),
    spass_id INT REFERENCES spass_types(spass_id),
    target_id INT REFERENCES targets(target_id),
    request_id INT REFERENCES requests(request_id),
    event_id INT REFERENCES event_types(event_id)
);
CREATE TABLE cda(
    event_id serial PRIMARY KEY,
    impact_event_time timestamp,
    qp_amplitude numeric,
    qi_amplitude numeric,
    qt_amplitude numeric,
    qc_amplitude numeric,
    spacecraft_sun_distance numeric,
    spacecraft_saturn_distance numeric,
    spacecraft_x_velocity numeric,
    spacecraft_y_velocity numeric,
    spacecraft_z_velocity numeric,
    counter_number numeric,
    particle_mass numeric,
    particle_charge numeric
);
