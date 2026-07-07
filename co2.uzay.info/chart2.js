$(document).ready(function() {
    var ctx = document.getElementById('myChart2').getContext('2d');
    window.myBarChart2 = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: [],
            datasets: [{
                label: 'SpaceData%',
                data: [],
                backgroundColor: blue(0.2),
                borderColor: blue(1),
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
});