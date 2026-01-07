<script src="https://code.jquery.com/jquery-3.7.0.min.js"></script>
<script src="datalidar6.js"></script>
<script src="datalidar7.js"></script>    
<script src="datalidar8.js"></script>    

  <?php
        include_once 'db.php';
        
function setFunction($num, $start, $end){return(int)substr($num, $start-1, $end-$start+1);}
function setNumber1($num, $start, $end){return setFunction($num, $start, $end)-10000;}
function setNumber2($num, $start, $end){return setFunction($num, $start, $end)-1000;}
function setNumber3($num, $start, $end){return setFunction($num, $start, $end)-20;}

for ($i = 0; $i <= 330; $i += 15) {
    $cookieIndex = $i / 15 + 25;
    $fluxVar = 'Flux' . $i;
    $$fluxVar = setNumber1($_COOKIE["data$cookieIndex"], 1, 5);
}

$Flux345 = setNumber1($_COOKIE["data47"], 6, 10);
$temp    = setNumber3($_COOKIE["data48"], 9, 10);

for ($i = 0; $i <= 315; $i += 15) {
    $cookieIndex = $i / 15 + 25;
    $distVar = 'Dist' . $i;
    $$distVar = setNumber2($_COOKIE["data$cookieIndex"], 6, 9);
}

$Dist330 = setNumber2($_COOKIE["data48"], 1, 4);
$Dist345 = setNumber2($_COOKIE["data48"], 5, 8);


function customMap($value, $fromLow, $fromHigh, $toLow, $toHigh) {
    return ($value - $fromLow) * ($toHigh - $toLow) / ($fromHigh - $fromLow) + $toLow;
}

$originalMin = -10;
$originalMax =  60;

$originalMin2 = 0;
$originalMax2 = 65535;

$newMin = 0;
$newMax = 255;

$Rtemp = customMap($temp, $originalMin, $originalMax, $newMin, $newMax);
$Btemp = customMap($temp, $originalMin, $originalMax, $newMax, $newMin);

$rgbValues = [];

for ($i = 0; $i < 360; $i += 15) {
    $fluxVar = 'Flux' . $i;
    $greenVar = 'Green' . $i;
    $rgbVar = 'rgb' . $i;

    $$greenVar = customMap($$fluxVar, $originalMin2, $originalMax2, $newMax, $newMin);

    $$rgbVar = "rgb(" . round($Rtemp) . ", " . round($$greenVar) . ", " . round($Btemp) . ")";
    
    $rgbValues[$rgbVar] = $$rgbVar;
}

$Distances = [
    $Dist0, $Dist15, $Dist30, $Dist45, $Dist60, $Dist75, $Dist90, $Dist105,
    $Dist120, $Dist135, $Dist150, $Dist165, $Dist180, $Dist195, $Dist210, 
    $Dist225, $Dist240, $Dist255, $Dist270, $Dist285, $Dist300, $Dist315, 
    $Dist330, $Dist345
];

$sum = array_sum($Distances);
$Average = round($sum / 12);

$maxDist = round(max($Distances));
if ($Average < $maxDist) $Average = $maxDist;

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $sql1 = "INSERT INTO LidarDistance_Y (Average, Dist0, Dist15, Dist30, Dist45, Dist60, Dist75, Dist90, Dist105, Dist120, Dist135, Dist150, Dist165, Dist180, Dist195, Dist210, Dist225, Dist240, Dist255, Dist270, Dist285, Dist300, Dist315, Dist330, Dist345)
    VALUES ('$Average', '$Dist0', '$Dist15', '$Dist30', '$Dist45', '$Dist60', '$Dist75', '$Dist90', '$Dist105', '$Dist120', '$Dist135', '$Dist150', '$Dist165', '$Dist180', '$Dist195', '$Dist210', '$Dist225', '$Dist240', '$Dist255', '$Dist270', '$Dist285', '$Dist300', '$Dist315', '$Dist330', '$Dist345')";
    
    $sql2 = "INSERT INTO LidarFlux_Y (Temperature, Flux0, Flux15, Flux30, Flux45, Flux60, Flux75, Flux90, Flux105, Flux120, Flux135, Flux150, Flux165, Flux180, Flux195, Flux210, Flux225, Flux240, Flux255, Flux270, Flux285, Flux300, Flux315, Flux330, Flux345)
    VALUES ('$temp', '$Flux0', '$Flux15', '$Flux30', '$Flux45', '$Flux60', '$Flux75', '$Flux90', '$Flux105', '$Flux120', '$Flux135', '$Flux150', '$Flux165', '$Flux180', '$Flux195', '$Flux210', '$Flux225', '$Flux240', '$Flux255', '$Flux270', '$Flux285', '$Flux300', '$Flux315', '$Flux330', '$Flux345')";
    
    $sql3 = "INSERT INTO LidarRGB_Y (Temperature, rgb0, rgb15, rgb30, rgb45, rgb60, rgb75, rgb90, rgb105, rgb120, rgb135, rgb150, rgb165, rgb180, rgb195, rgb210, rgb225, rgb240, rgb255, rgb270, rgb285, rgb300, rgb315, rgb330, rgb345)
    VALUES ('$temp', '$rgb0', '$rgb15', '$rgb30', '$rgb45', '$rgb60', '$rgb75', '$rgb90', '$rgb105', '$rgb120', '$rgb135', '$rgb150', '$rgb165', '$rgb180', '$rgb195', '$rgb210', '$rgb225', '$rgb240', '$rgb255', '$rgb270', '$rgb285', '$rgb300', '$rgb315', '$rgb330', '$rgb345')";

    if ($conn->query($sql1) === TRUE && $conn->query($sql2) === TRUE && $conn->query($sql3) === TRUE) {} 
    else {
        echo "Error: " . $sql1 . "<br>" . $conn->error;
        echo "Error: " . $sql2 . "<br>" . $conn->error;
        echo "Error: " . $sql3 . "<br>" . $conn->error;
    }
}

$conn->close();
?>   