       $(document).ready(function() {
            function getData() {
                var url ="https://api.thingspeak.com/channels/2479336/fields/1,2,3,4,5,6,7,8.json?api_key=M4PIOKQ7XHF6ZA3R&results=1";

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
        
const data25 = parseInt(field1Values);
const data26 = parseInt(field2Values);
const data27 = parseInt(field3Values);
const data28 = parseInt(field4Values);
const data29 = parseInt(field5Values);
const data30 = parseInt(field6Values);
const data31 = parseInt(field7Values);
const data32 = parseInt(field8Values);

document.cookie = "data25="+data25;
document.cookie = "data26="+data26;
document.cookie = "data27="+data27;
document.cookie = "data28="+data28;
document.cookie = "data29="+data29;
document.cookie = "data30="+data30;
document.cookie = "data31="+data31;
document.cookie = "data32="+data32;

console.log(data25);
console.log(data26);
console.log(data27);
console.log(data28);
console.log(data29);
console.log(data30);
console.log(data31);
console.log(data32);

                });


            }
            getData();

        });
