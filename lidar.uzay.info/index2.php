<?php include_once 'yaxsis.php'; ?>

<!doctype html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="shortcut icon" href="lidar.ico">
    <title id="pageTitle">3D Lidar</title>
    <link rel="stylesheet" href="verticallidar.css">
    <link rel="stylesheet" href="slider.css">
</head>
<body>
    <form method="POST">
        <div class="switch-container">
            <label class="switch">
                <input type="checkbox" id="saveData" name="saveData">
                <span class="slider"></span>
            </label>
            <input type="submit" id="saveButton" value="Save Data">
        </div>
    </form>
    <div class="container1">
		<div class="forward-long-rectangle105">
    <div class="face1 color105 front"></div>
    <div class="face1 color105 back"></div>
    <div class="face2 color105 right"></div>
    <div class="face2 color105 left"></div>
    <div class="face3 color105 top"></div>
    <div class="face3 color105 bottom"></div>
		</div>
		<div class="right-long-rectangle15">
    <div class="face1 color165 front"></div>
    <div class="face1 color165 back"></div>
    <div class="face2 color165 right"></div>
    <div class="face2 color165 left"></div>
    <div class="face3 color165 top"></div>
    <div class="face3 color165 bottom"></div>
		</div>
		<div class="forward-long-rectangle135">
    <div class="face1 color135 front"></div>
    <div class="face1 color135 back"></div>
    <div class="face2 color135 right"></div>
    <div class="face2 color135 left"></div>
    <div class="face3 color135 top"></div>
    <div class="face3 color135 bottom"></div>
		</div>
        <div class="forward-long-rectangle60">
    <div class="face1 color60 front"></div>
    <div class="face1 color60 back"></div>
    <div class="face2 color60 right"></div>
    <div class="face2 color60 left"></div>
    <div class="face3 color60 top"></div>
    <div class="face3 color60 bottom"></div>
		</div>
        <div class="right-long-rectangle30">
    <div class="face1 color150 front"></div>
    <div class="face1 color150 back"></div>
    <div class="face2 color150 right"></div>
    <div class="face2 color150 left"></div>
    <div class="face3 color150 top"></div>
    <div class="face3 color150 bottom"></div>
		</div>
        <div class="left-long-rectangle color0">
		</div>
        <div class="forward-long-rectangle">
    <div class="face1 color90 front"></div>
    <div class="face1 color90 back"></div>
    <div class="face2 color90 right"></div>
    <div class="face2 color90 left"></div>
    <div class="face3 color90 top"></div>
    <div class="face3 color90 bottom"></div>
		</div>
        <div class="right-long-rectangle color180">
		</div>
        <div class="left-long-rectangle30">
    <div class="face1 color30 front"></div>
    <div class="face1 color30 back"></div>
    <div class="face2 color30 right"></div>
    <div class="face2 color30 left"></div>
    <div class="face3 color30 top"></div>
    <div class="face3 color30 bottom"></div>
		</div>
        <div class="forward-long-rectangle120">
    <div class="face1 color120 front"></div>
    <div class="face1 color120 back"></div>
    <div class="face2 color120 right"></div>
    <div class="face2 color120 left"></div>
    <div class="face3 color120 top"></div>
    <div class="face3 color120 bottom"></div>
		</div>
		<div class="forward-long-rectangle45">
    <div class="face1 color45 front"></div>
    <div class="face1 color45 back"></div>
    <div class="face2 color45 right"></div>
    <div class="face2 color45 left"></div>
    <div class="face3 color45 top"></div>
    <div class="face3 color45 bottom"></div>
		</div>
		<div class="left-long-rectangle15">
    <div class="face1 color15 front"></div>
    <div class="face1 color15 back"></div>
    <div class="face2 color15 right"></div>
    <div class="face2 color15 left"></div>
    <div class="face3 color15 top"></div>
    <div class="face3 color15 bottom"></div>
		</div>
		<div class="forward-long-rectangle75">
    <div class="face1 color75 front"></div>
    <div class="face1 color75 back"></div>
    <div class="face2 color75 right"></div>
    <div class="face2 color75 left"></div>
    <div class="face3 color75 top"></div>
    <div class="face3 color75 bottom"></div>
		</div>
    </div>
	
    <div class="container2">
        <div class="no-forward-long-rectangle75">
    <div class="face1 color255 front"></div>
    <div class="face1 color255 back"></div>
    <div class="face2 color255 right"></div>
    <div class="face2 color255 left"></div>
    <div class="face3 color255 top"></div>
    <div class="face3 color255 bottom"></div>
		</div>
        <div class="no-left-long-rectangle15">
    <div class="face1 color195 front"></div>
    <div class="face1 color195 back"></div>
    <div class="face2 color195 right"></div>
    <div class="face2 color195 left"></div>
    <div class="face3 color195 top"></div>
    <div class="face3 color195 bottom"></div>
		</div>
        <div class="no-forward-long-rectangle45">
    <div class="face1 color225 front"></div>
    <div class="face1 color225 back"></div>
    <div class="face2 color225 right"></div>
    <div class="face2 color225 left"></div>
    <div class="face3 color225 top"></div>
    <div class="face3 color225 bottom"></div>
		</div>
        <div class="no-forward-long-rectangle120">
    <div class="face1 color300 front"></div>
    <div class="face1 color300 back"></div>
    <div class="face2 color300 right"></div>
    <div class="face2 color300 left"></div>
    <div class="face3 color300 top"></div>
    <div class="face3 color300 bottom"></div>
		</div>
        <div class="no-left-long-rectangle30">
    <div class="face1 color210 front"></div>
    <div class="face1 color210 back"></div>
    <div class="face2 color210 right"></div>
    <div class="face2 color210 left"></div>
    <div class="face3 color210 top"></div>
    <div class="face3 color210 bottom"></div>
		</div>
        <div class="left-long-rectangle">
    <div class="face1 color0 front"></div>
    <div class="face1 color0 back"></div>
    <div class="face2 color0 right"></div>
    <div class="face2 color0 left"></div>
    <div class="face3 color0 top"></div>
    <div class="face3 color0 bottom"></div>
		</div>
        <div class="no-forward-long-rectangle">
    <div class="face1 color270 front"></div>
    <div class="face1 color270 back"></div>
    <div class="face2 color270 right"></div>
    <div class="face2 color270 left"></div>
    <div class="face3 color270 top"></div>
    <div class="face3 color270 bottom"></div>
		</div>
        <div class="right-long-rectangle">
    <div class="face1 color180 front"></div>
    <div class="face1 color180 back"></div>
    <div class="face2 color180 right"></div>
    <div class="face2 color180 left"></div>
    <div class="face3 color180 top"></div>
    <div class="face3 color180 bottom"></div>
		</div>
        <div class="no-right-long-rectangle30">
    <div class="face1 color330 front"></div>
    <div class="face1 color330 back"></div>
    <div class="face2 color330 right"></div>
    <div class="face2 color330 left"></div>
    <div class="face3 color330 top"></div>
    <div class="face3 color330 bottom"></div>
		</div>
        <div class="no-forward-long-rectangle60">
    <div class="face1 color240 front"></div>
    <div class="face1 color240 back"></div>
    <div class="face2 color240 right"></div>
    <div class="face2 color240 left"></div>
    <div class="face3 color240 top"></div>
    <div class="face3 color240 bottom"></div>
		</div>
        <div class="no-forward-long-rectangle135">
    <div class="face1 color315 front"></div>
    <div class="face1 color315 back"></div>
    <div class="face2 color315 right"></div>
    <div class="face2 color315 left"></div>
    <div class="face3 color315 top"></div>
    <div class="face3 color315 bottom"></div>
		</div>
        <div class="no-right-long-rectangle15">
    <div class="face1 color345 front"></div>
    <div class="face1 color345 back"></div>
    <div class="face2 color345 right"></div>
    <div class="face2 color345 left"></div>
    <div class="face3 color345 top"></div>
    <div class="face3 color345 bottom"></div>
		</div>
        <div class="no-forward-long-rectangle105">
    <div class="face1 color285 front"></div>
    <div class="face1 color285 back"></div>
    <div class="face2 color285 right"></div>
    <div class="face2 color285 left"></div>
    <div class="face3 color285 top"></div>
    <div class="face3 color285 bottom"></div>
		</div>
    </div>
    <div class="blue-rectangle"></div>

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
<script src="slider2.js"></script>
</body>
</html>