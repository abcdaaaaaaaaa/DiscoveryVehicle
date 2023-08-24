<?php
include_once 'newlidar.php';
?>

<!doctype html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="shortcut icon" href="../lidar.ico">
    <title id="pageTitle">2D Lidar</title>
    <link rel="stylesheet" href="../lidar.css">
</head>
<body>
    <div class="container">
        <div class="forward-long-rectangle60"></div>
        <div class="right-long-rectangle30"></div>
        <div class="left-long-rectangle"></div>
        <div class="forward-long-rectangle"></div>
        <div class="right-long-rectangle"></div>
        <div class="left-long-rectangle30"></div>
        <div class="forward-long-rectangle120"></div>
    </div>
    <div class="blue-rectangle"></div>
<script>
const Angle0 = (<?php echo $Dist0; ?>);
const Angle30 = (<?php echo $Dist30; ?>);
const Angle60 = (<?php echo $Dist60; ?>);
const Angle90 = (<?php echo $Dist90; ?>);
const Angle120 = (<?php echo $Dist120; ?>);
const Angle150 = (<?php echo $Dist150; ?>);
const Angle180 = (<?php echo $Dist180; ?>);
const Average = (<?php echo $Average; ?>);
const rgb0 = "<?php echo $rgb0; ?>";
const rgb30 = "<?php echo $rgb30; ?>";
const rgb60 = "<?php echo $rgb60; ?>";
const rgb90 = "<?php echo $rgb90; ?>";
const rgb120 = "<?php echo $rgb120; ?>";
const rgb150 = "<?php echo $rgb150; ?>";
const rgb180 = "<?php echo $rgb180; ?>";
</script>
<script src="lidar.js"></script>
<script>
setTimeout(() => {
  window.location.reload(true);
}, 18000)
</script>
</body>
</html>
