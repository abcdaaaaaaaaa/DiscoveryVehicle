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
  <title>Chernobyl</title>
  </head>
  <body>
    <div class="container">
	     <div class="chart">
        <canvas id="barchart" width="500" height="500"></canvas>
         </div> 
		 <div class="solorta">
	     <div class="chart">
        <canvas id="myChart2"  width="450" height="500"></canvas>
         </div> 
		 </div>

 <div class="bigcreate">
 <div class="secondcontainer">

		 <div class="chart">
		 <canvas id="doughnut"  width="300" height="300"></canvas>
		 </div>
<div class="create">
<div class="spacecreate1">
<font color="white" size=6><?php echo $value15; ?></font>
</div>
<div class="spacecreate2">
<font color="white" size=6><?php echo $value16; ?></font>
</div>
<div class="spacecreate3">
<font color="white" size=6><?php echo $value17; ?></font>
</div>
<div class="spacecreate4">
<font color="white" size=3><?php echo $lat; ?> <?php echo $lng; ?></font>
</div>
		 </div>

</div>
</div>
</div>
<script  src="https://cdn.jsdelivr.net/npm/chart.js@3.8.0/dist/chart.min.js"></script>
<script src="chart2.js"></script>
<script>
const ctx2 = document.getElementById('doughnut').getContext('2d');
const doughnut = new Chart(ctx2, {
      type: 'doughnut',
       data : {
      labels: ['MQ2', 'MQ3', 'MQ4',  'MQ135'],
      datasets: [{
        label: 'MQData ppm',
        data: [<?php echo $MQ2; ?>, <?php echo $MQ3; ?>, <?php echo $MQ4; ?>, <?php echo $MQ135; ?>],
        backgroundColor: [
          'rgba(255, 26, 104, 0.2)', 
          'rgba(54, 162, 235, 0.2)',
          'rgba(153, 102, 255, 0.2)',
          'rgba(58, 51, 255, 0.2)',
        ],
        borderColor: [
          'rgba(255, 26, 104, 1)', 
          'rgba(54, 162, 235, 1)',
          'rgba(153, 102, 255, 1)',
          'rgba(58, 51, 255, 1)',
        ],
        borderWidth: 1
      }]
	  },
      options: {	  
        scales: {
          y: {
            beginAtZero: true
          }
        }
      }
	  });

</script>
<script>
const ctx = document.getElementById('barchart').getContext('2d');
const barchart = new Chart(ctx, {
      type: 'bar',
      data : {
     labels: ['Alcohol', 'Benzene', 'Hexane', 'CH4', 'Smoke', 'CO2', 'Toluen', 'NH4', 'Aceton', 'LPG', 'Propane', 'CO', 'H2', 'Air'],
      datasets: [{
        label: 'Air Quality',
        data: [<?php echo $value1; ?>, <?php echo $value2; ?>, <?php echo $value3; ?>, <?php echo $value4; ?>, <?php echo $value5; ?>, <?php echo $value6; ?>, <?php echo $value7; ?>,<?php echo $value8; ?>, <?php echo $value9; ?>, <?php echo $value10; ?>, <?php echo $value11; ?>, <?php echo $value12; ?>, <?php echo $value13; ?>, 1<?php echo $value14; ?>],
        backgroundColor: [
          'rgba(255, 26, 104, 0.2)',
          'rgba(255, 26, 104, 0.2)',
          'rgba(255, 26, 104, 0.2)',
          'rgba(255, 159, 64, 0.2)',
          'rgba(255, 159, 64, 0.2)',
          'rgba(54, 162, 235, 0.2)',
          'rgba(54, 162, 235, 0.2)',
          'rgba(54, 162, 235, 0.2)',
          'rgba(54, 162, 235, 0.2)',
          'rgba(75, 192, 192, 0.2)',
          'rgba(75, 192, 192, 0.2)',
          'rgba(153, 102, 255, 0.2)',
          'rgba(153, 102, 255, 0.2)',
          'rgba(58, 51, 255, 0.2)',
        ],
        borderColor: [
          'rgba(255, 26, 104, 1)',
          'rgba(255, 26, 104, 1)',
          'rgba(255, 26, 104, 1)',
          'rgba(255, 159, 64, 1)',
          'rgba(255, 159, 64, 1)',
          'rgba(54, 162, 235, 1)',
          'rgba(54, 162, 235, 1)',
          'rgba(54, 162, 235, 1)',
          'rgba(54, 162, 235, 1)',
          'rgba(75, 192, 192, 1)',
          'rgba(75, 192, 192, 1)',
          'rgba(153, 102, 255, 1)',
          'rgba(153, 102, 255, 1)',
          'rgba(58, 51, 255, 1)',
        ],
        borderWidth: 1
      }]
	  },

      options: {
	  indexAxis: 'y',
        scales: {
          y: {
            beginAtZero: true
          }
        }
      }
	  });

</script>
<script>
setTimeout(() => {
  window.location.reload(true);
}, 18000)
</script>
  </body>
</html>
