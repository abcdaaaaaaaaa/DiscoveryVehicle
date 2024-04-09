       $(document).ready(function() {
            function getData() {
                var url ="https://api.thingspeak.com/channels/2479336/fields/1,2,3.json?api_key=M4PIOKQ7XHF6ZA3R&results=1";

                $.getJSON(url, function(data) {
                    var field1Values = [];
                    var field2Values = [];
                    var field3Values = [];
                    var timestamps = [];

                    $.each(data.feeds, function(index, feed) {
						field1Values.push(feed.field1);
						field2Values.push(feed.field2);
						field3Values.push(feed.field3);
						timestamps.push(feed.created_at);
					});
        
const data25 = parseInt(field1Values);   
const data26 = parseInt(field2Values);   
const data27 = parseInt(field3Values);   

document.cookie = "data25="+data25;
document.cookie = "data26="+data26;
document.cookie = "data27="+data27;

console.log(data25);
console.log(data26);
console.log(data27);

                });


            }
            getData();

        });
