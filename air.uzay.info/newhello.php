<script src="https://code.jquery.com/jquery-3.7.0.min.js"></script>
<script src="../datavalue.js"></script>
<script type="module" src="../data.js"></script>


  <?php
        include_once 'db.php';
        
        $toplam1 = $_COOKIE["toplam1"];
        $toplam2 = $_COOKIE["toplam2"];
        $toplam3 = $_COOKIE["toplam3"];
        $toplam4 = $_COOKIE["toplam4"];
        $toplam5 = $_COOKIE["toplam5"];
        $value2 = $_COOKIE["value2"];
        $value3 = $_COOKIE["value3"];
        $value4 = $_COOKIE["value4"];
        $value5 = $_COOKIE["value5"];
        $value6 = $_COOKIE["value6"];
        $value7 = $_COOKIE["value7"];
        $value8 = $_COOKIE["value8"];
        $value9 = $_COOKIE["value9"];
        $value10 = $_COOKIE["value10"];
        $DHT = ($_COOKIE["value11"]) . '°C %' . ($_COOKIE["value12"]);
        $value13 = $_COOKIE["value13"];
        $value14 = $_COOKIE["value14"] * pow(10,-7) - 90;
        $value15 = $_COOKIE["value15"] * pow(10,-7) - 180;
        
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {

            switch ($toplam1) {
            
            case 1 :
              
            $sql = "INSERT INTO MQ135 (DHT, SpaceData100, Air, Acetone, Toluene, Alcohol, CO2, NH4, CO, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value7 . "', '" . $value8 . "', '" . $value9 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;
            
            case 2 :
              
            $sql = "INSERT INTO MQ2 (DHT, SpaceData100, Air, LPG, propane, H2, alcohol, CH4, smoke, CO, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value7 . "', '" . $value8 . "', '" . $value9 . "', '" . $value10 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;
            
            case 3 :
              
            $sql = "INSERT INTO MQ3 (DHT, SpaceData100, Air, Alcohol, Benzene, Hexane, LPG, CO, CH4, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value7 . "', '" . $value8 . "', '" . $value9 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;
            
            case 4 :
              
            $sql = "INSERT INTO MQ4 (DHT, SpaceData100, Air, CH4, LPG, H2, smoke, alcohol, CO, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value7 . "', '" . $value8 . "', '" . $value9 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;
            
            case 5 :
              
            $sql = "INSERT INTO MQ5 (DHT, SpaceData100, Air, LPG, CH4, H2, alcohol, CO, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value7 . "', '" . $value8 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;
            
            case 6 :
              
            $sql = "INSERT INTO MQ6 (DHT, SpaceData100, Air, LPG, CH4, H2, Alcohol, CO, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value7 . "', '" . $value8 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;
            
            case 7 :
              
            $sql = "INSERT INTO MQ7 (DHT, SpaceData100, Air, H2, CO, LPG, CH4, Alcohol, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value7 . "', '" . $value8 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;
            
            case 8 :
              
            $sql = "INSERT INTO MQ8 (DHT, SpaceData100, Air, H2, alcohol, LPG, CH4, CO, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value7 . "', '" . $value8 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;
            
            case 9 :
              
            $sql = "INSERT INTO MQ9 (DHT, SpaceData100, Air, CO, LPG, CH4, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;
            
            case 10 :
              
            $sql = "INSERT INTO MQ131 (DHT, SpaceData100, Air, O3, CL2, NOx, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;

            case 11 :
              
            $sql = "INSERT INTO MQ131L (DHT, SpaceData100, Air, O3, CL2, NOx, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;
            
            case 12 :
              
            $sql = "INSERT INTO MQ136 (DHT, SpaceData100, Air, H2S, NH4, CO, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;
            
            case 13 :
              
            $sql = "INSERT INTO MQ137 (DHT, SpaceData100, Air, CO, Ethanol, NH3, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;
            
            case 14 :
              
            $sql = "INSERT INTO MQ138 (DHT, SpaceData100, Air, n_Hexane, propane, Benzene, alcohol, CH4, smoke, CO, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value7 . "', '" . $value8 . "', '" . $value9 . "', '" . $value10 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;
            
            case 15 :
              
            $sql = "INSERT INTO MQ214 (DHT, SpaceData100, Air, CH4, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;
            
            case 16 :
              
            $sql = "INSERT INTO MQ216 (DHT, SpaceData100, Air, LPG, propane, i_butane, alcohol, CH4, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value7 . "', '" . $value8 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;
            
            case 17 :
                
            $sql = "INSERT INTO MQ303A (DHT, SpaceData100, Air, Hydrogen, Ethanol, IsoButane, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;
            
            case 18 :
                
            $sql = "INSERT INTO MQ303B (DHT, SpaceData100, Air, Hydrogen, Ethanol, IsoButane, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;
            
            case 19 :
              
            $sql = "INSERT INTO MQ306A (DHT, SpaceData100, Air, Ethanol, Hydrogen, Methane, IsoButane, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value7 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;
            
            case 20 :
              
            $sql = "INSERT INTO MQ307A (DHT, SpaceData100, CO, H2, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value4 . "', '" . $value5 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;
              
            case 21 :
              
            $sql = "INSERT INTO MQ309A (DHT, SpaceData100, Air, H2, CH4, alcohol, CO, SpaceData200, lat, lng)
                    VALUES ('" . $DHT . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value7 . "', '" . $value13 . "', '" . $value14 . "', '" . $value15 . "')";
            break;
            }
             
                    if ($conn->query($sql) === TRUE) {
                    } 
                    else {
                        echo "Error: " . $sql . "<br>" . $conn->error;
                    }
                
                    $conn->close();
            }
?>   
