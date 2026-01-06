  $(document).ready(function() {
        function getData() {
            var url ="https://api.thingspeak.com/channels/2169907/fields/1,2,3,4,5,6,7.json?api_key=AL0IDSI4FU59TFXT&results=1";

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
    
                const toplam1 = parseInt(field1Values);   
                const toplam2 = parseInt(field2Values);   
                const toplam3 = parseInt(field3Values);
                const toplam4 = parseInt(field4Values);   
                const toplam5 = parseInt(field5Values);   
                const toplam6 = parseInt(field6Values);
                const toplam7 = parseInt(field7Values);   

                document.cookie = "toplam1="+toplam1; // SensorMode
                document.cookie = "toplam2="+toplam2; // SensorPer
                document.cookie = "toplam3="+toplam3; // temp
                document.cookie = "toplam4="+toplam4; // rh
                document.cookie = "toplam5="+toplam5; // SensorPer2
                document.cookie = "value14="+toplam6; // lat
                document.cookie = "value15="+toplam7; // lng

            });


        }
        getData();

    });