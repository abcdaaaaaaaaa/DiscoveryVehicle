$(document).ready(function() {
    function getData() {
        var url = "https://api.thingspeak.com/channels/2195036/fields/1,2,3,4.json?api_key=DG5Q1OBE0MW2GDTF&results=1";

        $.getJSON(url, function(data) {
            var field1Values = [];
            var field2Values = [];
            var field3Values = [];
            var field4Values = [];
            var timestamps = [];

            $.each(data.feeds, function(index, feed) {
                field1Values.push(feed.field1);
                field2Values.push(feed.field2);
                field3Values.push(feed.field3);
                field4Values.push(feed.field4);
                // timestamps.push(feed.created_at);
	            timestamps.push(feed.created_at.substring(11, 19)); 
            });

            const toplam1 = parseInt(field1Values);
            const toplam2 = parseInt(field2Values);
            const toplam3 = parseInt(field3Values);
            const toplam4 = parseInt(field4Values);

            document.cookie = "toplam1="+toplam1; // Usv/hr
            document.cookie = "toplam2="+toplam2; // Avg
            document.cookie = "toplam3="+toplam3; // SdCPM
            document.cookie = "toplam4="+toplam4; // CPM Count
            
            console.log(toplam1);
            console.log(toplam2);
            console.log(toplam3);
            console.log(toplam4);


        });
    }

    getData();
});
