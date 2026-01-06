<script src="https://code.jquery.com/jquery-3.7.0.min.js"></script>
<script src="../datavalue.js"></script>

  <?php
        include_once 'db.php';
        
        $toplam1 = $_COOKIE["toplam1"] / pow(10, 4);
        $toplam2 = $_COOKIE["toplam2"] / pow(10, 4);
        $toplam3 = $_COOKIE["toplam3"] / pow(10, 4);
        $toplam4 = $_COOKIE["toplam4"];
        
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {

    
            $sql = "INSERT INTO Radioactive (Usv_hr, Avg1, sdCPM, CPMCount)
            VALUES ('" . $toplam1 . "', '" . $toplam2 . "', '" . $toplam3 . "', '" . $toplam4 . "')";


         
            if ($conn->query($sql) === TRUE) {
            } 
            else {
                echo "Error: " . $sql . "<br>" . $conn->error;
            }
        
            $conn->close();
        }
?>   