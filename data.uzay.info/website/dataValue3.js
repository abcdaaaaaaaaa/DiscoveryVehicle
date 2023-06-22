        $(document).ready(function() {
            function getData() {
                var url ="https://api.thingspeak.com/channels/2195037/fields/1,2,3,4,5.json?api_key=H9IXGTX44JKNORPW&results=1";

                $.getJSON(url, function(data) {
                    var field1Values = [];
                    var field2Values = [];
                    var field3Values = [];	
                    var field4Values = [];
                    var field5Values = [];								
                    var timestamps = [];

                    $.each(data.feeds, function(index, feed) {
						field1Values.push(feed.field1);
						field2Values.push(feed.field2);
						field3Values.push(feed.field3);
						timestamps.push(feed.created_at);
					});
        
 let toplam15 = parseInt(field1Values);   
 let toplam16 = parseInt(field2Values);   
 let toplam17 = parseInt(field3Values); 
 let toplam19 = parseInt(field4Values);   
 let toplam20 = parseInt(field5Values); 
   
document.cookie = "value15="+toplam15;
document.cookie = "value16="+toplam16;
document.cookie = "value17="+toplam17;
document.cookie = "lat="+toplam19;
document.cookie = "lng="+toplam20;

console.log(toplam15);
console.log(toplam16);
console.log(toplam17);
console.log(toplam19);
console.log(toplam20);

                });


            }
            getData();

        });    