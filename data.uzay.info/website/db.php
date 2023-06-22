<?php
$servername = "localhost";
$dbname = "uzayinfo_name";
$username = "uzayinfo_username";
$password = "Hello123?";

        $conn = new mysqli($servername, $username, $password, $dbname);

        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        } 
?>
