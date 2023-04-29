<!DOCTYPE html>
<html lang="en">
<head>
  <title>Bootstrap Example</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.3/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
  <link rel="stylesheet" href="./style.css">
  <style>
    .error {
	color: red;
	text-align: center;
    }
  </style>
</head>
<body>

<div class="container">


<?php

$server_address = "localhost";
$username = "root";
$password = "";
$database_name = "quest_database";

$conn = new mysqli($server_address, $username, $password);
if($conn->connect_error) die("Connection failed: " . $conn->connect_error);
else echo "Connected Succesfully to mysql! <br>";


$query = "CREATE DATABASE if not EXISTS " . $database_name . " ;";
if($conn->query($query)===TRUE) echo "Created database successfully <br>";
else echo "Failed to create database <br>";

$conn = new mysqli($server_address, $username, $password, $database_name);
if($conn->connect_error) die("Connection error to db: " . conn->connect_error);
else echo "Connected to database " . $database_name . " successfully.<br>";


$query = "create table if not exists quest(
	      quest_id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
       	      quest_title varchar(100),
       	      quest_description varchar(1000),
       	      quest_reward varchar(100),
       	      requiredCultivationBase varchar(150),
	      quest_status varchar(10),
	      quest_submission_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
	    );
";

if($conn->query($query)===TRUE) echo "Successfully created quest table <br>";
else { echo "Error creating quest table!<br>"; }


function addNewQuest($conn, $quest_title, $quest_description, $quest_reward, $requiredCultivationBase){
         $quest_status = "started";
	 $query = "INSERT into quest(quest_title, quest_description, quest_reward, requiredCultivationBase, quest_status) values('" . $quest_title . "','" . $quest_description . "','" . $quest_reward . "','" . $requiredCultivationBase . "','" . $quest_status . "');";

	 if($conn->query($query)===TRUE) echo "Successfully insertet quest in DB <br>";
	 else echo "Error occurred when inserting quest. <br>";
}


//addNewQuest($conn,'a','b','c','d');

function getAllQuests($conn){
	 $query = "select * from quest;";
	 $result = $conn->query($query);

         if($result->num_rows>0){
		echo "<h4>Quests:</h4>";
		echo "<table class='table'>
		     <tr>
			<th> Quest Title </th>
			<th> Quest Reward </th>
			<th> Submission Time </th>
			<th> Action </th>
		     </tr>";
		
		while($row = $result->fetch_assoc()) {
			   echo "<tr>";
			   echo "<td>" . $row["quest_title"] . "</td>";
			   echo "<td>" . $row["quest_reward"] . "</td>";
			   echo "<td>" . $row["quest_submission_time"] . "</td>";
			   echo "<td> <button onclick='acceptQuest()'> Accept Quest </button> </td>";
			   echo "</tr>";
		}
	 	echo "</table>";
	 }else echo "Unable to fetch data from query table!<br>";
}

function acceptQuest(){
	echo "alert('Quest acceptance confirmed!')";
}

//getAllQuests($conn);

?>

</div>


</body>
</html>
