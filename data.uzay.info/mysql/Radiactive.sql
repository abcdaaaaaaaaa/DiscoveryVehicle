CREATE TABLE Radioactive (
    id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    Usv_hr VARCHAR(12),
    Avg1 VARCHAR(12),
    sdCPM VARCHAR(12),
    CPMCount VARCHAR(7),
    reading_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
)
