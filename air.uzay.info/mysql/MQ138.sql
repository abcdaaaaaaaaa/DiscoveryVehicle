CREATE TABLE MQ138 (
    id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    DHT VARCHAR(15),
    SpaceData100 VARCHAR(7),
    Air VARCHAR(5),
    n_Hexane VARCHAR(5),
    propane VARCHAR(5),
    Benzene VARCHAR(5),
    alcohol VARCHAR(5),
    CH4 VARCHAR(5),
    smoke VARCHAR(5),
    CO VARCHAR(5),
    SpaceData200 VARCHAR(7),
    lat VARCHAR(12),
    lng VARCHAR(12),
    reading_time TIMESTAMP DEFAULT UTC_TIMESTAMP
);
