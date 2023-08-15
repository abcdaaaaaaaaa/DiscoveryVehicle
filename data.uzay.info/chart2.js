        $(document).ready(function() {
            function getData() {
                var url ="https://api.thingspeak.com/channels/2195036/fields/5,6.json?api_key=DG5Q1OBE0MW2GDTF&results=5";

                $.getJSON(url, function(data) {
                    var field5Values = [];
                    var field6Values = [];
                    var timestamps = [];

                    $.each(data.feeds, function(index, feed) {
						field5Values.push(feed.field5);
						field6Values.push(feed.field6);
						timestamps.push(feed.created_at);
					});
                    //dealing the the graph
                    var ctx = document.getElementById('myChart2').getContext('2d');

                    var chart = new Chart(ctx, {
                        type:'bar',
                        data:{
                            labels:timestamps,
                            datasets:[{
                                label: 'SpaceData1%',
                                data: field5Values,
                                backgroundColor: red(0.2),
                                borderColor:  red(1),
                                borderWidth: 1
                            },
                            {
                                label: 'SpaceData2%',
                                data: field6Values,
                                backgroundColor: blue(0.2),
                                borderColor:  blue(1),
                                borderWidth: 1                                
                                
                            }
                            
						]
                        },
                        options: {
                            scales: {
                                yAxes: [{
                                    thicks: {
                                        beginAtZero: true
                                    }
                                }]
                            }
                        }
                    });




                });

            }
            getData();

        });