<!DOCTYPE html>
<html lang="en">
<head>
  <title>Bootstrap Example</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.3/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>

  <style>
    .error {
	color: red;
	text-align: center;
    }
  </style>
</head>
<body>

<div class="container">
  <h2>Registration</h2>
  <form class="form-horizontal" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" method="POST">
    <div class="form-group">
      <label class="control-label col-sm-2" for="firstNameId">First Name:</label>
      <div class="col-sm-8">
        <input type="text" class="form-control" id="firstNameId" placeholder="Enter First Name" name="firstName"> 
      </div>
      <span class="error col-sm-2"><?php echo $firstNameErr;?></span>
    </div>
    <div class="form-group">
      <label class="control-label col-sm-2" for="lastNameId">Last Name:</label>
      <div class="col-sm-8">
        <input type="text" class="form-control" id="lastNameId" placeholder="Enter Last Name" name="lastName">
      </div>
      <span class="error col-sm-2"><?php echo $lastNameErr;?></span>
    </div>

    <div class="form-group">
      <label class="control-label col-sm-2" for="emailId">Email:</label>
      <div class="col-sm-8">          
        <input type="email" class="form-control" id="emailId" placeholder="Enter email" name="email">
      </div>
      <span class="error col-sm-2"><?php echo $emailErr;?></span>
    </div>

    <div class="form-group">
      <label class="control-label col-sm-2" for="addressId">Address:</label>
      <div class="col-sm-8">          
        <input type="text" class="form-control" id="addressId" placeholder="Enter address" name="address">
      </div>
      <span class="error col-sm-2"><?php echo $addressErr;?></span>
    </div>

    <div class="form-group">
      <label class="control-label col-sm-2" for="photoId">Photo:</label>
      <div class="col-sm-8">          
        <input type="text" class="form-control" id="photoId" placeholder="Enter photo" name="photo">
      </div>
      <span class="error col-sm-2"><?php echo $photoErr;?></span>
    </div>

    <div class="form-group">        
      <div class="col-sm-offset-2 col-sm-10">
        <button type="submit" class="btn btn-default">Submit</button>
      </div>
    </div>
  </form>
</div>



<?php 

include "handleForm.php";
include "saveData.php";

if($firstNameErr == "" && $emailErr == "" && $addressErr == "" ){
    header('Location: submission.php');
    exit();
} ?>


</body>
</html>
