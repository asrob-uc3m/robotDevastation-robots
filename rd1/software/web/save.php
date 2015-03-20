<?php
if(!empty($_POST['robotName'])){
    $data = $_POST['robotName'] . "\n";
    $file = fopen("/home/teo/demo.txt", 'w');//creates new file
    fwrite($file, $data);
    fclose($file);
}
?>
