<?php
if(!empty($_POST['robotName'])){
    $data = $_POST['robotName'] . "\n";
    $file = fopen("/home/pi/rd1.config", 'w');
    fwrite($file, $data);
    fclose($file);
}
?>
