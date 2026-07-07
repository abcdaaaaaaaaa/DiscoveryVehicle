<?php
include_once 'db.php';

$apiKey = 'PWIFQRC3WHDW6YG5';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (!isset($_POST['api_key']) || $_POST['api_key'] !== $apiKey) {
        http_response_code(403);
        echo "Invalid API key.";
        exit;
    }
    
    $timeCheckSql = "SELECT reading_time FROM CO2 ORDER BY id DESC LIMIT 1";
    $timeCheckResult = $conn->query($timeCheckSql);
    if ($timeCheckResult && $row = $timeCheckResult->fetch_assoc()) {
        $last_time = strtotime($row['reading_time'] . ' UTC');
        if (time() - $last_time < 5) {
            http_response_code(429);
            echo "Rate limit exceeded. Please wait 5 seconds.";
            exit;
        }
    }

    $lastRowSql = "SELECT * FROM CO2 ORDER BY id DESC LIMIT 1";
    $lastRowResult = $conn->query($lastRowSql);
    $lastRow = $lastRowResult->fetch_assoc();

    $DHT = $lastRow['DHT'] ?? '-140°C %-100';
    $SpaceData = $lastRow['SpaceData'] ?? '%0';
    $TheoCO2 = $lastRow['TheoCO2'] ?? '0';
    $PCoef = $lastRow['PCoef'] ?? '0';
    $CO2 = $lastRow['CO2'] ?? '0';
    $CH4 = $lastRow['CH4'] ?? '0';
    $C2H5OH = $lastRow['C2H5OH'] ?? '0';
    $CO = $lastRow['CO'] ?? '0';
    $lat = $lastRow['lat'] ?? '0';
    $lng = $lastRow['lng'] ?? '0';

    $field1 = isset($_POST['field1']) ? $_POST['field1'] : null;
    $field2 = isset($_POST['field2']) ? $_POST['field2'] : null;
    $field3 = isset($_POST['field3']) ? $_POST['field3'] : null;
    $field4 = isset($_POST['field4']) ? $_POST['field4'] : null;
    $field5 = isset($_POST['field5']) ? $_POST['field5'] : null;
    $field6 = isset($_POST['field6']) ? $_POST['field6'] : null;
    $field7 = isset($_POST['field7']) ? $_POST['field7'] : null;
    $field8 = isset($_POST['field8']) ? $_POST['field8'] : null;
    $field9 = isset($_POST['field9']) ? $_POST['field9'] : null;
    $field10 = isset($_POST['field10']) ? $_POST['field10'] : null;
    $field11 = isset($_POST['field11']) ? $_POST['field11'] : null;
    $field12 = isset($_POST['field12']) ? $_POST['field12'] : null;

    if ($field1 !== null && $field2 !== null) {
        $timeVal = $field1 / 100;
        $corrVal = $field2 / 10000;
        $PCoef = '×' . $corrVal . ' / ' . $timeVal . 's';
    }
    if ($field3 !== null) $TheoCO2 = $field3 / 100;
    if ($field4 !== null) $CO2 = $field4 / 100;
    if ($field5 !== null) $CH4 = $field5 / 100;
    if ($field6 !== null) $C2H5OH = $field6 / 100;
    if ($field7 !== null) $CO = $field7 / 100;
    if ($field8 !== null) $SpaceData = '%' . $field8 / 4095 * 100;

    if ($field9 !== null && $field10 !== null) {
        $dhtTemp = ($field9 / 10) - 140;
        $dhtRh = ($field10 / 10) - 100;
        $DHT = $dhtTemp . '°C %' . $dhtRh;
    }

    if ($field11 !== null) $lat = ($field11 / 10000000.0) - 90.0;
    if ($field12 !== null) $lng = ($field12 / 10000000.0) - 180.0;

    $stmt = $conn->prepare("INSERT INTO CO2 (DHT, SpaceData, TheoCO2, PCoef, CO2, CH4, C2H5OH, CO, lat, lng) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    $stmt->bind_param("ssssssssss", $DHT, $SpaceData, $TheoCO2, $PCoef, $CO2, $CH4, $C2H5OH, $CO, $lat, $lng);
    
    if ($stmt->execute()) {
        echo "Data successfully saved to SQL.";
    } else {
        http_response_code(500);
        echo "Database error: " . $stmt->error;
    }
    $stmt->close();
    
} elseif ($_SERVER["REQUEST_METHOD"] == "GET") {
    $apiKey = isset($_GET['api_key']) ? $_GET['api_key'] : '';
    $results = isset($_GET['results']) ? (int)$_GET['results'] : 1;

    if ($apiKey !== 'PWIFQRC3WHDW6YG5') {
        http_response_code(403);
        echo "Invalid API key.";
        exit;
    }

    $sql = "SELECT * FROM CO2 ORDER BY id DESC LIMIT ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("i", $results);
    $stmt->execute();
    $result = $stmt->get_result();

    $feeds = [];
    while ($row = $result->fetch_assoc()) {
        $feeds[] = $row;
    }

    header('Content-Type: application/json');
    echo json_encode(["feeds" => array_reverse($feeds)]);
    $stmt->close();
}