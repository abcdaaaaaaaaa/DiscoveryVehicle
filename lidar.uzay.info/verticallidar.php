<?php
include_once 'yaxsis.php';
# verticallidar.php
?>

<!doctype html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="shortcut icon" href="lidar.ico">
    <title id="pageTitle">3D Lidar</title>
    <link rel="stylesheet" href="verticallidar.css">
</head>
<body>
    <div class="container1">
		<div class="forward-long-rectangle105"></div>
		<div class="right-long-rectangle15"></div>
		<div class="forward-long-rectangle135"></div>
        <div class="forward-long-rectangle60"></div>
        <div class="right-long-rectangle30"></div>
        <div class="left-long-rectangle color0"></div>
        <div class="forward-long-rectangle"></div>
        <div class="right-long-rectangle color180"></div>
        <div class="left-long-rectangle30"></div>
        <div class="forward-long-rectangle120"></div>
		<div class="forward-long-rectangle45"></div>
		<div class="left-long-rectangle15"></div>
		<div class="forward-long-rectangle75"></div>
    </div>
	
    <div class="container2">
        <div class="no-forward-long-rectangle75"></div>
        <div class="no-left-long-rectangle15"></div>
        <div class="no-forward-long-rectangle45"></div>
        <div class="no-forward-long-rectangle120"></div>
        <div class="no-left-long-rectangle30"></div>
        <div class="left-long-rectangle"></div>
        <div class="no-forward-long-rectangle"></div>
        <div class="right-long-rectangle"></div>
        <div class="no-right-long-rectangle30"></div>
        <div class="no-forward-long-rectangle60"></div>
        <div class="no-forward-long-rectangle135"></div>
        <div class="no-right-long-rectangle15"></div>
        <div class="no-forward-long-rectangle105"></div>
    </div>
    
    <div class="blue-rectangle"></div>
    
<!--
<script>

const MaxDistance = 8000 + 1; // 8000 + 1 (for Math.random())

const Angle0 = Math.floor(Math.random() * MaxDistance);
const Angle15 = Math.floor(Math.random() * MaxDistance);
const Angle30 = Math.floor(Math.random() * MaxDistance);
const Angle45 = Math.floor(Math.random() * MaxDistance);
const Angle60 = Math.floor(Math.random() * MaxDistance);
const Angle75 = Math.floor(Math.random() * MaxDistance);
const Angle90 = Math.floor(Math.random() * MaxDistance);
const Angle105 = Math.floor(Math.random() * MaxDistance);
const Angle120 = Math.floor(Math.random() * MaxDistance);
const Angle135 = Math.floor(Math.random() * MaxDistance);
const Angle150 = Math.floor(Math.random() * MaxDistance);
const Angle165 = Math.floor(Math.random() * MaxDistance);
const Angle180 = Math.floor(Math.random() * MaxDistance);
const NoAngle15 = Math.floor(Math.random() * MaxDistance);
const NoAngle30 = Math.floor(Math.random() * MaxDistance);
const NoAngle45 = Math.floor(Math.random() * MaxDistance);
const NoAngle60 = Math.floor(Math.random() * MaxDistance);
const NoAngle75 = Math.floor(Math.random() * MaxDistance);
const NoAngle90 = Math.floor(Math.random() * MaxDistance);
const NoAngle105 = Math.floor(Math.random() * MaxDistance);
const NoAngle120 = Math.floor(Math.random() * MaxDistance);
const NoAngle135 = Math.floor(Math.random() * MaxDistance);
const NoAngle150 = Math.floor(Math.random() * MaxDistance);
const NoAngle165 = Math.floor(Math.random() * MaxDistance);

const angles = [Angle0, Angle15, Angle30, Angle45, Angle60, Angle75, Angle90, Angle105, Angle120, Angle135, Angle150, Angle165, Angle180, NoAngle15, NoAngle30, NoAngle45, NoAngle60, NoAngle75, NoAngle90, NoAngle105, NoAngle120, NoAngle135, NoAngle150, NoAngle165];

let total = 0;
let maxAngle = 0;

angles.forEach(angle => {
    total += angle;
    if (angle > maxAngle) {
        maxAngle = angle;
    }
});

const average = Math.round(total / angles.length * 2);

if (maxAngle > average) {
    Average = maxAngle;
} else {
    Average = average;
}

const originalMin = -10;
const originalMax = 60;

const originalMin2 = 0;
const originalMax2 = 65535;

const newMin = 0;
const newMax = 255;

