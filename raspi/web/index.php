<!DOCTYPE html>
<html lang="en">
<head>
</head>
<body>
<h1>
    RD1 Configuration Page
</h1>

<?php
$current = file_get_contents("/home/pi/robotName")  #-- Remember to create and chmod 666 /home/pi/robotName
?>

Robot Name (current): <strong><span id="current"><?php echo $current ?></span></strong><br>
Robot Name (new): <input type="text" id="robotName"><br>
<input type="submit" value="Change robot name" onClick="changeRobotName();">

<script>
function changeRobotName() {
    var robotName = document.getElementById("robotName").value;
    if ( robotName == "" ) {
        alert('Please enter a new robot name.');
        return;
    }
    var res = confirm('Change robot name to ' + robotName + ' ?');
    if (res == false) {
        return;
    }
    var data = new FormData();
    data.append("robotName" , robotName);
    var xhr = (window.XMLHttpRequest) ? new XMLHttpRequest() : new activeXObject("Microsoft.XMLHTTP");
    xhr.open( 'post', 'save.php', true );
    xhr.send(data);
    document.getElementById("current").innerHTML = robotName;
    document.getElementById("robotName").value = '';
    alert('Saved new robot name ' + robotName )
}
</script>

</body>
</html>
