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
					
const data9 = parseInt(field1Values);   
const data10 = parseInt(field2Values);   
const data11 = parseInt(field3Values);   
const data12 = parseInt(field4Values);   
const data13 = parseInt(field5Values);   
const data14 = parseInt(field6Values);
const data15 = parseInt(field7Values);   
const data16 = parseInt(field8Values);   

document.cookie = "data9="+data9;
document.cookie = "data10="+data10;
document.cookie = "data11="+data11;
document.cookie = "data12="+data12;
document.cookie = "data13="+data13;
document.cookie = "data14="+data14;
document.cookie = "data15="+data15;
document.cookie = "data16="+data16;

console.log(data9);
console.log(data10);
console.log(data11);
console.log(data12);
console.log(data13);
console.log(data14);
console.log(data15);
console.log(data16);

                });


            }
            getData();

        });
