<?php include_once 'newhello.php'; ?>

<!doctype html>
<html>
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
   <link rel="shortcut icon" href="bluespace.ico">
   <link rel="stylesheet" href="customchart.css">
   <link rel="stylesheet" href="slider.css">
  <title>Air Analysis System</title>
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
    <font color="white" size=4><?php echo $DHT; ?></font>
    </div>
    <div class="spacecreate2">
    <font color="white" size=3><?php echo $value14; ?> <?php echo $value15; ?></font>
    </div>
    </div>
    </div>
    </div>
    </div>
    
<script>
    <?php
        if (isset($toplam1)) echo "const toplam1 = $toplam1;\n\t";
        if (isset($toplam2)) echo "const toplam2 = $toplam2;\n\t";
        if (isset($toplam3)) echo "const toplam3 = $toplam3;\n\t";
        if (isset($toplam4)) echo "const toplam4 = $toplam4;\n\t";
        if (isset($toplam5)) echo "const toplam5 = $toplam5;\n\t";
        if (isset($value3)) echo "const value3 = $value3;\n\t";
        if (isset($value4)) echo "const value4 = $value4;\n\t";
        if (isset($value5)) echo "const value5 = $value5;\n\t";
        if (isset($value6)) echo "const value6 = $value6;\n\t";
        if (isset($value7)) echo "const value7 = $value7;\n\t";
        if (isset($value8)) echo "const value8 = $value8;\n\t";
        if (isset($value9)) echo "const value9 = $value9;\n\t";
        if (isset($value10)) echo "const value10 = $value10;\n\t";
    ?>
</script>

<script src="https://cdn.jsdelivr.net/npm/chart.js@3.7.0/dist/chart.min.js"></script>
<script src="datacolor.js"></script>
<script src="chart2.js"></script>
<script src="slider.js"></script>

<script>
 const ctx = document.getElementById('barchart').getContext('2d');
 const barchart = new Chart(ctx,hello('bar'));    
 const ctx2 = document.getElementById('doughnut').getContext('2d');
 const doughnut = new Chart(ctx2,hello('doughnut'));    
</script>
</body>
</html>
