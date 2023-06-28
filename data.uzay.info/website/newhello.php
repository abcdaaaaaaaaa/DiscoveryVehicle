<script src="https://code.jquery.com/jquery-3.7.0.min.js"></script>
<script src="../dataValue1.js"></script>
<script src="../dataValue2.js"></script>    
<script src="../dataValue3.js"></script>  

  <?php
        include_once 'db.php';

        $value1 = $_COOKIE["value1"];
        $value2 = $_COOKIE["value2"];
        $value3 = $_COOKIE["value3"];
        $value4 = $_COOKIE["value4"];
        $value5 = $_COOKIE["value5"];
        $value6 = $_COOKIE["value6"];
        $value7 = $_COOKIE["value7"];
        $value8 = $_COOKIE["value8"];
        $value9 = $_COOKIE["value9"];
        $value10 = $_COOKIE["value10"];
        $value11 = $_COOKIE["value11"];
        $value12 = $_COOKIE["value12"];
        $value13 = $_COOKIE["value13"];
        $value14 = $_COOKIE["value14"];
        $value15 = $_COOKIE["value15"];
        $value16 = $_COOKIE["value16"];
        $value17 = $_COOKIE["value17"];
        $value18 = $_COOKIE["value18"];
        $value19 = $_COOKIE["value19"];
        $MQ135 = $value14; 
        $MQ2 = $_COOKIE["MQ2"];
        $MQ3 = $_COOKIE["MQ3"];
        $MQ4 = $_COOKIE["MQ4"];
        $lat = $_COOKIE["lat"];
        $lng = $_COOKIE["lng"];

$sql = "INSERT INTO SensorData (Alcohol, Benzene, Hexane, CH4,  Smoke, CO2, Toluen, NH4, Aceton, LPG, Propane, CO, H2, Air, Avg1, sdCPM, Arrayval, SpaceData100, SpaceData200, MQ135, MQ2, MQ3, MQ4, lat, lng)
        VALUES ('" . $value1 . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value7 . "', '" . $value8 . "', '" . $value9 . "', '" . $value10 . "', '" . $value11 . "', '" . $value12 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "', '" . $value16 . "', '" . $value17 . "', '" . $value18 . "', '" . $value19 . "',  '" . $MQ135 . "', '" . $MQ2 . "', '" . $MQ3 . "', '" . $MQ4 . "', '" . $lat . "', '" . $lng . "')";
        
        if ($conn->query($sql) === TRUE) {
        } 
        else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
    
        $conn->close();

?>   