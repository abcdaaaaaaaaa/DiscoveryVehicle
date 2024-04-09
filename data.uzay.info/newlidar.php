<script src="https://code.jquery.com/jquery-3.7.0.min.js"></script>
<script src="../datalidar3.js"></script>
<script src="../datalidar4.js"></script>    
<script src="../datalidar5.js"></script>    
<script src="../datalidar6.js"></script>    

  <?php
        include_once 'db.php';
        
function setFunction($num, $start, $end){return(int)substr($num, $start-1, $end-$start+1)-1000;}
function setNumber($num, $start, $end){return setFunction($num, $start, $end)-10000;}
function setNumber2($num, $start, $end){return setFunction($num, $start, $end)-1000;}
function setNumber3($num, $start, $end){return setFunction($num, $start, $end)-20;}

$Flux0   = setNumber($_COOKIE["data1"], 1, 5);
$Flux15  = setNumber($_COOKIE["data1"], 6, 10);
$Flux30  = setNumber($_COOKIE["data2"], 1, 5);
$Flux45  = setNumber($_COOKIE["data2"], 6, 10);
$Flux60  = setNumber($_COOKIE["data3"], 1, 5);
$Flux75  = setNumber($_COOKIE["data3"], 6, 10);
$Flux90  = setNumber($_COOKIE["data4"], 1, 5);
$Flux105 = setNumber($_COOKIE["data4"], 6, 10);
$Flux120 = setNumber($_COOKIE["data5"], 1, 5);
$Flux135 = setNumber($_COOKIE["data5"], 6, 10);
$Flux150 = setNumber($_COOKIE["data6"], 1, 5);
$Flux165 = setNumber($_COOKIE["data6"], 6, 10);
$Flux180 = setNumber($_COOKIE["data7"], 1, 5);
$Flux195 = setNumber($_COOKIE["data7"], 6, 10);
$Flux210 = setNumber($_COOKIE["data8"], 1, 5);
$Flux225 = setNumber($_COOKIE["data8"], 6, 10);
$Flux240 = setNumber($_COOKIE["data9"], 1, 5);
$Flux255 = setNumber($_COOKIE["data9"], 6, 10);
$Flux270 = setNumber($_COOKIE["data10"], 1, 5);
$Flux285 = setNumber($_COOKIE["data10"], 6, 10);
$Flux300 = setNumber($_COOKIE["data11"], 1, 5);
$Flux315 = setNumber($_COOKIE["data11"], 6, 10);
$Flux330 = setNumber($_COOKIE["data12"], 1, 5);
$Flux345 = setNumber($_COOKIE["data12"], 6, 10);
$Average = setFunction($_COOKIE["data13"], 1, 4);
$temp0   = setNumber3($_COOKIE["data13"], 5, 6);
$temp15  = setNumber3($_COOKIE["data13"], 7, 8);
$temp30  = setNumber3($_COOKIE["data13"], 9, 10);
$temp45  = setNumber3($_COOKIE["data14"], 1, 2);
$Dist0   = setNumber2($_COOKIE["data14"], 3, 6);
$Dist15  = setNumber2($_COOKIE["data14"], 7, 10);
$temp60  = setNumber3($_COOKIE["data15"], 1, 2);
$Dist30  = setNumber2($_COOKIE["data15"], 3, 6);
$Dist45  = setNumber2($_COOKIE["data15"], 7, 10);
$temp75  = setNumber3($_COOKIE["data16"], 1, 2);
$Dist60  = setNumber2($_COOKIE["data16"], 3, 6);
$Dist75  = setNumber2($_COOKIE["data16"], 7, 10);
$temp90  = setNumber3($_COOKIE["data17"], 1, 2);
$Dist90  = setNumber2($_COOKIE["data17"], 3, 6);
$Dist105 = setNumber2($_COOKIE["data17"], 7, 10);
$temp105  = setNumber3($_COOKIE["data18"], 1, 2);
$Dist120 = setNumber2($_COOKIE["data18"], 3, 6);
$Dist135 = setNumber2($_COOKIE["data18"], 7, 10);
$temp120  = setNumber3($_COOKIE["data19"], 1, 2);
$Dist150 = setNumber2($_COOKIE["data19"], 3, 6);
$Dist165 = setNumber2($_COOKIE["data19"], 7, 10);
$temp135 = setNumber3($_COOKIE["data20"], 1, 2);
$Dist180 = setNumber2($_COOKIE["data20"], 3, 6);
$Dist195 = setNumber2($_COOKIE["data20"], 7, 10);
$temp150 = setNumber3($_COOKIE["data21"], 1, 2);
$Dist210 = setNumber2($_COOKIE["data21"], 3, 6);
$Dist225 = setNumber2($_COOKIE["data21"], 7, 10);
$temp165 = setNumber3($_COOKIE["data22"], 1, 2);
$Dist240 = setNumber2($_COOKIE["data22"], 3, 6);
$Dist255 = setNumber2($_COOKIE["data22"], 7, 10);
$temp180 = setNumber3($_COOKIE["data23"], 1, 2);
$Dist270 = setNumber2($_COOKIE["data23"], 3, 6);
$Dist285 = setNumber2($_COOKIE["data23"], 7, 10);
$temp195 = setNumber3($_COOKIE["data24"], 1, 2);
$Dist300 = setNumber2($_COOKIE["data24"], 3, 6);
$Dist315 = setNumber2($_COOKIE["data24"], 7, 10);
$temp210 = setNumber3($_COOKIE["data25"], 1, 2);
$Dist330 = setNumber2($_COOKIE["data25"], 3, 6);
$Dist345 = setNumber2($_COOKIE["data25"], 7, 10);
$temp225 = setNumber3($_COOKIE["data26"], 1, 2);
$temp240 = setNumber3($_COOKIE["data26"], 3, 4);
$temp255 = setNumber3($_COOKIE["data26"], 5, 6);
$temp270 = setNumber3($_COOKIE["data26"], 7, 8);
$temp285 = setNumber3($_COOKIE["data26"], 9, 10);
$temp300 = setNumber3($_COOKIE["data27"], 1, 2);
$temp315 = setNumber3($_COOKIE["data27"], 3, 4);
$temp330 = setNumber3($_COOKIE["data27"], 5, 6);
$temp345 = setNumber3($_COOKIE["data27"], 7, 8);

