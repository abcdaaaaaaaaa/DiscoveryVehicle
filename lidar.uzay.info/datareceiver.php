<?php
include_once 'db.php';

$API_KEY_X = "YSXKFJYHCZGW00DT";
$API_KEY_Y = "DKH2JAX5CLOA7D83";

function customMap($value, $fromLow, $fromHigh, $toLow, $toHigh) {
    $mapped = ($value - $fromLow) * ($toHigh - $toLow) / ($fromHigh - $fromLow) + $toLow;
    return max(min($mapped, max($toLow, $toHigh)), min($toLow, $toHigh));
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (!isset($_POST['api_key'])) {
        http_response_code(400);
        die();
    }

    $apiKey = $_POST['api_key'];
    
    if ($apiKey !== $API_KEY_X && $apiKey !== $API_KEY_Y) {
        http_response_code(403);
        die();
    }

    $axis = ($apiKey === $API_KEY_X) ? 'X' : 'Y';
    $rateLimitFile = "last_post_" . $axis . ".txt";
    
    $now = time();
    if (file_exists($rateLimitFile)) {
        $lastTime = (int)file_get_contents($rateLimitFile);
        if ($now - $lastTime < 5) {
            http_response_code(429);
            die();
        }
    }
    file_put_contents($rateLimitFile, $now);

    $fluxes = [];
    $distances = [];
    
    for ($i = 0; $i < 22; $i++) {
        $fieldValue = $_POST["field" . ($i + 1)];
        $fluxes[$i] = (int)substr($fieldValue, 0, 5) - 10000;
        $distances[$i] = (int)substr($fieldValue, 5, 4) - 1000;
    }
    
    $field23 = $_POST["field23"];
    $fluxes[22] = (int)substr($field23, 0, 5) - 10000;
    $fluxes[23] = (int)substr($field23, 5, 5) - 10000;
    
    $field24 = $_POST["field24"];
    $distances[22] = (int)substr($field24, 0, 4) - 1000;
    $distances[23] = (int)substr($field24, 4, 4) - 1000;
    $temp = (int)substr($field24, 8, 2) - 20;

    $angles = [0, 15, 30, 45, 60, 75, 90, 105, 120, 135, 150, 165, 180, 195, 210, 225, 240, 255, 270, 285, 300, 315, 330, 345];
    
    $distVars = [];
    $fluxVars = [];
    $rgbVars = [];
    
    $Rtemp = customMap($temp, -10, 60, 0, 255);
    $Btemp = customMap($temp, -10, 60, 255, 0);

    foreach ($angles as $index => $angle) {
        $distVars["Dist" . $angle] = $distances[$index];
        $fluxVars["Flux" . $angle] = $fluxes[$index];
        
        $green = customMap($fluxes[$index], 0, 65535, 255, 0);
        $rgbVars["rgb" . $angle] = "rgb(" . round($Rtemp) . ", " . round($green) . ", " . round($Btemp) . ")";
    }

    $sum = array_sum($distances);
    $Average = round($sum / 24);
    $maxDist = round(max($distances));
    if ($Average < $maxDist) $Average = $maxDist;

    $distColumns = implode(", ", array_keys($distVars));
    $distValues = "'" . implode("', '", array_values($distVars)) . "'";
    $sql1 = "INSERT INTO LidarDistance_$axis (Average, $distColumns) VALUES ('$Average', $distValues)";
    
    $fluxColumns = implode(", ", array_keys($fluxVars));
    $fluxValues = "'" . implode("', '", array_values($fluxVars)) . "'";
    $sql2 = "INSERT INTO LidarFlux_$axis (Temperature, $fluxColumns) VALUES ('$temp', $fluxValues)";
    
    $rgbColumns = implode(", ", array_keys($rgbVars));
    $rgbValues = "'" . implode("', '", array_values($rgbVars)) . "'";
    $sql3 = "INSERT INTO LidarRGB_$axis (Temperature, $rgbColumns) VALUES ('$temp', $rgbValues)";

    if ($conn->query($sql1) === TRUE && $conn->query($sql2) === TRUE && $conn->query($sql3) === TRUE) {
        echo "1";
    } else {
        http_response_code(500);
        echo "0";
    }
} 
elseif ($_SERVER["REQUEST_METHOD"] == "GET") {
    $axis = isset($_GET['axis']) && $_GET['axis'] === 'Y' ? 'Y' : 'X';
    
    $sqlDist = "SELECT * FROM LidarDistance_$axis ORDER BY id DESC LIMIT 1";
    $sqlRGB = "SELECT * FROM LidarRGB_$axis ORDER BY id DESC LIMIT 1";
    
    $resultDist = $conn->query($sqlDist);
    $resultRGB = $conn->query($sqlRGB);
    
    if ($resultDist->num_rows > 0 && $resultRGB->num_rows > 0) {
        $rowDist = $resultDist->fetch_assoc();
        $rowRGB = $resultRGB->fetch_assoc();
        
        header('Content-Type: application/json');
        echo json_encode(["success" => true, "dist" => $rowDist, "rgb" => $rowRGB]);
    } else {
        header('Content-Type: application/json');
        echo json_encode(["success" => false]);
    }
}
$conn->close();
?>