const customMap = (value, inMin, inMax, outMin, outMax) => {
    return (value - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
};

let rgb0, rgb15, rgb30, rgb45, rgb60, rgb75, rgb90, rgb105, rgb120, rgb135, rgb150, rgb165, rgb180, rgb195, rgb210, rgb225, rgb240, rgb255, rgb270, rgb285, rgb300, rgb315, rgb330, rgb345;

// In reality too, the temperature value is equalized at a fixed place because it will not vary rapidly depending on the object, such as the force.
const RB = Math.random() * (originalMax + originalMin + 1) - originalMin; 

for (let i = 0; i <= 360; i += 15) {
    const Rtemp = customMap(RB, originalMin, originalMax, newMin, newMax);
    const Btemp = customMap(RB, originalMin, originalMax, newMax, newMin);
    const Green = customMap(Math.random() * (originalMax2 + 1), originalMin2, originalMax2, newMax, newMin);
    
    const rgb = `rgb(${Math.round(Rtemp)}, ${Math.round(Green)}, ${Math.round(Btemp)})`;
    
    switch(i) {
        case 0: rgb0 = rgb; break;
        case 15: rgb15 = rgb; break;
        case 30: rgb30 = rgb; break;
        case 45: rgb45 = rgb; break;
        case 60: rgb60 = rgb; break;
        case 75: rgb75 = rgb; break;
        case 90: rgb90 = rgb; break;
        case 105: rgb105 = rgb; break;
        case 120: rgb120 = rgb; break;
        case 135: rgb135 = rgb; break;
        case 150: rgb150 = rgb; break;
        case 165: rgb165 = rgb; break;
        case 180: rgb180 = rgb; break;
        case 195: rgb195 = rgb; break;
        case 210: rgb210 = rgb; break;
        case 225: rgb225 = rgb; break;
        case 240: rgb240 = rgb; break;
        case 255: rgb255 = rgb; break;
        case 270: rgb270 = rgb; break;
        case 285: rgb285 = rgb; break;
        case 300: rgb300 = rgb; break;
        case 315: rgb315 = rgb; break;
        case 330: rgb330 = rgb; break;
        case 345: rgb345 = rgb; break;
    }
}

setTimeout(() => {
  window.location.reload(true);
}, 25000)

</script>
-->
<script>
const Angle0 = (<?php echo $Dist0; ?>);
const Angle15 = (<?php echo $Dist15; ?>);
const Angle30 = (<?php echo $Dist30; ?>);
const Angle45 = (<?php echo $Dist45; ?>);
const Angle60 = (<?php echo $Dist60; ?>);
const Angle75 = (<?php echo $Dist75; ?>);
const Angle90 = (<?php echo $Dist90; ?>);
const Angle105 = (<?php echo $Dist105; ?>);
const Angle120 = (<?php echo $Dist120; ?>);
const Angle135 = (<?php echo $Dist135; ?>);
const Angle150 = (<?php echo $Dist150; ?>);
const Angle165 = (<?php echo $Dist165; ?>);
const Angle180 = (<?php echo $Dist180; ?>);
const NoAngle15 = (<?php echo $Dist195; ?>);
const NoAngle30 = (<?php echo $Dist210; ?>);
const NoAngle45 = (<?php echo $Dist225; ?>);
const NoAngle60 = (<?php echo $Dist240; ?>);
const NoAngle75 = (<?php echo $Dist255; ?>);
const NoAngle90 = (<?php echo $Dist270; ?>);
const NoAngle105 = (<?php echo $Dist285; ?>);
const NoAngle120 = (<?php echo $Dist300; ?>);
const NoAngle135 = (<?php echo $Dist315; ?>);
const NoAngle150 = (<?php echo $Dist330; ?>);
const NoAngle165 = (<?php echo $Dist345; ?>);

const Average = (<?php echo $Average; ?>);

const rgb0 = '<?php echo $rgb0; ?>';
const rgb15 = '<?php echo $rgb15; ?>';
const rgb30 = '<?php echo $rgb30; ?>';
const rgb45 = '<?php echo $rgb45; ?>';
const rgb60 = '<?php echo $rgb60; ?>';
const rgb75 = '<?php echo $rgb75; ?>';
const rgb90 = '<?php echo $rgb90; ?>';
const rgb105 = '<?php echo $rgb105; ?>';
const rgb120 = '<?php echo $rgb120; ?>';
const rgb135 = '<?php echo $rgb135; ?>';
const rgb150 = '<?php echo $rgb150; ?>';
const rgb165 = '<?php echo $rgb165; ?>';
const rgb180 = '<?php echo $rgb180; ?>';
const rgb195 = '<?php echo $rgb195; ?>';
const rgb210 = '<?php echo $rgb210; ?>';
const rgb225 = '<?php echo $rgb225; ?>';
const rgb240 = '<?php echo $rgb240; ?>';
const rgb255 = '<?php echo $rgb255; ?>';
const rgb270 = '<?php echo $rgb270; ?>';
const rgb285 = '<?php echo $rgb285; ?>';
const rgb300 = '<?php echo $rgb300; ?>';
const rgb315 = '<?php echo $rgb315; ?>';
const rgb330 = '<?php echo $rgb330; ?>';
const rgb345 = '<?php echo $rgb345; ?>';
</script>
<script src="lidar.js"></script>
<script>
setTimeout(() => {
  window.location.reload(true);
}, 20000)
</script>
</body>
</html>