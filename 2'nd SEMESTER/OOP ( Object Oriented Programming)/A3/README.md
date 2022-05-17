# Assignment 04-05
## Requirements
- The application must be implemented in C++ and use layered architecture.
- Provide tests and specifications for non-trivial functions outside the UI. Test coverage must be at least 98% for all layers, except the UI
- Have at least 10 entities in your memory repository
- Validate all input data
- Handle the following situations:
    - If an entity that already exists is added, a message is shown and the entity is not stored. You must decide what makes an entity unique.
    - If the user tries to update/delete an entity that does not exist, a message will be shown and there will be no effect on the list of entities.

## Week 5
- Solve the requirements related to the administrator mode
- Define the `DynamicVector` class which provides the specific operations: `add`, `remove`, `length`, etc. The array of elements must be dynamically allocated

## Week 6
- Solve all problem requirements
- `DynamicVector` must be a templated class


# Assignment 08-09
## Requirements
1. Replace your DynamicVector template with the STL vector. Use STL algorithms wherever possible
   in your application (e.g. in your filter function you could use copy_if, count_if). Replace all your
   for loops either with STL algorithms, or with the ranged-based for loop (C++11).

2. Store your data in a text file. When the program starts, the entities in the database (file) will be
   read. The modifications made during the execution of the application should be stored in the file.
   For this feature, use the iostream library. Create insertion and extraction operators for your
   entities and use these when reading/writing to files or console.

3. Use exceptions to signal errors:
- from the repository;
- validation errors – validate your entities using Validator classes;
- create your own exception classes.
  Validate your input data.
  Observation: Points 4 and 5 should be solved using inheritance and polymorphism.

4. Store your EVENT LIST in a file. When the application starts, the user should choose the type of file (CSV or HTML).
  Depending on this type, the application should save the list in the correct format.

5. Add a new command, allowing the user to see the EVENT LIST. Displaying the list means opening the saved file (csv or html) with the correct application:
- CSV file – with Notepad, Notepad++, Microsoft Excel or OpenOffice Calc
- HTML file – with a browser


# Assignment 11-12
## Requirements
- Create a graphical user interface (GUI) for the problem you have been working on (Labs 5,6,7,8),
using Qt.
- For the first iteration, due in Week 11, you should implement at least the design of the interface
(location and size of GUI widgets, without attached functionalities) and the list/table displaying
the repository entities in administrator mode should be populated using an input file.
- For the first iteration, the GUI must be created and coded manually (no Qt Designer!).

- For the second iteration, due in Week 12, all the required functionalities should be available using
the GUI. For this iteration, you may use Qt Designer, if you want to change the initial design of
your GUI.
- The functionality of the application must be the same (including the one-by-one iteration of
objects for the user mode).

## Problem Statements

Lectures, seminars and labs ... school in general must be taken seriously; BUT so must be your social life and leisure time. To manage the latter and be always informed about the interesting events happening in your city you will implement a software application. The application can be used in two modes: administrator and user. When the application is started, it will offer the option to choose the mode.\
**Administrator mode:** The application will have a database which holds all the interesting events in your area. You must be able to update the database, meaning: add a new event, delete an event and update the information of an event. Each **Event** has a `title`, a `description`, a `date and time`, a `number of people` who are going and a `link` towards the online resource containing the event. The administrators will also have the option to see all the events in the database.\
**User mode:** A user can create a list with the events that he/she is interested in. The application will allow the user to:
- See the events in the database for a given month (if there is no month given, see all the events, ordered chronologically), one by one. When the user chooses this option, the data of the first event (title, description, date and time, number of people who are going) is displayed, and the event is opened in the browser (e.g. Facebook event).
- If the user wants to participate in the event he/she can choose to add it to his/her events list. When this happens, the number of people who are going to the event increases (for the event in the repository).
- If the event seems uninteresting, the user can choose not to add it to the list and continue to the next. In this case, the information corresponding to the next event is shown, and the user is again offered the possibility to add it to his/her list. This can continue as long as the user wants, as when arriving to the end of the list of events for the given month, if the user chooses next, the application will again show the first event.
- Delete an event from the list. When the user deletes an event from his/her list, the number of people who are going to the event decreases.
- See the list of events the user wants to attend.
