document.addEventListener('DOMContentLoaded', function() {
    var chartCanvas = document.getElementById('myChart2');
    if (!chartCanvas) return;

    var ctx = chartCanvas.getContext('2d');
    window.myBarChart2 = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: [],
            datasets: [
                {
                    label: 'SpaceData1%',
                    data: [],
                    backgroundColor: red(0.2),
                    borderColor: red(1),
                    borderWidth: 1
                },
                {
                    label: 'SpaceData2%',
                    data: [],
                    backgroundColor: blue(0.2),
                    borderColor: blue(1),
                    borderWidth: 1
                }
            ]
        },
        options: {
            scales: {
                y: {
                    beginAtZero: true
                }
            }
        }
    });
});