<script src="https://code.jquery.com/jquery-3.7.0.min.js"></script>
<script src="../GreenLidar3.js"></script>
<script src="../datalidar4.js"></script>    
<script src="../datalidar5.js"></script>    

  <?php
        include_once 'db.php';
        
        $Dist0 = $_COOKIE["Angle0"];
        $Dist30 = $_COOKIE["Angle30"];
        $Dist60 = $_COOKIE["Angle60"];
        $Dist90 = $_COOKIE["Angle90"];
        $Dist120 = $_COOKIE["Angle120"];
        $Dist150 = $_COOKIE["Angle150"];
        $Dist180 = $_COOKIE["Angle180"];
        $Average = $_COOKIE["Average"];
        $temp0 =  $_COOKIE["temp0"];
        $temp30 = $_COOKIE["temp30"];
        $temp60 = $_COOKIE["temp60"];
        $temp90 = $_COOKIE["temp90"];
        $temp120 = $_COOKIE["temp120"];
        $temp150 = $_COOKIE["temp150"];
        $temp180 = $_COOKIE["temp180"];
        $Flux0 =  $_COOKIE["green0"];
        $Flux30 =  $_COOKIE["green30"];
        $Flux60 =  $_COOKIE["green60"];
        $Flux90 =  $_COOKIE["green90"];
        $Flux120 =  $_COOKIE["green120"];
        $Flux150 =  $_COOKIE["green150"];
        $Flux180 =  $_COOKIE["green180"];

$originalMin = -10;
$originalMax = 60;

$newMin = 0;
$newMax = 255;

$normalizedtemp0 = ($temp0 - $originalMin) / ($originalMax - $originalMin);
$Rtemp0 = $newMin + ($normalizedtemp0 * ($newMax - $newMin));
$Btemp0 = $newMax - ($normalizedtemp0 * ($newMax - $newMin));

$normalizedtemp30 = ($temp30 - $originalMin) / ($originalMax - $originalMin);
$Rtemp30 = $newMin + ($normalizedtemp30 * ($newMax - $newMin));
$Btemp30 = $newMax - ($normalizedtemp30 * ($newMax - $newMin));

$normalizedtemp60 = ($temp60 - $originalMin) / ($originalMax - $originalMin);
$Rtemp60 = $newMin + ($normalizedtemp60 * ($newMax - $newMin));
$Btemp60 = $newMax - ($normalizedtemp60 * ($newMax - $newMin));

$normalizedtemp90 = ($temp90 - $originalMin) / ($originalMax - $originalMin);
$Rtemp90 = $newMin + ($normalizedtemp90 * ($newMax - $newMin));
$Btemp90 = $newMax - ($normalizedtemp90 * ($newMax - $newMin));

$normalizedtemp120 = ($temp120 - $originalMin) / ($originalMax - $originalMin);
$Rtemp120 = $newMin + ($normalizedtemp120 * ($newMax - $newMin));
$Btemp120 = $newMax - ($normalizedtemp120 * ($newMax - $newMin));

$normalizedtemp150 = ($temp150 - $originalMin) / ($originalMax - $originalMin);
$Rtemp150 = $newMin + ($normalizedtemp150 * ($newMax - $newMin));
$Btemp150 = $newMax - ($normalizedtemp150 * ($newMax - $newMin));

$normalizedtemp180 = ($temp180 - $originalMin) / ($originalMax - $originalMin);
$Rtemp180 = $newMin + ($normalizedtemp180 * ($newMax - $newMin));
$Btemp180 = $newMax - ($normalizedtemp180 * ($newMax - $newMin));

$originalMin2 = 0;
$originalMax2 = 65535;

$newMin2 = 0;
$newMax2 = 255;

$normalizedGreen0 = ($Flux0 - $originalMin2) / ($originalMax2 - $originalMin2);
$Green0 = $newMax2 - ($normalizedGreen0 * ($newMax2 - $newMin2));

$normalizedGreen30 = ($Flux30 - $originalMin2) / ($originalMax2 - $originalMin2);
$Green30 = $newMax2 - ($normalizedGreen30 * ($newMax2 - $newMin2));

$normalizedGreen60 = ($Flux60 - $originalMin2) / ($originalMax2 - $originalMin2);
$Green60 = $newMax2 - ($normalizedGreen60 * ($newMax2 - $newMin2));

$normalizedGreen90 = ($Flux90 - $originalMin2) / ($originalMax2 - $originalMin2);
$Green90 = $newMax2 - ($normalizedGreen90 * ($newMax2 - $newMin2));

$normalizedGreen120 = ($Flux120 - $originalMin2) / ($originalMax2 - $originalMin2);
$Green120 = $newMax2 - ($normalizedGreen120 * ($newMax2 - $newMin2));

$normalizedGreen150 = ($Flux150 - $originalMin2) / ($originalMax2 - $originalMin2);
$Green150 = $newMax2 - ($normalizedGreen150 * ($newMax2 - $newMin2));

$normalizedGreen180 = ($Flux180 - $originalMin2) / ($originalMax2 - $originalMin2);
$Green180 = $newMax2 - ($normalizedGreen180 * ($newMax2 - $newMin2));

$rgb0 = "rgb(" . round($Rtemp0) . ", " . round($Green0) . ", " . round($Btemp0) . ")";
$rgb30 = "rgb(" . round($Rtemp30) . ", " . round($Green30) . ", " . round($Btemp30) . ")";
$rgb60 = "rgb(" . round($Rtemp60) . ", " . round($Green60) . ", " . round($Btemp60) . ")";
$rgb90 = "rgb(" . round($Rtemp90) . ", " . round($Green90) . ", " . round($Btemp90) . ")";
$rgb120 = "rgb(" . round($Rtemp120) . ", " . round($Green120) . ", " . round($Btemp120) . ")";
$rgb150 = "rgb(" . round($Rtemp150) . ", " . round($Green150) . ", " . round($Btemp150) . ")";
$rgb180 = "rgb(" . round($Rtemp180) . ", " . round($Green180) . ", " . round($Btemp180) . ")";


$sql = "INSERT INTO Lidar (Dist0, Dist30, Dist60, Dist90, Dist120, Dist150, Dist180, Average, Temp0, Temp30, Temp60, Temp90, Temp120, Temp150, Temp180, Flux0, Flux30, Flux60, Flux90, Flux120, Flux150, Flux180, rgb0, rgb30, rgb60, rgb90, rgb120, rgb150, rgb180)
        VALUES ('" . $Dist0 . "', '" . $Dist30 . "', '" . $Dist60 . "', '" . $Dist90 . "', '" . $Dist120 . "', '" . $Dist150 . "', '" . $Dist180 . "', '" . $Average . "', '" . $temp0 . "', '" . $temp30 . "', '" . $temp60 . "', '" . $temp90 . "', '" . $temp120 . "', '" . $temp150 . "', '" . $temp180 . "', '" . $Flux0 . "', '" . $Flux30 . "', '" . $Flux60 . "', '" . $Flux90 . "', '" . $Flux120 . "', '" . $Flux150 . "', '" . $Flux180 . "', '" . $rgb0 . "', '" . $rgb30 . "', '" . $rgb60 . "', '" . $rgb90 . "', '" . $rgb120 . "', '" . $rgb150 . "', '" . $rgb180 . "')";

 
        if ($conn->query($sql) === TRUE) {
        } 
        else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
    
        $conn->close();

?>   
