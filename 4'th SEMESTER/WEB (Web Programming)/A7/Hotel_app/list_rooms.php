<?php
session_start();
if (isset($_SESSION['username'])) {
    $username = $_SESSION['username'];
} else {
    header('Location: login.php');
    die();
}
if (isset($_POST['returnButton'])) {
    header('Location: home.php');
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
        <title>All rooms</title> 
    </head>
    <body>
        <br></br>
        <div class="container text-center" id="viewRoomsDiv">
            <div class="container" id="showRooms">
                <h3>All rooms:</h3>
                <table class="roomtable table">
                    <thead>
                        <tr>
                            <th>ID</th>
                            <th>Hotel ID</th>
                            <th>Room number</th>
                            <th>Category</th>
                            <th>Price</th>
                        </tr>
                    </thead>
                    <tbody>
                    </tbody>
                </table>
            </div>
            <div id="buttons" class="container text-center">
                <button type="button" id="previousButton" class="btn btn-primary mb-1">Previous</button>
                <button id="nextButton" type="button" class="btn btn-primary mb-1">Next</button>
                <br></br>
                <button id="allLogsButton" type="button" class="btn btn-primary mb-1">Show All</button>
                <br></br>
                <div id="filterByCategory" class="mb-1">
                    <label for="categoryInputFilter" class="form-label">Category: </label><input type="text" id="categoryInputFilter" class="form-control mb-3">
                    <button id="filterByCategoryButton" type="button" class="btn btn-primary">Filter by category</button>
                </div>
                <br></br>
                <div id="filterByPrice" class="mb-1">
                    <label for="priceInputFilter" class="form-label">Price: </label><input type="text" id="priceInputFilter" class="form-control mb-3">
                    <button id="filterByPriceButton" type="button" class="btn btn-primary mb-3">Filter by price</button>
                </div>
                <br></br>
                <br></br>
                <br></br>
                <form method="post">
                    <input id="returnButton" type="submit" class="btn btn-primary mb-1" name="returnButton" value="Return to main page">
                </form>
            </div>
        </div>  
    </body>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js"></script>
    <script src="rooms_script.js"></script>
</html>