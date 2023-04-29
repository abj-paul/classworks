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
    <h1> Submit New Quest For Adventurers: </h1>
    <form action="/quest-submission.php" class="questForm" method="GET">
        <input type="text" class="form-control" placeholder="Quest Title" name="quest_title"/>
        <input type="text" class="form-control" placeholder="Quest Description" name="quest_description"/>
        <select class="form-select" name="requiredCultivationBase"> 
          <option value="qiGatheringStage"> Qi Gathering Stage </option>
          <option value="formationBuildingStage"> Foundation Building Stage </option>
          <option value="coreFormationStage"> Core Formation Stage </option>
          <option value="nascentSoulStage"> Nascent Soul Stage </option>
          <option value="worldMergingStage"> World Merging Stage </option>
          <option value="immortalAscensionStage"> Immortal Ascension Stage </option>
        </select>
        <input type="text" class="form-control" placeholder="Quest Reward" name="quest_reward"/>
        <button type="submit" class="btn btn-primary"> Submit Quest </button>
    </form>
</div>


</body>
</html>
