       $(document).ready(function() {
            function getData() {
                var url ="https://api.thingspeak.com/channels/2195037/fields/1,2,3,4,5,6,7.json?api_key=H9IXGTX44JKNORPW&results=1";

                $.getJSON(url, function(data) {
                    var field1Values = [];
                    var field2Values = [];
                    var field3Values = [];
                    var field4Values = [];
                    var field5Values = [];
                    var field6Values = [];	
                    var field7Values = [];	
                    var timestamps = [];

                    $.each(data.feeds, function(index, feed) {
						field1Values.push(feed.field1);
						field2Values.push(feed.field2);
						field3Values.push(feed.field3);
						field4Values.push(feed.field4);
						field5Values.push(feed.field5);
						field6Values.push(feed.field6);
						field7Values.push(feed.field7);
						timestamps.push(feed.created_at);
					});
        
const green0 = parseInt(field1Values);   
const green30 = parseInt(field2Values);   
const green60 = parseInt(field3Values);   
const green90 = parseInt(field4Values);   
const green120 = parseInt(field5Values);   
const green150 = parseInt(field6Values);
const green180 = parseInt(field7Values);   

document.cookie = "green0="+green0;
document.cookie = "green30="+green30;
document.cookie = "green60="+green60;
document.cookie = "green90="+green90;
document.cookie = "green120="+green120;
document.cookie = "green150="+green150;
document.cookie = "green180="+green180;

console.log(green0);
console.log(green30);
console.log(green60);
console.log(green90);
console.log(green120);
console.log(green150);
console.log(green180);

                });


            }
            getData();

        });
