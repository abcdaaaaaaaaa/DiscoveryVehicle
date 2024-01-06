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

function customMap($value, $fromLow, $fromHigh, $toLow, $toHigh) {
    return ($value - $fromLow) * ($toHigh - $toLow) / ($fromHigh - $fromLow) + $toLow;
}

$originalMin = -10;
$originalMax = 60;

$originalMin2 = 0;
$originalMax2 = 65535;

$newMin = 0;
$newMax = 255;

$Rtemp0 = customMap($temp0, $originalMin, $originalMax, $newMin, $newMax);
$Btemp0 = customMap($temp0, $originalMin, $originalMax, $newMax, $newMin);

$Rtemp30 = customMap($temp30, $originalMin, $originalMax, $newMin, $newMax);
$Btemp30 = customMap($temp30, $originalMin, $originalMax, $newMax, $newMin);

$Rtemp60 = customMap($temp60, $originalMin, $originalMax, $newMin, $newMax);
$Btemp60 = customMap($temp60, $originalMin, $originalMax, $newMax, $newMin);

$Rtemp90 = customMap($temp90, $originalMin, $originalMax, $newMin, $newMax);
$Btemp90 = customMap($temp90, $originalMin, $originalMax, $newMax, $newMin);

$Rtemp120 = customMap($temp120, $originalMin, $originalMax, $newMin, $newMax);
$Btemp120 = customMap($temp120, $originalMin, $originalMax, $newMax, $newMin);

$Rtemp150 = customMap($temp150, $originalMin, $originalMax, $newMin, $newMax);
$Btemp150 = customMap($temp150, $originalMin, $originalMax, $newMax, $newMin);

$Rtemp180 = customMap($temp180, $originalMin, $originalMax, $newMin, $newMax);
$Btemp180 = customMap($temp180, $originalMin, $originalMax, $newMax, $newMin);

$Green0   = customMap($Flux0, $originalMin2, $originalMax2, $newMax, $newMin);
$Green30  = customMap($Flux30, $originalMin2, $originalMax2, $newMax, $newMin);
$Green60  = customMap($Flux60, $originalMin2, $originalMax2, $newMax, $newMin);
$Green90  = customMap($Flux90, $originalMin2, $originalMax2, $newMax, $newMin);
$Green120 = customMap($Flux120, $originalMin2, $originalMax2, $newMax, $newMin);
$Green150 = customMap($Flux150, $originalMin2, $originalMax2, $newMax, $newMin);
$Green180 = customMap($Flux180, $originalMin2, $originalMax2, $newMax, $newMin);

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
