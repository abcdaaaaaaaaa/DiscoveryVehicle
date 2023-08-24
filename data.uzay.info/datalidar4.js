       $(document).ready(function() {
            function getData() {
                var url ="https://api.thingspeak.com/channels/2248087/fields/1,2,3,4,5,6,7,8.json?api_key=L8S1E9AKRO8URR4W&results=1";

                $.getJSON(url, function(data) {
                    var field1Values = [];
                    var field2Values = [];
                    var field3Values = [];
                    var field4Values = [];
                    var field5Values = [];
                    var field6Values = [];	
                    var field7Values = [];	
                    var field8Values = [];										
                    var timestamps = [];

                    $.each(data.feeds, function(index, feed) {
						field1Values.push(feed.field1);
						field2Values.push(feed.field2);
						field3Values.push(feed.field3);
						field4Values.push(feed.field4);
						field5Values.push(feed.field5);
						field6Values.push(feed.field6);
						field7Values.push(feed.field7);
						field8Values.push(feed.field8);
						timestamps.push(feed.created_at);
					});
					
const Angle0 = parseInt(field1Values);   
const Angle30 = parseInt(field2Values);   
const Angle60 = parseInt(field3Values);   
const Angle90 = parseInt(field4Values);   
const Angle120 = parseInt(field5Values);   
const Angle150 = parseInt(field6Values);
const Angle180 = parseInt(field7Values);   
const Average = parseInt(field8Values);   

document.cookie = "Angle0="+Angle0;
document.cookie = "Angle30="+Angle30;
document.cookie = "Angle60="+Angle60;
document.cookie = "Angle90="+Angle90;
document.cookie = "Angle120="+Angle120;
document.cookie = "Angle150="+Angle150;
document.cookie = "Angle180="+Angle180;
document.cookie = "Average="+Average;

console.log(Angle0);
console.log(Angle30);
console.log(Angle60);
console.log(Angle90);
console.log(Angle120);
console.log(Angle150);
console.log(Angle180);
console.log(Average);

                });


            }
            getData();

        });
