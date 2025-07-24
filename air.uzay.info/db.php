<?php
$servername = "localhost";
$dbname = "uzayinfo_air";
$username = "uzayinfo_airuser";
$password = "air2500";

// ALTER DATABASE uzayinfo_air
// CHARACTER SET utf8mb4 
// COLLATE utf8mb4_turkish_ci;

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }
    
    $conn->set_charset("utf8mb4");

?>