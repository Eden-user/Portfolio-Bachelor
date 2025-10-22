<?php 
$read=file_get_contents('cv.php') . file_get_contents('header.php');
$count = strlen($read);
echo $count; 
?>
