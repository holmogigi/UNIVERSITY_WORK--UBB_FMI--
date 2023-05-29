<?php
session_start();
if (isset($_SESSION['username'])) {
    $username = $_SESSION['username'];
    echo "<script>var username = '" . $username . "';</script>";
} else {
    header('Location: login.php');
    die();
}
if (isset($_POST['returnButton'])) {
    header('Location: home.php');
}
if (isset($_POST['postButton'])) {
    header('Location: add_reservation.php');
}
if (isset($_POST['EDITRES'])) {
    header('Location: editreservation.php');
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
        <title>All your reservations</title> 
    </head>
    <body>
        <br></br>
        <div class="container text-center" id="viewReservationsDiv">
            <div class="container" id="showReservations">
                <h3>All reservations:</h3>
                <table class="reservationtable table">
                    <thead>
                        <tr>
                            <th id="clickable-header">ID</th>
                            <th>Room Number</th>
                            <th>Hotel Name</th>  
                            <th>Start Date</th>
                            <th>End Date</th>
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
                
                <br></br>
                <div id="ADDRES" class="mb-1">
                <form method="post">
                    <input id="postButton" type="submit" class="btn btn-primary mb-1" name="postButton" value="Add reservation">
                </form></div>
                    <br></br>
                    <div id="EDITRES" class="mb-1">
                        <form id="editForm" method="post" action="editreservation.php">
                            <label for="DELETERESinput" class="form-label">Id: </label>
                            <input type="text" id="DELETERESinput" name="id" class="form-control mb-3">
                            <button id="editReservation" type="submit" class="btn btn-primary mb-3">Edit reservation</button>
                        </form>
                    </div>
                    <br></br>
                    <div id="DELETERES" class="mb-1">
                    <form id="deleteForm" method="post"> 
                        <label for="DELETERESinput" class="form-label">Id: </label>
                        <input type="text" id="DELETERESinput" class="form-control mb-3">
                        <button id="DELETERES" type="submit" class="btn btn-primary mb-3">Delete reservation</button>
                    </form>
                    </div>
                <br></br>
                <form method="post">
                    <input id="returnButton" type="submit" class="btn btn-primary mb-1" name="returnButton" value="Return to main page">
                </form>
            </div>
        </div>  
    </body>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js"></script>
    <script src="reservations.js"></script>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script>
        $(document).ready(function() {
            // Attach click event handler to the table body
            $('.reservationtable').on('click', 'tbody tr', function() {
            var id = $(this).find('td:first-child').text(); // Retrieve the ID from the clicked row
            
            // Autocomplete the text boxes with the clicked ID
            $('#EDITRES input').val(id);
            $('#DELETERES input').val(id);
            $('#editForm').submit(function(e) {
                // Prevent the default form submission
                e.preventDefault();

                // Get the entered value
                var id = $('#DELETERESinput').val();
                window.location.href = 'editreservation.php?id=' + id;
                });
            });
            $('#deleteForm').submit(function(e) {
                // Prevent the default form submission
                e.preventDefault();

                // Get the entered value
                var id = $('#DELETERESinput').val();

                $.ajax({
                type: 'GET',
                url: "http://localhost:8080/Hotel_app/DBUtils.php", 
                data: {
                    action: 'deleteReservetion',
                    id: id, 
                },
                success: (data) => {
                    let res = JSON.parse(data);
                    if (res === 0) {
                        alert("Reservation could not be deleted!");
                    } else {
                        $('.form-control').val("");
                        alert("!DELETED!");
                    }
                }
            })
                });
            });
    </script>
</html>
