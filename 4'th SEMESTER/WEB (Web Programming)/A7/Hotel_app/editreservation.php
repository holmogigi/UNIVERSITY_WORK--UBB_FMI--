<?php
// Check if the ID parameter is set
if (isset($_GET['id'])) {
  // Get the ID value
  $id = $_GET['id'];
}

if (isset($_POST['returnButton'])) {
    header('Location: home.php');
}
if (isset($_POST['viewAllButton'])) {
    header('Location: reservations.php');
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
        <title>Edit reservation</title> 
    </head>
    <body>
    <div class="container text-center" id="addFormDiv">
            <div id="addForm">
                <br></br>
                <h5>Edit a reservation</h5>
                <br></br>
                <div class="mb-1"><label for="startDate" class="form-label">Start Date: </label><input type="text" id="startDate" class="form-control"></div>
                <div class="mb-1"><label for="endDate" class="form-label">End Date: </label><input type="text" id="endDate" class="form-control"></div>
                <button id="insertLogButton" type="button" class="btn btn-primary mb-1">Edit</button>
            </div>
            <br></br>
            <form method="post">
                <input type="submit" class="btn btn-primary mb-1" name="viewAllButton" value="View all reservations">
                <input type="submit" class="btn btn-primary mb-1" name="returnButton" value="Return to main page">
            </form>
        </div> 
    </div> 
    </body>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js"></script>
    <script src="add_script_reservations.js"></script>

    <script>
        $('#insertLogButton').click(() => {
        let start_date = $('#startDate').val();
        let end_date = $('#endDate').val();
        const urlParams = new URLSearchParams(window.location.search);
        let id = urlParams.get('id');

        if (start_date.trim().length && end_date.trim().length) {
            $.ajax({
                type: 'GET',
                url: "http://localhost:8080/Hotel_app/DBUtils.php", 
                data: {
                    action: 'editReservetion',
                    id: id,
                    start_date: start_date,
                    end_date: end_date,  
                },
                success: (data) => {
                    let res = JSON.parse(data);
                    if (res === 0) {
                        alert("Reservation could not be edited!");
                    } else {
                        $('.form-control').val("");
                        alert("!GOOD!");
                    }
                }
            })
        } else {
            alert("Please enter valid data in all fields!");
        }
    })
    </script>
</html>