<?php
include "config.php";
?>


<html lang="en">
<head>
<link href="css/bootstrap.css" rel="stylesheet" type="text/css" />
<link href="css/bootstrap.min.css" rel="stylesheet" type="text/css" />
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
<title>

School Notice Board
</title>
<h2><center style="color:blue;font-size:xx-large;">ADITYA ENGINEERING COLLEGE </center></h2>
</head>
<body style="background: linear-gradient(white,white,white,yellow); font-size:150% "><center>

<form action="" method="post" >

  ENTER NOTICE:
  <textarea  rows="3" cols="20" id="comment" name="msg"  required></textarea>
</br>
</br>
<div class="col-sm-6" style="background-color:white"></div>
<div class="col-sm-1" >
<button name="submit" class="btn btn-success" type="submit" value="submit"  >click to Submit </button>
</div>
	</center>
</form>

<marquee style="color:green; font-size:150%;"><h2> SMART NOTICE BOARD </h2></marquee>
<a href="show.php" style="color:red; font-size:150%" accesskey="h">click here to see whats displaying on notice board </a>

<div style="position: fixed;
    bottom: 30%;
    left: 10;
    width: 500px;">

PROJECT GUIDE: K.H.K prasad(M.tech) 
</div>
<div style="position: fixed;
    bottom:30%;
    right: 0;
    width: 280px;">
PROJECT LEADER:B.Devi Manikanta</br>
MEMBER:V.NARASIMHA</br>
MEMBER:ALEX PRIYATHAM</br>
MEMBER:GIRISH</br>

MEMEBER:MANITEJA

</div>
<div style="position:absolute; bottom:20%; left:40%; width:50%;">

	
contact info: 
&emsp;email:naninarasimha27@gmail.com</br>
phone:9949911067
</div>


</body>
</html>
<?php
if(isset($_POST['submit']))
{
	$msg=$_POST['msg'];
	
	$query="update notice set msg='$msg' where `s.no`=1";
	$sql=mysqli_query($con,$query);
	if($sql)
	{echo "<script>
		alert('submitted successfully')</script>";
	}
}
?>
