INSERT INTO cda(
    event_id,
    impact_event_time,
    qp_amplitude,
    qi_amplitude,
    qt_amplitude,
    qc_amplitude,
    spacecraft_sun_distance,
    spacecraft_saturn_distance,
    spacecraft_x_velocity,
    spacecraft_y_velocity,
    spacecraft_z_velocity,
    counter_number,
    particle_mass,
    particle_charge
) SELECT
    event_id ::INTEGER,
    impact_event_time ::TIMESTAMP,
    qp_amplitude ::NUMERIC,
    qi_amplitude ::NUMERIC,
    qt_amplitude ::NUMERIC,
    qc_amplitude ::NUMERIC,
    spacecraft_sun_distance ::NUMERIC,
    spacecraft_saturn_distance ::NUMERIC,
    spacecraft_x_velocity ::NUMERIC,
    spacecraft_y_velocity ::NUMERIC,
    spacecraft_z_velocity ::NUMERIC,
    CASE counter_number
        WHEN '**' THEN NULL
        ELSE counter_number ::INTEGER
    END AS counter_number,
    particle_mass ::NUMERIC,
    particle_charge ::NUMERIC
FROM
    import.cda_import;
INSERT INTO teams(description) SELECT
    DISTINCT i.team
FROM
    import.master_plan_import AS i;
INSERT INTO spass_types(description) SELECT
    DISTINCT i.spass_type
FROM
    import.master_plan_import AS i;
INSERT INTO targets(description) SELECT
    DISTINCT i.target
FROM
    import.master_plan_import AS i;
INSERT INTO requests(description) SELECT
    DISTINCT i.request_name
FROM
    import.master_plan_import AS i;
INSERT INTO event_types(description) SELECT
    DISTINCT i.library_definition
FROM
    import.master_plan_import AS i;
INSERT INTO master_plan(
    time_stamp,
    title,
    description,
    team_id,
    spass_id,
    target_id,
    request_id,
    event_id
) SELECT
    CAST(i.start_time_utc AS TIMESTAMP),
    i.title,
    i.description,
    teams.team_id,
    spass_types.spass_id,
    targets.target_id,
    requests.request_id,
    event_types.event_id
FROM
    import.master_plan_import AS i
LEFT JOIN teams
    ON i.team = teams.description
LEFT JOIN spass_types
    ON i.spass_type = spass_types.description
LEFT JOIN targets
    ON i.target = targets.description
LEFT JOIN requests
    ON i.request_name = requests.description
LEFT JOIN event_types
    ON i.library_definition = event_types.description;
DROP TABLE import.master_plan_import;
DROP TABLE import.cda_import;
