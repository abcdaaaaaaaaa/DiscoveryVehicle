       $(document).ready(function() {
            function getData() {
                var url ="https://api.thingspeak.com/channels/2248096/fields/1,2,3,4,5,6,7.json?api_key=V8217HGH2YKR9ZIK&results=1";

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
        
const temp0 = parseInt(field1Values);   
const temp30 = parseInt(field2Values);   
const temp60 = parseInt(field3Values);   
const temp90 = parseInt(field4Values);   
const temp120 = parseInt(field5Values);   
const temp150 = parseInt(field6Values);
const temp180 = parseInt(field7Values);   

document.cookie = "temp0="+temp0;
document.cookie = "temp30="+temp30;
document.cookie = "temp60="+temp60;
document.cookie = "temp90="+temp90;
document.cookie = "temp120="+temp120;
document.cookie = "temp150="+temp150;
document.cookie = "temp180="+temp180;

console.log(temp0);
console.log(temp30);
console.log(temp60);
console.log(temp90);
console.log(temp120);
console.log(temp150);
console.log(temp180);

                });


            }
            getData();

        });
