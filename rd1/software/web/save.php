<?php
if(!empty($_POST['robotName'])){
    $data = $_POST['robotName'] . "\n";
    $file = fopen("/home/yo/demo.txt", 'w');
    fwrite($file, $data);
    fclose($file);
}
?>
