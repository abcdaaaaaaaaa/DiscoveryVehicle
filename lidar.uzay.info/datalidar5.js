       $(document).ready(function() {
            function getData() {
                var url ="https://api.thingspeak.com/channels/2248096/fields/1,2,3,4,5,6,7,8.json?api_key=V8217HGH2YKR9ZIK&results=1";

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
        
const data17 = parseInt(field1Values);   
const data18 = parseInt(field2Values);   
const data19 = parseInt(field3Values);   
const data20 = parseInt(field4Values);   
const data21 = parseInt(field5Values);   
const data22 = parseInt(field6Values);
const data23 = parseInt(field7Values);   
const data24 = parseInt(field8Values);   

document.cookie = "data17="+data17;
document.cookie = "data18="+data18;
document.cookie = "data19="+data19;
document.cookie = "data20="+data20;
document.cookie = "data21="+data21;
document.cookie = "data22="+data22;
document.cookie = "data23="+data23;
document.cookie = "data24="+data24;

console.log(data17);
console.log(data18);
console.log(data19);
console.log(data20);
console.log(data21);
console.log(data22);
console.log(data23);
console.log(data24);

                });


            }
            getData();

        });
