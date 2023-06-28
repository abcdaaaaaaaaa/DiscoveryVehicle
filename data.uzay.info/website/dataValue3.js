        $(document).ready(function() {
            function getData() {
                var url ="https://api.thingspeak.com/channels/2195037/fields/1,2,3,4,5,6,7,8.json?api_key=H9IXGTX44JKNORPW&results=1";

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
        
 let toplam15 = parseInt(field1Values);   
 let toplam16 = parseInt(field2Values);   
 let toplam17 = parseInt(field3Values); 
 let toplam19 = parseInt(field4Values);   
 let toplam20 = parseInt(field5Values); 
 let toplam21 = parseInt(field6Values); 
 let toplam22 = parseInt(field7Values); 
 let toplam23 = parseInt(field8Values); 
   
document.cookie = "value15="+toplam15;
document.cookie = "value16="+toplam16;
document.cookie = "value17="+toplam17;
document.cookie = "lat="+toplam19;
document.cookie = "lng="+toplam20;
document.cookie = "MQ2="+toplam21;
document.cookie = "MQ3="+toplam22;
document.cookie = "MQ4="+toplam23;

console.log(toplam15);
console.log(toplam16);
console.log(toplam17);
console.log(toplam19);
console.log(toplam20);
console.log(toplam21);
console.log(toplam22);
console.log(toplam23);

                });


            }
            getData();

        });    