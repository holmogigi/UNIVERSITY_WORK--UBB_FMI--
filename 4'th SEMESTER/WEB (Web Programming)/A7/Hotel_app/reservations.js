

let currentPage = 0;

const insertData = (newBody, data) => {
    if (currentPage === 0) {
        $('#previousButton').attr('disabled', true);
    }
    let result = JSON.parse(data);
    let numberOfPages = Math.ceil(result.length/4);
    for (let log of result) {
        let newRow = newBody.insertRow();
        if (result.indexOf(log) >= 4 * currentPage) {
            for (let index of ['id', 'room_number', 'hotel_name', 'start_date', 'end_date']) {
                let newCol = newRow.insertCell();
                let newText = document.createTextNode(log[index]);
                newCol.appendChild(newText);
            }
            newBody.append(newRow);
        }
        if (result.indexOf(log) >= 4 * currentPage + 3) {
            break;
        }
    }
    if (numberOfPages === 0) {
        $('#nextButton').attr('disabled', true);
    } else {
        if (currentPage === numberOfPages - 1) {
            $('#nextButton').attr('disabled', true);
        } else {
            $('#nextButton').attr('disabled', false);
        }
    }
}

function doSomethingWithUserId(user_id) 
{

    let body = $('.reservationtable tbody').eq(0);
    let newBody = document.createElement('tbody');
    $.ajax({
        type: 'GET',
        url: "http://localhost:8080/Hotel_app/DBUtils.php",
        data: {action: 'getReservationByUserId',
        user_id: user_id},
        success: (data) => {
            insertData(newBody, data);
        }
    })
    body.replaceWith(newBody);
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

    $('#previousButton').click(() => 
        {
            if (currentPage > 0) {
                currentPage--;
                if (currentPage === 0) {
                    $('#previousButton').attr('disabled', true);
                }
            }
            showCorrectHotels();
        })

        $('#nextButton').click(() => 
        {
            $('#previousButton').attr('disabled', false);
            currentPage++;
            showCorrectHotels();
        })
})