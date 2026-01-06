    $(document).ready(function() {
        function getData() {
            var url ="https://api.thingspeak.com/channels/2169907/fields/2,5.json?api_key=AL0IDSI4FU59TFXT&results=5";

            $.getJSON(url, function(data) {
                var field2Values = [];
                var field5Values = [];
                var timestamps = [];

                $.each(data.feeds, function(index, feed) {
					field2Values.push(feed.field2);
					field5Values.push(feed.field5);
                    // timestamps.push(feed.created_at);
    	            timestamps.push(feed.created_at.substring(11, 19)); 
				});

                var ctx = document.getElementById('myChart2').getContext('2d');
                var chart = new Chart(ctx, {
                    type:'bar',
                    data:{
                        labels:timestamps,
                        datasets:[{
                            label: 'SpaceData1%',
                            data: field2Values.map(num => parseInt(Number(num) / (Math.pow(2, 12) - 1) * 100).toString()),
                            backgroundColor: red(0.2),
                            borderColor:  red(1),
                            borderWidth: 1
                        },
                        {
                            label: 'SpaceData2%',
                            data: field5Values.map(num => parseInt(Number(num) / (Math.pow(2, 12) - 1) * 100).toString()),
                            backgroundColor: blue(0.2),
                            borderColor:  blue(1),
                            borderWidth: 1
                        }
					]
                    },
                    options: {
                      scales: {
                        y: {
                          ticks: {
                            beginAtZero: true
                          }
                        }
                      }
                    }
                });
            });
        }
        getData();
        });