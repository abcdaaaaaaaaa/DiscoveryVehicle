<?php
$servername = "localhost";
$dbname = "uzayinfo_CO2";
$username = "uzayinfo_CO2user";
$password = "8579Pi,8674Sh~";

// ALTER DATABASE uzayinfo_CO2
// CHARACTER SET utf8mb4 
// COLLATE utf8mb4_turkish_ci;

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }
    
    $conn->set_charset("utf8mb4");

?>