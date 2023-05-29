In this lab you will have to develop a server-side web application in PHP. The web application has to manipulate a Mysql database with 1 to 3 tables and should implement the following base operations on these tables: select, insert, delete, update. Also the web application must use AJAX for getting data asynchronously from the web server and the web application should contain at least 5 web pages (client-side html or server-side php).

Please make sure that you avoid sql-injection attacks when working with the database.

Have in mind the user experience when you implement the problem:

-add different validation logic for input fields

-do not force the user to input an ID for an item if he wants to delete/edit/insert it; this should happen automatically (e.g. the user clicks an item from a list, and a page/modal prepopulated with the data for that particular item is opened, where the user can edit it)

-add confirmation when the user deletes/cancels an item

-do a bare minimum CSS that at least aligns the various input fields

Write a web application for room booking in a hotel chain. The application should save room information in the database. The clients should have the posibility of browsing the rooms by category, type, price, hotel etc. (use AJAX for this), booking one or more rooms for a specific period of time, but also they should have the posibility of cancelling their reservation. Rooms browsing should be paged - rooms are displayed on pages with maximum 4 rooms on a page (you should be able to go to the previous and the next page).
