<?php
session_start();
if (!isset($_SESSION['username'])) {
    header('Location: login.php');
}
if (isset($_POST['returnButton'])) {
    header('Location: home.php');
}
if (isset($_POST['viewAllButton'])) {
    header('Location: list_rooms.php');
}
?>

<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
        <link rel="stylesheet" href="style.css">
        <title>Add a room</title> 
    </head>
    <body>
    <div class="container text-center" id="addFormDiv">
            <div id="addForm">
                <br></br>
                <h5>Add a room</h5>
                <br></br>
                <div class="mb-1"><label for="typeField" class="form-label">Hotel ID: </label><input type="text" id="typeField" class="form-control"></div>
                <div class="mb-1"><label for="severityField" class="form-label">Room Number: </label><input type="text" id="severityField" class="form-control"></div>
                <div class="mb-1"><label for="typeField1" class="form-label">Category: </label><input type="text" id="typeField1" class="form-control"></div>
                <div class="mb-1"><label for="severityField1" class="form-label">Price: </label><input type="text" id="severityField1" class="form-control"></div>
                <button id="insertLogButton" type="button" class="btn btn-primary mb-1">Add room</button>
            </div>
            <br></br>
            <form method="post">
                <input type="submit" class="btn btn-primary mb-1" name="viewAllButton" value="View all rooms">
                <input type="submit" class="btn btn-primary mb-1" name="returnButton" value="Return to main page">
            </form>
        </div> 
    </div> 
    </body>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js"></script>
    <script src="add_script_rooms.js"></script>
</html>