<?php
if(!empty($_POST['robotName'])){
    $data = $_POST['robotName'] . "\n";
    $file = fopen("/home/pi/robotName", 'w');  #-- Remember to create and chmod 666 /home/pi/robotName
    fwrite($file, $data);
    fclose($file);
}
?>
