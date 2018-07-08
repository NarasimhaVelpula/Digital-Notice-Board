<?php
include "config.php";
$query="select curdate()";
	$sql=mysqli_query($con,$query);
	$data=mysqli_fetch_array($sql);
	$date=$data['curdate()'];
	echo $date;

	
	$query="select dayname('$date') as day;";
	$sql=mysqli_query($con,$query);
	$data=mysqli_fetch_array($sql);
	$date=$data['day'];
	echo $date;
	$query="select * from notice";
	$sql=mysqli_query($con,$query);
	$data=mysqli_fetch_array($sql);
	echo $data['msg'];
?>