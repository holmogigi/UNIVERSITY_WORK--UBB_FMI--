<?php
session_start();
if (isset($_SESSION['username'])) {
    $username = $_SESSION['username'];
} else {
    header('Location: login.php');
    die();
}
if (isset($_POST['viewAllButton'])) {
    header('Location: listHotels.php');
}
if (isset($_POST['logoutButton'])){
    session_unset();
    session_destroy();
    header('Location: login.php');
}
if(isset($_POST['addLogButton'])) {
    header('Location: ');
}
if(isset($_POST['removeLogButton'])) {
    header('Location: ');
}
?>


<!DOCTYPE html>
<html>
    <head>
        <title>Hotel booking site</title>
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>

    </head>
    <body>
        <main>
            <br></br>
            <br></br>
            <br></br>
            <br></br>
            <br></br>
            <br></br>
            <br></br>
            <br></br>
            <div class="container text-center"><h3>Welcome, <?php echo $username;?>!</h3></div>
            <br></br>
        <div class="container text-center" id="index-page">
               <button type="button" class="btn btn-primary btn-block" onclick="location.href='listHotels.php'">List all hotels</button>
               <button type="button" class="btn btn-primary btn-block" onclick="location.href='list_rooms.php'">List all rooms</button>
               <button type="button" class="btn btn-primary btn-block" onclick="location.href='reservations.php'">My reservetions</button>
               <br></br>
               &nbsp&nbsp&nbsp<button type="button" class="btn btn-primary btn-block" onclick="location.href='add_hotel.php'">Add hotel</button>&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
               <button type="button" class="btn btn-primary btn-block" onclick="location.href='add_room.php'">Add room</button>&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
               <button type="button" class="btn btn-primary btn-block" onclick="location.href='login.php'">Log out</button>&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
        </div>
        </main>
    </body>
</html>