function customMap($value, $fromLow, $fromHigh, $toLow, $toHigh) {
    return ($value - $fromLow) * ($toHigh - $toLow) / ($fromHigh - $fromLow) + $toLow;
}

$originalMin = -10;
$originalMax =  60;

$originalMin2 = 0;
$originalMax2 = 65535;

$newMin = 0;
$newMax = 255;

$Rtemp0    = customMap($temp0, $originalMin, $originalMax, $newMin, $newMax);
$Btemp0    = customMap($temp0, $originalMin, $originalMax, $newMax, $newMin);
$Green0    = customMap($Flux0, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb0      = "rgb(" . round($Rtemp0) . ", " . round($Green0) . ", " . round($Btemp0) . ")";

$Rtemp15   = customMap($temp15, $originalMin, $originalMax, $newMin, $newMax);
$Btemp15   = customMap($temp15, $originalMin, $originalMax, $newMax, $newMin);
$Green15   = customMap($Flux15, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb15     = "rgb(" . round($Rtemp15) . ", " . round($Green15) . ", " . round($Btemp15) . ")";

$Rtemp30   = customMap($temp30, $originalMin, $originalMax, $newMin, $newMax);
$Btemp30   = customMap($temp30, $originalMin, $originalMax, $newMax, $newMin);
$Green30   = customMap($Flux30, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb30     = "rgb(" . round($Rtemp30) . ", " . round($Green30) . ", " . round($Btemp30) . ")";

$Rtemp45   = customMap($temp45, $originalMin, $originalMax, $newMin, $newMax);
$Btemp45   = customMap($temp45, $originalMin, $originalMax, $newMax, $newMin);
$Green45   = customMap($Flux45, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb45     = "rgb(" . round($Rtemp45) . ", " . round($Green45) . ", " . round($Btemp45) . ")";

$Rtemp60   = customMap($temp60, $originalMin, $originalMax, $newMin, $newMax);
$Btemp60   = customMap($temp60, $originalMin, $originalMax, $newMax, $newMin);
$Green60   = customMap($Flux60, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb60     = "rgb(" . round($Rtemp60) . ", " . round($Green60) . ", " . round($Btemp60) . ")";

$Rtemp75   = customMap($temp75, $originalMin, $originalMax, $newMin, $newMax);
$Btemp75   = customMap($temp75, $originalMin, $originalMax, $newMax, $newMin);
$Green75   = customMap($Flux75, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb75     = "rgb(" . round($Rtemp75) . ", " . round($Green75) . ", " . round($Btemp75) . ")";

$Rtemp90   = customMap($temp90, $originalMin, $originalMax, $newMin, $newMax);
$Btemp90   = customMap($temp90, $originalMin, $originalMax, $newMax, $newMin);
$Green90   = customMap($Flux90, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb90     = "rgb(" . round($Rtemp90) . ", " . round($Green90) . ", " . round($Btemp90) . ")";

$Rtemp105  = customMap($temp105, $originalMin, $originalMax, $newMin, $newMax);
$Btemp105  = customMap($temp105, $originalMin, $originalMax, $newMax, $newMin);
$Green105  = customMap($Flux105, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb105    = "rgb(" . round($Rtemp105) . ", " . round($Green105) . ", " . round($Btemp105) . ")";

$Rtemp120  = customMap($temp120, $originalMin, $originalMax, $newMin, $newMax);
$Btemp120  = customMap($temp120, $originalMin, $originalMax, $newMax, $newMin);
$Green120  = customMap($Flux120, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb120    = "rgb(" . round($Rtemp120) . ", " . round($Green120) . ", " . round($Btemp120) . ")";

$Rtemp135  = customMap($temp135, $originalMin, $originalMax, $newMin, $newMax);
$Btemp135  = customMap($temp135, $originalMin, $originalMax, $newMax, $newMin);
$Green135  = customMap($Flux135, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb135    = "rgb(" . round($Rtemp135) . ", " . round($Green135) . ", " . round($Btemp135) . ")";

$Rtemp150  = customMap($temp150, $originalMin, $originalMax, $newMin, $newMax);
$Btemp150  = customMap($temp150, $originalMin, $originalMax, $newMax, $newMin);
$Green150  = customMap($Flux150, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb150    = "rgb(" . round($Rtemp150) . ", " . round($Green150) . ", " . round($Btemp150) . ")";

$Rtemp165  = customMap($temp165, $originalMin, $originalMax, $newMin, $newMax);
$Btemp165  = customMap($temp165, $originalMin, $originalMax, $newMax, $newMin);
$Green165  = customMap($Flux165, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb165    = "rgb(" . round($Rtemp165) . ", " . round($Green165) . ", " . round($Btemp165) . ")";

$Rtemp180  = customMap($temp180, $originalMin, $originalMax, $newMin, $newMax);
$Btemp180  = customMap($temp180, $originalMin, $originalMax, $newMax, $newMin);
$Green180  = customMap($Flux180, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb180    = "rgb(" . round($Rtemp180) . ", " . round($Green180) . ", " . round($Btemp180) . ")";

$Rtemp195  = customMap($temp195, $originalMin, $originalMax, $newMin, $newMax);
$Btemp195  = customMap($temp195, $originalMin, $originalMax, $newMax, $newMin);
$Green195  = customMap($Flux195, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb195    = "rgb(" . round($Rtemp195) . ", " . round($Green195) . ", " . round($Btemp195) . ")";

$Rtemp210  = customMap($temp210, $originalMin, $originalMax, $newMin, $newMax);
$Btemp210  = customMap($temp210, $originalMin, $originalMax, $newMax, $newMin);
$Green210  = customMap($Flux210, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb210    = "rgb(" . round($Rtemp210) . ", " . round($Green210) . ", " . round($Btemp210) . ")";

$Rtemp225  = customMap($temp225, $originalMin, $originalMax, $newMin, $newMax);
$Btemp225  = customMap($temp225, $originalMin, $originalMax, $newMax, $newMin);
$Green225  = customMap($Flux225, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb225    = "rgb(" . round($Rtemp225) . ", " . round($Green225) . ", " . round($Btemp225) . ")";

$Rtemp240  = customMap($temp240, $originalMin, $originalMax, $newMin, $newMax);
$Btemp240  = customMap($temp240, $originalMin, $originalMax, $newMax, $newMin);
$Green240  = customMap($Flux240, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb240    = "rgb(" . round($Rtemp240) . ", " . round($Green240) . ", " . round($Btemp240) . ")";

$Rtemp255  = customMap($temp255, $originalMin, $originalMax, $newMin, $newMax);
$Btemp255  = customMap($temp255, $originalMin, $originalMax, $newMax, $newMin);
$Green255  = customMap($Flux255, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb255    = "rgb(" . round($Rtemp255) . ", " . round($Green255) . ", " . round($Btemp255) . ")";

$Rtemp270  = customMap($temp270, $originalMin, $originalMax, $newMin, $newMax);
$Btemp270  = customMap($temp270, $originalMin, $originalMax, $newMax, $newMin);
$Green270  = customMap($Flux270, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb270    = "rgb(" . round($Rtemp270) . ", " . round($Green270) . ", " . round($Btemp270) . ")";

$Rtemp285  = customMap($temp285, $originalMin, $originalMax, $newMin, $newMax);
$Btemp285  = customMap($temp285, $originalMin, $originalMax, $newMax, $newMin);
$Green285  = customMap($Flux285, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb285    = "rgb(" . round($Rtemp285) . ", " . round($Green285) . ", " . round($Btemp285) . ")";

$Rtemp300  = customMap($temp300, $originalMin, $originalMax, $newMin, $newMax);
$Btemp300  = customMap($temp300, $originalMin, $originalMax, $newMax, $newMin);
$Green300  = customMap($Flux300, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb300    = "rgb(" . round($Rtemp300) . ", " . round($Green300) . ", " . round($Btemp300) . ")";

$Rtemp315  = customMap($temp315, $originalMin, $originalMax, $newMin, $newMax);
$Btemp315  = customMap($temp315, $originalMin, $originalMax, $newMax, $newMin);
$Green315  = customMap($Flux315, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb315    = "rgb(" . round($Rtemp315) . ", " . round($Green315) . ", " . round($Btemp315) . ")";

$Rtemp330  = customMap($temp330, $originalMin, $originalMax, $newMin, $newMax);
$Btemp330  = customMap($temp330, $originalMin, $originalMax, $newMax, $newMin);
$Green330  = customMap($Flux330, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb330    = "rgb(" . round($Rtemp330) . ", " . round($Green330) . ", " . round($Btemp330) . ")";

$Rtemp345  = customMap($temp345, $originalMin, $originalMax, $newMin, $newMax);
$Btemp345  = customMap($temp345, $originalMin, $originalMax, $newMax, $newMin);
$Green345  = customMap($Flux345, $originalMin2, $originalMax2, $newMax, $newMin);
$rgb345    = "rgb(" . round($Rtemp345) . ", " . round($Green345) . ", " . round($Btemp345) . ")";

$sql1 = "INSERT INTO LidarDistance (Dist0, Dist15, Dist30, Dist45, Dist60, Dist75, Dist90, Dist105, Dist120, Dist135, Dist150, Dist165, Dist180, Dist195, Dist210, Dist225, Dist240, Dist255, Dist270, Dist285, Dist300, Dist315, Dist330, Dist345, Average)
VALUES ('$Dist0', '$Dist15', '$Dist30', '$Dist45', '$Dist60', '$Dist75', '$Dist90', '$Dist105', '$Dist120', '$Dist135', '$Dist150', '$Dist165', '$Dist180', '$Dist195', '$Dist210', '$Dist225', '$Dist240', '$Dist255', '$Dist270', '$Dist285', '$Dist300', '$Dist315', '$Dist330', '$Dist345', '$Average')";

$sql2 = "INSERT INTO LidarTemperature (Temp0, Temp15, Temp30, Temp45, Temp60, Temp75, Temp90, Temp105, Temp120, Temp135, Temp150, Temp165, Temp180, Temp195, Temp210, Temp225, Temp240, Temp255, Temp270, Temp285, Temp300, Temp315, Temp330, Temp345)
VALUES ('$temp0', '$temp15', '$temp30', '$temp45', '$temp60', '$temp75', '$temp90', '$temp105', '$temp120', '$temp135', '$temp150', '$temp165', '$temp180', '$temp195', '$temp210', '$temp225', '$temp240', '$temp255', '$temp270', '$temp285', '$temp300', '$temp315', '$temp330', '$temp345')";

$sql3 = "INSERT INTO LidarFlux (Flux0, Flux15, Flux30, Flux45, Flux60, Flux75, Flux90, Flux105, Flux120, Flux135, Flux150, Flux165, Flux180, Flux195, Flux210, Flux225, Flux240, Flux255, Flux270, Flux285, Flux300, Flux315, Flux330, Flux345)
VALUES ('$Flux0', '$Flux15', '$Flux30', '$Flux45', '$Flux60', '$Flux75', '$Flux90', '$Flux105', '$Flux120', '$Flux135', '$Flux150', '$Flux165', '$Flux180', '$Flux195', '$Flux210', '$Flux225', '$Flux240', '$Flux255', '$Flux270', '$Flux285', '$Flux300', '$Flux315', '$Flux330', '$Flux345')";

$sql4 = "INSERT INTO LidarRGB (rgb0, rgb15, rgb30, rgb45, rgb60, rgb75, rgb90, rgb105, rgb120, rgb135, rgb150, rgb165, rgb180, rgb195, rgb210, rgb225, rgb240, rgb255, rgb270, rgb285, rgb300, rgb315, rgb330, rgb345)
VALUES ('$rgb0', '$rgb15', '$rgb30', '$rgb45', '$rgb60', '$rgb75', '$rgb90', '$rgb105', '$rgb120', '$rgb135', '$rgb150', '$rgb165', '$rgb180', '$rgb195', '$rgb210', '$rgb225', '$rgb240', '$rgb255', '$rgb270', '$rgb285', '$rgb300', '$rgb315', '$rgb330', '$rgb345')";

if ($conn->query($sql1) === TRUE && $conn->query($sql2) === TRUE && $conn->query($sql3) === TRUE && $conn->query($sql4) === TRUE) {} 
else {
    echo "Error: " . $sql1 . "<br>" . $conn->error;
    echo "Error: " . $sql2 . "<br>" . $conn->error;
    echo "Error: " . $sql3 . "<br>" . $conn->error;
    echo "Error: " . $sql4 . "<br>" . $conn->error;
}

$conn->close();


?>   