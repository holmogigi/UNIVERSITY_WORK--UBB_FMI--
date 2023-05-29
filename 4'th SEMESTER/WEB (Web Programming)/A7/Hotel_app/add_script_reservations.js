function doSomethingWithUserId(user_id) 
{
    $('#insertLogButton').click(() => {
        let room_id = $('#roomId').val();
        let start_date = $('#startDate').val();
        let end_date = $('#endDate').val();
        if (room_id.trim().length > 0 && start_date.trim().length && end_date.trim().length) 
        {
            $.ajax({
                type: 'GET',
                url: "http://localhost:8080/Hotel_app/DBUtils.php", 
                data: {
                    action: 'insertReservetion',
                    room_id: room_id,
                    user_id: user_id,
                    start_date: start_date,
                    end_date: end_date,  
                },
                success: (data) => {
                    let res = JSON.parse(data);
                    if (res === 0) {
                        alert("Reservation could not be added!");
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
}


$(document).ready(() => 
{
    $.ajax({
        type: 'GET',
        url: 'http://localhost:8080/Hotel_app/DBUtils.php',
        data: { action: 'selectIdByUsername', username: username },
        success: function(result) 
        {
          var response = JSON.parse(result);
          var user_id = parseInt(response[0].id, 10);
          console.log(user_id);
          doSomethingWithUserId(user_id);
        }
      });

})