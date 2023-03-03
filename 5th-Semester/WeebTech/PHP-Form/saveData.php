<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "assignmentDB";

	 $conn = new mysqli($servername, $username, $password);
	 if ($conn->connect_error) {
	   die("Connection failed: " . $conn->connect_error);
	 }
	 echo "Connected successfully <br>";


	 $sql = "CREATE DATABASE if not exists assignmentDB";
	 if ($conn->query($sql) === TRUE) {
	   echo "Database created successfully <br>";
	 } else {
	     echo "Error creating database: " . $conn->error;
	 }
	 $conn->close();


// Create connection to database
$conn = new mysqli($servername, $username, $password, $dbname);
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
} 

$sql = "CREATE TABLE if not exists registrationTable (
id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
firstName VARCHAR(30) NOT NULL,
lastName VARCHAR(30) NOT NULL,
email VARCHAR(50),
address VARCHAR(50),
photo VARCHAR(50),
reg_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
)";

if ($conn->query($sql) === TRUE) {
  echo "Table registrationTable created successfully <br>";
} else {
  echo "Error creating table: " . $conn->error;
}

$sql = "INSERT INTO registrationTable (firstName, lastName, email, address, photo)
VALUES ('John', 'Doe', 'john@example.com', 'London, UK', 'No photo yet')";

if ($conn->query($sql) === TRUE) {
  echo "New record created successfully <br>";
} else {
  echo "Error: " . $sql . "<br>" . $conn->error;
}

/*
$sql = "INSERT INTO registrationTable (firstName, lastName, email, address, photo)
VALUES ('Rahim', 'Vuita', 'rahim@gmail.com', 'Keraniganj, Dhaka', 'No photo yet')";

if ($conn->query($sql) === TRUE) {
  echo "New record created successfully <br>";
} else {
  echo "Error: " . $sql . "<br>" . $conn->error;
}
*/


$sql = "SELECT * FROM registrationTable ORDER BY id DESC LIMIT 1";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
  // output data of each row
  while($row = $result->fetch_assoc()) {
    echo "id: " . $row["id"]. " - Name: " . $row["firstName"]. " " . $row["lastnNme"]. "<br>";
    echo "Email: " . $row["email"]. " - Address: " . $row["address"]. " - Photo: " . $row["photo"]. "<br>";
  }
} else {
  echo "0 results";
}

/* sql to delete a record
$sql = "DELETE FROM registrationTable";

if ($conn->query($sql) === TRUE) {
  echo "Record deleted successfully<br>";
} else {
  echo "Error deleting record: " . $conn->error;
}
*/


$conn->close();

?>