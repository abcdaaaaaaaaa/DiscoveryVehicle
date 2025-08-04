       $(document).ready(function() {
            function getData() {
                var url ="https://api.thingspeak.com/channels/3026076/feeds/1,2,3,4,5,6,7,8.json?api_key=9ATA4ZAICPKOK1BT&results=1";

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
        
const data1 = parseInt(field1Values);   
const data2 = parseInt(field2Values);   
const data3 = parseInt(field3Values);   
const data4 = parseInt(field4Values);   
const data5 = parseInt(field5Values);   
const data6 = parseInt(field6Values);
const data7 = parseInt(field7Values);   
const data8 = parseInt(field8Values);   

document.cookie = "data1="+data1;
document.cookie = "data2="+data2;
document.cookie = "data3="+data3;
document.cookie = "data4="+data4;
document.cookie = "data5="+data5;
document.cookie = "data6="+data6;
document.cookie = "data7="+data7;
document.cookie = "data8="+data8;

console.log(data1);
console.log(data2);
console.log(data3);
console.log(data4);
console.log(data5);
console.log(data6);
console.log(data7);
console.log(data8);

                });


            }
            getData();

        });
