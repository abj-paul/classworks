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

/*
  echo "Successfully got the data!";
  echo $firstName , $lastName , $email , $address , $photo;
*/
}

?>