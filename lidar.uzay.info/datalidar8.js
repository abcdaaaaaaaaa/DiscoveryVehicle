       $(document).ready(function() {
            function getData() {
                var url ="https://api.thingspeak.com/channels/3026076/fields/1,2,3,4,5,6,7,8.json?api_key=9ATA4ZAICPKOK1BT&results=1";

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
        
const data41 = parseInt(field1Values);
const data42 = parseInt(field2Values);
const data43 = parseInt(field3Values);
const data44 = parseInt(field4Values);
const data45 = parseInt(field5Values);
const data46 = parseInt(field6Values);
const data47 = parseInt(field7Values);
const data48 = parseInt(field8Values);

document.cookie = "data41="+data41;
document.cookie = "data42="+data42;
document.cookie = "data43="+data43;
document.cookie = "data44="+data44;
document.cookie = "data45="+data45;
document.cookie = "data46="+data46;
document.cookie = "data47="+data47;
document.cookie = "data48="+data48;

console.log(data41);
console.log(data42);
console.log(data43);
console.log(data44);
console.log(data45);
console.log(data46);
console.log(data47);
console.log(data48);

                });


            }
            getData();

        });
