<script src="https://code.jquery.com/jquery-3.7.0.min.js"></script>
<script src="../dataValue1.js"></script>
<script src="../dataValue2.js"></script>    

  <?php
        include_once 'db.php';

        $value1 = $_COOKIE["value1"];
        $value2 = $_COOKIE["value2"];
        $value3 = $_COOKIE["value3"];
        $value4 = $_COOKIE["value4"];
        $value5 = $_COOKIE["value5"];
        $value6 = $_COOKIE["value6"];
        $value7 = $_COOKIE["value7"];
        $char1  = $_COOKIE["value8"];
        $value9 = $_COOKIE["value9"];
        $value10 = $_COOKIE["value10"];
        $value11 = $_COOKIE["value11"];
        $value12 = $_COOKIE["value12"];
        $value13 = $_COOKIE["value13"];
        $value14 = $_COOKIE["value14"];
        $value15 = $_COOKIE["value15"];
        $value16 = $_COOKIE["value16"];

switch ( $char1 ) {

case 1 :
  
$sql = "INSERT INTO MQ135 (CO, Alcohol, CO2, Toluen,  NH4, Aceton, Air, usvhr, Avg1, sdCPM, CPMCount, SpaceData100, SpaceData200, lat, lng)
        VALUES ('" . $value1 . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value7 . "', '" . $value9 . "', '" . $value10 . "', '" . $value11 . "', '" . $value12 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "', '" . $value16 . "')";
break;

case 2 :
  
$sql = "INSERT INTO MQ2 (H2, LPG, CO, Alcohol, Propane, Air, usvhr, Avg1, sdCPM, CPMCount, SpaceData100, SpaceData200, lat, lng)
        VALUES ('" . $value1 . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "',  '" . $value9 . "', '" . $value10 . "', '" . $value11 . "', '" . $value12 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "', '" . $value16 . "')";
break;

case 3 :
  
$sql = "INSERT INTO MQ3 (LPG, CH4, CO, Alcohol, Benzene, Hexane, Air, usvhr, Avg1, sdCPM, CPMCount, SpaceData100, SpaceData200, lat, lng)
        VALUES ('" . $value1 . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value7 . "', '" . $value9 . "', '" . $value10 . "', '" . $value11 . "', '" . $value12 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "', '" . $value16 . "')";
break;

case 4 :
  
$sql = "INSERT INTO MQ4 (LPG, CH4, CO, Alcohol, Smoke, Air, usvhr, Avg1, sdCPM, CPMCount, SpaceData100, SpaceData200, lat, lng)
        VALUES ('" . $value1 . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value9 . "', '" . $value10 . "', '" . $value11 . "', '" . $value12 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "', '" . $value16 . "')";
break;

case 5 :
  
$sql = "INSERT INTO MQ5 (H2, LPG, CH4, CO,  Alcohol, Air, usvhr, Avg1, sdCPM, CPMCount, SpaceData100, SpaceData200, lat, lng)
        VALUES ('" . $value1 . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value9 . "', '" . $value10 . "', '" . $value11 . "', '" . $value12 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "', '" . $value16 . "')";
break;

case 6 :
  
$sql = "INSERT INTO MQ6 (H2, LPG, CH4, CO,  Alcohol, Air, usvhr, Avg1, sdCPM, CPMCount, SpaceData100, SpaceData200, lat, lng)
        VALUES ('" . $value1 . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value9 . "', '" . $value10 . "', '" . $value11 . "', '" . $value12 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "', '" . $value16 . "')";
break;

case 7 :
  
$sql = "INSERT INTO MQ7 (H2, LPG, CH4, CO,  Alcohol, Air, usvhr, Avg1, sdCPM, CPMCount, SpaceData100, SpaceData200, lat, lng)
        VALUES ('" . $value1 . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value9 . "', '" . $value10 . "', '" . $value11 . "', '" . $value12 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "', '" . $value16 . "')";
break;

case 8 :
  
$sql = "INSERT INTO MQ8 (H2, LPG, CH4, CO,  Alcohol, Air, usvhr, Avg1, sdCPM, CPMCount, SpaceData100, SpaceData200, lat, lng)
        VALUES ('" . $value1 . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value9 . "', '" . $value10 . "', '" . $value11 . "', '" . $value12 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "', '" . $value16 . "')";
break;

case 9 :
  
$sql = "INSERT INTO MQ9 (LPG, CH4, CO, Air, usvhr, Avg1, sdCPM, CPMCount, SpaceData100, SpaceData200, lat, lng)
        VALUES ('" . $value1 . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value9 . "', '" . $value10 . "', '" . $value11 . "', '" . $value12 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "', '" . $value16 . "')";
break;

case 10 :
  
$sql = "INSERT INTO MQ131 (NOx, CL2, O3, Air, usvhr, Avg1, sdCPM, CPMCount, SpaceData100, SpaceData200, lat, lng)
        VALUES ('" . $value1 . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value9 . "', '" . $value10 . "', '" . $value11 . "', '" . $value12 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "', '" . $value16 . "')";
break;

case 11 :
  
$sql = "INSERT INTO MQ136 (H2S, NH4, CO, Air, usvhr, Avg1, sdCPM, CPMCount, SpaceData100, SpaceData200, lat, lng)
        VALUES ('" . $value1 . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value9 . "', '" . $value10 . "', '" . $value11 . "', '" . $value12 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "', '" . $value16 . "')";
break;

case 12 :
  
$sql = "INSERT INTO MQ303A (Isobutane, Hydrogen, Ethanol, Air, usvhr, Avg1, sdCPM, CPMCount, SpaceData100, SpaceData200, lat, lng)
        VALUES ('" . $value1 . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value9 . "', '" . $value10 . "', '" . $value11 . "', '" . $value12 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "', '" . $value16 . "')";
break;

case 13 :
  
$sql = "INSERT INTO MQ309A (H2, CH4, CO, Alcohol, Air, usvhr, Avg1, sdCPM, CPMCount, SpaceData100, SpaceData200, lat, lng)
        VALUES ('" . $value1 . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value9 . "', '" . $value10 . "', '" . $value11 . "', '" . $value12 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "', '" . $value16 . "')";
break;

default:
  
$sql = "INSERT INTO MQ135 (CO, Alcohol, CO2, Toluen,  NH4, Aceton, Air, usvhr, Avg1, sdCPM, CPMCount, SpaceData100, SpaceData200, lat, lng)
        VALUES ('" . $value1 . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value7 . "', '" . $value9 . "', '" . $value10 . "', '" . $value11 . "', '" . $value12 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "', '" . $value16 . "')";
break;

}
 
        if ($conn->query($sql) === TRUE) {
        } 
        else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
    
        $conn->close();

?>   
