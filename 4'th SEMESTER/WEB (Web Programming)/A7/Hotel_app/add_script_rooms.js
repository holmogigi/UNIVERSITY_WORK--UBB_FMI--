$(document).ready(() => 
{
    $('#insertLogButton').click(() => {
        let hotel_id = $('#typeField').val();
        let room_number = $('#severityField').val();
        let category = $('#typeField1').val();
        let price = $('#severityField1').val();
        if (hotel_id.trim().length > 0 && room_number.trim().length && category.trim().length && price.trim().length) {
            $.ajax({
                type: 'GET',
                url: "http://localhost:8080/Hotel_app/DBUtils.php", 
                data: {
                    action: 'insertroom',
                    hotel_id: hotel_id,
                    room_number: room_number,
                    category: category,
                    price: price,  
                },
                success: (data) => {
                    let res = JSON.parse(data);
                    if (res === 0) {
                        alert("Room could not be added!");
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
})