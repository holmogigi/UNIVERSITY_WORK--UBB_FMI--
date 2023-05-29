<?php
session_start();
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
        <title>All hotels</title> 
    </head>
    <body>
        <br></br>
        <div class="container text-center" id="viewLogsDiv">
            <div class="container" id="showLogs">
                <h3>All hotels:</h3>
                <table class="logTable table">
                    <thead>
                        <tr>
                            <th>ID</th>
                            <th>Name</th>
                            <th>Address</th>
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
                <div id="filterByName" class="mb-1">
                    <label for="nameInputFilter" class="form-label">Name: </label><input type="text" id="nameInputFilter" class="form-control mb-3">
                    <button id="filterByNameButton" type="button" class="btn btn-primary">Filter by name</button>
                </div>
                <br></br>
                <div id="filterByAddress" class="mb-1">
                    <label for="addressInputFilter" class="form-label">Address: </label><input type="text" id="addressInputFilter" class="form-control mb-3">
                    <button id="filterByAddressButton" type="button" class="btn btn-primary mb-3">Filter by address</button>
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
    <script src="hotels_script.js"></script>
</html>