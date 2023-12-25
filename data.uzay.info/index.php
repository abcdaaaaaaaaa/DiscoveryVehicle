<?php
include_once 'newhello.php';
?>

<!doctype html>
<html>
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
   <link rel="shortcut icon" href="../bluespace.png">
   <link rel="stylesheet" href="../customchart.css">
  <title>Nuclear and Chemical Data Calculation System</title>
  </head>
  <body>
    <div class="container">
	     <div class="chart">
        <canvas id="barchart" width="450" height="500"></canvas>
         </div> 
		 <div class="solorta">
	     <div class="chart">
        <canvas id="myChart2"  width="500" height="500"></canvas>
         </div> 
		 </div>

 <div class="bigcreate">
 <div class="secondcontainer">

		 <div class="chart">
		 <canvas id="doughnut"  width="300" height="300"></canvas>
		 </div>
<div class="create">
<div class="spacecreate1">
<font color="white" size=5><?php echo $value9; ?></font>
</div>
<div class="spacecreate2">
<font color="white" size=4><?php echo $value10; ?>+/-<?php echo $value11; ?></font>
</div>
<div class="spacecreate3">
<font color="white" size=6><?php echo $value12; ?></font>
</div>
<div class="spacecreate4">
<font color="white" size=3><?php echo $value15; ?> <?php echo $value16; ?></font>
</div>
</div>

</div>
</div>
</div>

<script>
const toplam1 = (<?php echo $value1; ?>);
const toplam2 = (<?php echo $value2; ?>);
const toplam3 = (<?php echo $value3; ?>);
const toplam4 = (<?php echo $value4; ?>);
const toplam5 = (<?php echo $value5; ?>);
const toplam6 = (<?php echo $value6; ?>);
const toplam7 = (<?php echo $value7; ?>);
const toplam8 = (<?php echo $char1; ?>);
</script>
<script src="https://cdn.jsdelivr.net/npm/chart.js@3.7.0/dist/chart.min.js"></script>
<script src="../datacolor.js"></script>
<script src="../chart2.js"></script>
<script>
  const ctx = document.getElementById('barchart').getContext('2d');
  const barchart = new Chart(ctx,hello('bar'));    
  console.log(hello());
  const ctx2 = document.getElementById('doughnut').getContext('2d');
  const doughnut = new Chart(ctx2,hello('doughnut'));    
</script>
<script>
setTimeout(() => {
  window.location.reload(true);
}, 20000)
</script>
</body>
</html>