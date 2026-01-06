$(document).ready(function() {
    function getData() {
        var url = "https://api.thingspeak.com/channels/2195036/fields/1,2,3,4.json?api_key=DG5Q1OBE0MW2GDTF&results=5";

        $.getJSON(url, function(data) {
            var field1Values = [];
            var field2Values = [];
            var field3Values = [];
            var field4Values = [];
            var timestamps = [];

            $.each(data.feeds, function(index, feed) {
                field1Values.push(feed.field1);
                field2Values.push(feed.field2);
                field3Values.push(feed.field3);
                field4Values.push(feed.field4);
                // timestamps.push(feed.created_at);
	            timestamps.push(feed.created_at.substring(11, 19)); 
            });
                
            var labels = timestamps;

            var datasets = [
                { id: "chart1", color: "#9C27B0", title: "Usv/hr", data: field1Values.map(num => Number(num) / Math.pow(10, 4).toString()) },
                { id: "chart2", color: "#03A9F4", title: "Avg", data: field2Values.map(num => Number(num) / Math.pow(10, 4).toString()) },
                { id: "chart3", color: "#FF5722", title: "SdCPM", data: field3Values.map(num => Number(num) / Math.pow(10, 4).toString()) },
                { id: "chart4", color: "#00E676", title: "CPM Count", data: field4Values.map(num => Number(num)) },
            ];

            datasets.forEach(ds => {
                new Chart(document.getElementById(ds.id), {
                    type: 'line',
                    data: {
                        labels: labels,
                        datasets: [{
                            label: ds.title,
                            data: ds.data,
                            borderColor: ds.color,
                            backgroundColor: ds.color + "33",
                            borderWidth: 4,
                            fill: true,
                            tension: 0.4,
                            pointRadius: 3,
                            pointHoverRadius: 6
                        }]
                    },
                    options: {
                        responsive: true,
                        plugins: {
                            legend: { labels: { color: '#ccc' } }
                        },
                        scales: {
                            x: {
                                title: { display: true, text: 'Time', color: '#ccc' },
                                ticks: { color: '#ccc' },
                                grid: { color: 'rgba(255, 255, 255, 0.01)' }
                            },
                            y: {
                                title: { display: true, text: 'Value', color: '#ccc' },
                                ticks: { color: '#ccc' },
                                grid: { color: 'rgba(255, 255, 255, 0.01)' }
                            }
                        }
                    }
                });
            });
        });
    }

    getData();
});
