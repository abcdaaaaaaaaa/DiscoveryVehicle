       $(document).ready(function() {
            function getData() {
                var url ="https://api.thingspeak.com/channels/3026070/fields/1,2,3,4,5,6,7,8.json?api_key=RJ4Z9J79OHW8TVWB&results=1";

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
        
const data33 = parseInt(field1Values);
const data34 = parseInt(field2Values);
const data35 = parseInt(field3Values);
const data36 = parseInt(field4Values);
const data37 = parseInt(field5Values);
const data38 = parseInt(field6Values);
const data39 = parseInt(field7Values);
const data40 = parseInt(field8Values);

document.cookie = "data33="+data33;
document.cookie = "data34="+data34;
document.cookie = "data35="+data35;
document.cookie = "data36="+data36;
document.cookie = "data37="+data37;
document.cookie = "data38="+data38;
document.cookie = "data39="+data39;
document.cookie = "data40="+data40;

console.log(data33);
console.log(data34);
console.log(data35);
console.log(data36);
console.log(data37);
console.log(data38);
console.log(data39);
console.log(data40);

                });


            }
            getData();

        });
