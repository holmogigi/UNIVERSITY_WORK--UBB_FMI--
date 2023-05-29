let currentPage = 0;
let showType = 'all';

const insertData = (newBody, data) => 
{
    if (currentPage === 0) {
        $('#previousButton').attr('disabled', true);
    }
    let result = JSON.parse(data);
    let numberOfPages = Math.ceil(result.length/4);
    for (let log of result) {
        let newRow = newBody.insertRow();
        if (result.indexOf(log) >= 4 * currentPage) {
            for (let index of ['id', 'hotel_name', 'room_number', 'category', 'price']) 
            {
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

const showAllRooms = () => 
{
    let body = $('.roomtable tbody').eq(0);
    let newBody = document.createElement('tbody');
    $.ajax({
        type: 'GET',
        url: "http://localhost:8080/Hotel_app/DBUtils.php",
        data: {action: 'getAllRooms'},
        success: (data) => {
            insertData(newBody, data);
        }
    })
    body.replaceWith(newBody);
}


const showRoomByCategory = (category) => 
{
    let body = $('.roomtable tbody').eq(0);
    let newBody = document.createElement('tbody');
    $.ajax({
        type: 'GET',
        url: "http://localhost:8080/Hotel_app/DBUtils.php",
        data: {action: 'getRoomByCategory', category: category},
        success: (data) => {
            $('.form-control').val("");
            insertData(newBody, data);
        }
    })
    body.replaceWith(newBody);
}

const showRoomlByPrice = (price) => 
{
    let body = $('.roomtable tbody').eq(0);
    let newBody = document.createElement('tbody');
    $.ajax({
        type: 'GET',
        url: "http://localhost:8080/Hotel_app/DBUtils.php",
        data: {action: 'getRoomByPrice', price: price},
        success: (data) => {
            $('.form-control').val("");
            insertData(newBody, data);
        }
    })
    body.replaceWith(newBody);
}

const showCorrectHotels = () => {
    switch (showType) {
        case 'all':
            showAllRooms();
            break;

        case 'category':
            category = $('#categoryInputFilter').val().trim();
            if (category.length > 0)
                showRoomByCategory(category);
            else 
            {
                showType = 'all';
            }
            break;

        case 'price':
            price = $('#priceInputFilter').val().trim();
            if (price.length > 0)
                showRoomlByPrice(price);
            else {
                showType = 'all';  
            }
            break;
    }
}

$(document).ready(() => {
    showAllRooms();

    $('#allLogsButton').click(() => 
    {
        currentPage = 0;
        showType = 'all';
        showCorrectHotels();
    })

    $('#filterByCategory').click(() => 
    {
        currentPage = 0;
        showType = 'category';
        showCorrectHotels();
    })

    $('#filterByPrice').click(() => 
    {
        currentPage = 0;
        showType = 'price';
        showCorrectHotels();
    })

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