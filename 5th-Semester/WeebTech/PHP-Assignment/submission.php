<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.3/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
<style>
.myRow {
     padding: 10px;
     background-color: yellow; 
     border-bottom: 2px solid black;
}
img{height: 300px;}
</style>
<title></title>
</head>
<body>
	
<div class="container">
<?php 
function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}

$firstName = $lastName = $email = $address = $photo = "";
$firstNameErr = $lastNameErr = $emailErr = $addressErr = $photoErr = "";


if ($_SERVER["REQUEST_METHOD"] == "POST") {

  if (empty($_POST["firstName"])) {
    $firstNameErr = "First Name is required";
  } else {
    $firstName = test_input($_POST["firstName"]);
    if (!preg_match("/^[a-zA-Z-' ]*$/",$firstName)) {
      $firstNameErr = "Only letters and white space allowed";
    }
  }

  if (empty($_POST["lastName"])) {
     $lastName = "";
  } else {
    $lastName = test_input($_POST["lastName"]);
    if (!preg_match("/^[a-zA-Z-' ]*$/",$lastName)) {
      $lastNameErr = "Only letters and white space allowed";
    }
  }

  
  if (empty($_POST["email"])) {
    $emailErr = "Email is required";
  } else {
    $email = test_input($_POST["email"]);
    if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
      $emailErr = "Invalid email format";
    }
  }

  if (empty($_POST["address"])) {
    $addressErr = "Address is required";
  } else {
    $address = test_input($_POST["address"]);
    if (!preg_match("/^[a-zA-Z-' ,]*$/",$address)) {
      $addressErr = "Only letters and white space allowed";
    }
  }
  $photo = $_POST["photo"];
}
?>

     <div class="row">
     <div class="col-sm-7">
<h1> Registration Submitted. </h1>
<?php 
if($firstNameErr == "" && $emailErr == "" && $addressErr == "" ){
        
	echo "<div class='myRow'>First Name: " . $firstName . "</div>";
	echo "<div class='myRow'>Last Name: " . $lastName . "</div>";
	echo "<div class='myRow'>Email: " . $email . "</div>";
	echo "<div class='myRow'>Address: " . $address . "</div>";

}else{
	echo "Please fill up all the fields!";
	exit();
}

?>
	</div>
     <div class="col-sm-5">

<?php 
echo  "<img src='" . $photo . "'>";
?>
	</div>
</div>
</body>
</html>