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
    if($_SERVER["REQUEST_METHOD"]=="GET") {
        $quest_title = $_GET["quest_title"];
        $quest_description = $_GET["quest_description"];
        $requiredCultivationBase = $_GET["requiredCultivationBase"];
        $quest_reward = $_GET["quest_reward"];
	
        echo $quest_title . $quest_description . $requiredCultivationBase . $quest_reward;
	
	require "save_quest.php";
	
	addNewQuest($conn, $quest_title, $quest_description, $quest_reward, $requiredCultivationBase);
	getAllQuests($conn);
    }
?>

</div>


</body>
</html>
