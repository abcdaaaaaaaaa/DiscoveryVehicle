<!doctype html>
<html>
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="shortcut icon" href="bluespace.ico">
    <link rel="stylesheet" href="customchart.css">
    <title>Air Analysis System</title>
  </head>
  <body>
    <div class="container">
        <div class="chart">
            <canvas id="barchart" width="450" height="500"></canvas>
        </div> 
        <div class="solorta">
            <div class="chart">
                <canvas id="myChart2" width="500" height="500"></canvas>
            </div> 
        </div>
        <div class="bigcreate">
            <div class="secondcontainer">
                <div class="chart">
                    <canvas id="doughnut" width="300" height="300"></canvas>
                </div>
                <div class="create">
                    <div class="spacecreate1">
                        <font color="white" size="4"><?php echo isset($DHT) ? $DHT : '0°C %0'; ?></font>
                    </div>
                    <div class="spacecreate2">
                        <font color="white" size="3"><?php echo isset($value14) ? $value14 : '0'; ?> <?php echo isset($value15) ? $value15 : '0'; ?></font>
                    </div>
                </div>
            </div>
        </div>
    </div>
    
<script>
    window.total1 = <?php echo floatval($total1 ?? 1); ?>;
    window.total2 = <?php echo floatval($total2 ?? 0); ?>;
    window.total3 = <?php echo floatval($total3 ?? 0); ?>;
    window.total4 = <?php echo floatval($total4 ?? 0); ?>;
    window.total5 = <?php echo floatval($total5 ?? 0); ?>;
    window.value2 = <?php echo floatval($value2 ?? 0); ?>;
    window.value3 = <?php echo floatval($value3 ?? 0); ?>;
    window.value4 = <?php echo floatval($value4 ?? 0); ?>;
    window.value5 = <?php echo floatval($value5 ?? 0); ?>;
    window.value6 = <?php echo floatval($value6 ?? 0); ?>;
    window.value7 = <?php echo floatval($value7 ?? 0); ?>;
    window.value8 = <?php echo floatval($value8 ?? 0); ?>;
    window.value9 = <?php echo floatval($value9 ?? 0); ?>;
    window.value10 = <?php echo floatval($value10 ?? 0); ?>;
    window.value11 = <?php echo floatval($_COOKIE["value11"] ?? 0); ?>;
    window.value12 = <?php echo floatval($_COOKIE["value12"] ?? 0); ?>;
    window.value13 = <?php echo floatval($value13 ?? 0); ?>;
    window.value14 = <?php echo floatval($value14 ?? 0); ?>;
    window.value15 = <?php echo floatval($value15 ?? 0); ?>;
</script>

<script src="https://cdn.jsdelivr.net/npm/chart.js@3.7.0/dist/chart.min.js"></script>
<script src="datacolor.js"></script>
<script src="chart2.js"></script>
<script type="module" src="data.js"></script>

<script>
 var ctx = document.getElementById('barchart').getContext('2d');
 var barchart = new Chart(ctx, getChartConfig('bar'));    
 var ctx2 = document.getElementById('doughnut').getContext('2d');
 var doughnut = new Chart(ctx2, getChartConfig('doughnut'));    

 window.updateCharts = function() {
     if (typeof barchart !== 'undefined' && typeof dataList !== 'undefined') {
         var barConfig = getChartConfig('bar');
         barchart.data.labels = barConfig.data.labels;
         barchart.data.datasets[0].label = barConfig.data.datasets[0].label;
         barchart.data.datasets[0].data = dataList;
         barchart.data.datasets[0].backgroundColor = barConfig.data.datasets[0].backgroundColor;
         barchart.data.datasets[0].borderColor = barConfig.data.datasets[0].borderColor;
         barchart.update();
     }
     
     if (typeof doughnut !== 'undefined' && typeof dataList !== 'undefined') {
         var doughConfig = getChartConfig('doughnut');
         doughnut.data.labels = doughConfig.data.labels;
         doughnut.data.datasets[0].label = doughConfig.data.datasets[0].label;
         doughnut.data.datasets[0].data = dataList;
         doughnut.data.datasets[0].backgroundColor = doughConfig.data.datasets[0].backgroundColor;
         doughnut.data.datasets[0].borderColor = doughConfig.data.datasets[0].borderColor;
         doughnut.update();
     }

     if (typeof window.value11 !== 'undefined' && typeof window.value12 !== 'undefined') {
         document.querySelector('.spacecreate1 font').innerHTML = window.value11 + '°C %' + window.value12;
     }

     if (typeof window.value14 !== 'undefined' && typeof window.value15 !== 'undefined') {
         var lat = (window.value14 * Math.pow(10, -7) - 90).toFixed(7);
         var lng = (window.value15 * Math.pow(10, -7) - 180).toFixed(7);
         document.querySelector('.spacecreate2 font').innerHTML = lat + ' ' + lng;
     }
 };

 function syncCalculatedData() {
     var updateParams = new URLSearchParams({
         api_key: "J2UEIZSZTC5568NM",
         update_calculated: "1",
         total1: window.total1,
         value3: window.value3 || 0,
         value4: window.value4 || 0,
         value5: window.value5 || 0,
         value6: window.value6 || 0,
         value7: window.value7 || 0,
         value8: window.value8 || 0,
         value9: window.value9 || 0,
         value10: window.value10 || 0
     });

     fetch('datareceiver.php', {
         method: 'POST',
         headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
         body: updateParams
     }).catch(err => console.error(err));
 }

 function loadLiveData() {
     fetch('datareceiver.php?api_key=J2UEIZSZTC5568NM&results=5')
         .then(response => response.json())
         .then(data => {
             if (data.feeds && data.feeds.length > 0) {
                 var feed = data.feeds[data.feeds.length - 1];
                 
                 window.total1 = parseInt(feed.field1);
                 window.total2 = parseFloat(feed.field2);
                 window.total3 = parseFloat(feed.field3);
                 window.total4 = parseFloat(feed.field4);
                 window.total5 = parseFloat(feed.field5);
                 window.value14 = parseFloat(feed.field6);
                 window.value15 = parseFloat(feed.field7);
                 
                 if (typeof window.calculateData === 'function') {
                     window.calculateData();
                     syncCalculatedData();
                 }

                 var timestamps = [];
                 var field2Values = [];
                 var field5Values = [];
                 
                 data.feeds.forEach(function(item) {
                     var val1 = item.field2 ? (parseFloat(item.field2) / 40.95).toFixed(4) : 0;
                     var val2 = item.field5 ? (parseFloat(item.field5) / 40.95).toFixed(4) : 0;
                     field2Values.push(val1);
                     field5Values.push(val2);
                     var timeStr = item.created_at ? item.created_at.substring(11, 19) : "";
                     timestamps.push(timeStr);
                 });
                 
                 if (typeof window.myBarChart2 !== 'undefined') {
                     window.myBarChart2.data.labels = timestamps;
                     window.myBarChart2.data.datasets[0].data = field2Values;
                     window.myBarChart2.data.datasets[1].data = field5Values;
                     window.myBarChart2.update();
                 }
                 
                 window.updateCharts();
             }
         })
         .catch(err => console.error(err));
 }

 window.addEventListener('DOMContentLoaded', () => {
     setInterval(loadLiveData, 5000);
     setTimeout(loadLiveData, 500);
 });
</script>
</body>
</html>