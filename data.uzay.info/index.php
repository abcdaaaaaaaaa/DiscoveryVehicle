<?php include_once 'newhello.php'; ?>

<!doctype html>
<html>
<head>
    <meta charset="UTF-8" />
    <title>Radiation Metrics System</title>
    <link rel="icon" href="bluespace.ico">
    <link rel="stylesheet" href="RadiationMetrics.css">
    <link rel="stylesheet" href="slider.css">
    <script src="https://cdn.jsdelivr.net/npm/chart.js@3.7.0/dist/chart.min.js"></script>
    <script src="RadiationMetrics.js"></script>
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
        <div class="chart-card">
            <div class="chart-title">Usv/hr</div>
            <canvas id="chart1"></canvas>
        </div>
        <div class="chart-card">
            <div class="chart-title">Avg</div>
            <canvas id="chart2"></canvas>
        </div>
        <div class="chart-card">
            <div class="chart-title">SdCPM</div>
            <canvas id="chart3"></canvas>
        </div>
        <div class="chart-card">
            <div class="chart-title">CPM Count</div>
            <canvas id="chart4"></canvas>
        </div>
    </div>
    <script src="slider.js"></script>
</body>
</html>
