<!doctype html>
<html>
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
   <link rel="shortcut icon" href="bluespace.ico">
   <link rel="stylesheet" href="customchart.css">
  <title>CO2 Analysis System</title>
  <script src="https://code.jquery.com/jquery-3.7.0.min.js"></script>
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
    <font color="white" size=4 id="pcoef_text">-</font>
    </div>
    <div class="spacecreate2">
    <font color="white" size=4 id="dht_text">-</font>
    </div>
    <div class="spacecreate3">
    <font color="white" size=3 id="loc_text">-</font>
    </div>
    </div>
    </div>
    </div>
    </div>
    
<script>
    var toplam3 = 0;
    var toplam4 = 0;
    var toplam5 = 0;
    var toplam6 = 0;
    var toplam7 = 0;
</script>

<script src="https://cdn.jsdelivr.net/npm/chart.js@3.7.0/dist/chart.min.js"></script>
<script src="datacolor.js"></script>
<script src="chart2.js"></script>

<script>
 var ctx = document.getElementById('barchart').getContext('2d');
 var barchart = new Chart(ctx, hello('bar'));    
 var ctx2 = document.getElementById('doughnut').getContext('2d');
 var doughnut = new Chart(ctx2, hello('doughnut'));    

 function fetchLatestValues() {
     $.ajax({
         url: "datareceiver.php",
         type: "GET",
         data: { api_key: "PWIFQRC3WHDW6YG5", results: 7 },
         cache: false,
         dataType: "json",
         success: function(data) {
             if (data.feeds && data.feeds.length > 0) {
                 var feed = data.feeds[data.feeds.length - 1];

                 toplam4 = parseFloat(feed.CO2) || 0;
                 toplam3 = parseFloat(feed.TheoCO2) || 0;
                 toplam5 = parseFloat(feed.CH4) || 0;
                 toplam6 = parseFloat(feed.C2H5OH) || 0;
                 toplam7 = parseFloat(feed.CO) || 0;

                 barchart.data.datasets[0].data = [toplam4, toplam3, toplam5, toplam6, toplam7];
                 barchart.update();
                 
                 doughnut.data.datasets[0].data = [toplam4, toplam3, toplam5, toplam6, toplam7];
                 doughnut.update();

                 $('#pcoef_text').text(feed.PCoef);
                 $('#dht_text').text(feed.DHT);
                 $('#loc_text').text(feed.lat + ' ' + feed.lng);

                 if (window.myBarChart2) {
                     var field8Values = [];
                     var timestamps = [];
                     $.each(data.feeds, function(index, item) {
                         var val = item.SpaceData ? parseFloat(item.SpaceData.replace('%', '')) : 0;
                         field8Values.push(val);
                         var timeStr = item.reading_time ? item.reading_time.substring(11, 19) : "";
                         timestamps.push(timeStr);
                     });
                     window.myBarChart2.data.labels = timestamps;
                     window.myBarChart2.data.datasets[0].data = field8Values;
                     window.myBarChart2.update();
                 }
             }
         }
     });
 }

 fetchLatestValues();
 setInterval(fetchLatestValues, 5000);
</script>
</body>
</html>