#include "ui.h"
#include <windows.h>
#include <shellapi.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

UI::UI(Service &service, UserService &userService, EventValidator &validator1): service(service), userService(userService), validator(validator1) {}

void UI::print_menu() {
    cout<< "Press '1' for ADMIN MODE\n";
    cout<< "Press '2' for USER MODE\n";
    cout<< "Press '3' to EXIT\n";

}

void UI::print_menu_admin() {
    cout<< "!ADMIN MODE!\n";
    cout<< "1. ADD event \n";
    cout<< "2. DELETE an event\n";
    cout<< "3. UPDATE an event\n";
    cout<< "4. PRINT events\n";
    cout<< "5. EXIT admin mode\n";
}

void UI::print_menu_user() {
    cout<< "!USER MODE!\n";
    cout<< "1. PRINT every available event for a given month\n";
    cout<< "2. PRINT all events you have added to your list\n";
    cout<< "3. REMOVE an event from your list\n";
    cout<< "4. OPEN\n";
    cout<< "5. EXIT user mode\n";
}

void UI::add_event() {
    string title, description, date_time, number_people, link;
    int int_number_people;

    while(true){
        try{
            cout<<"Title: ";
            getline(cin, title);
            this->validator.validateTitle(title);
            break;
        }
        catch(ValidatorException& exception) {
            cout << exception.what() << endl;
        }
    }

    while(true){
        try{
            cout<<"Description: ";
            getline(cin, description);
            this->validator.validateDescription(description);
            break;
        }
        catch(ValidatorException& exception){
            cout << exception.what() << endl;
        }
    }

    while(true){
        try{
            cout<<"Date and Time(eg. dd/mm/yyyy xx:yy): ";
            getline(cin, date_time);
            this->validator.validateDateTime(date_time);
            break;
        }
        catch(ValidatorException& exception){
            cout<< exception.what() << endl;
        }
    }
    while(true){
        try{
            cout<<"Number of people attending: ";
            getline(cin, number_people);
            this->validator.validatePeopleString(number_people);
            int_number_people = stoi(number_people);
            this->validator.validatePeople(int_number_people);
            break;
        }
        catch(ValidatorException& exception){
            cout << exception.what() << endl;
        }
    }
    while(true){
        try{
            cout<<"Link: ";
            getline(cin, link);
            this->validator.validateLink(link);
            break;
        }
        catch(ValidatorException& exception){
            cout << exception.what() << endl;
        }
    }
    this->service.add_service(title, description, date_time, int_number_people, link);
    cout <<"Event added successfully!\n";
}

void UI::remove_event() {
    string link;
    while(true){
        try{
            cout<<"Link: ";
            getline(cin, link);
            this->validator.validateLink(link);
            break;
        }
        catch(ValidatorException& exception){
            cout << exception.what()<< endl;
        }
    }
    this->service.remove_service(link);
    cout<<"Event removed successfully!\n";
}

void UI::update_event() {
    string oldLink, newLink, title, description, date_time, number_people;
    int int_number_people;

    while(true){
        try{
            cout<<"Link: ";
            getline(cin, oldLink);
            this->validator.validateLink(oldLink);
            break;
        }
        catch(ValidatorException& exception){
            cout<<exception.what()<< endl;
        }
    }
    while(true){
        try{
            cout<<"New Link: ";
            getline(cin, newLink);
            this->validator.validateLink(newLink);
            break;
        }
        catch(ValidatorException& exception){
            cout << exception.what() << endl;
        }
    }
    while(true){
        try{
            cout<<"New Title: ";
            getline(cin, title);
            this->validator.validateTitle(title);
            break;
        }
        catch(ValidatorException& exception){
            cout<<exception.what()<<endl;
        }
    }
    while(true){
        try{
            cout<<"New Description: ";
            getline(cin, description);
            this->validator.validateDescription(description);
            break;
        }
        catch(ValidatorException& exception){
            cout<<exception.what()<<endl;
        }
    }
    while(true){
        try{
            cout<<"New Date and Time: ";
            getline(cin, date_time);
            this->validator.validateDateTime(date_time);
            break;
        }
        catch(ValidatorException& exception){
            cout<<exception.what()<<endl;
        }
    }
    while(true){
        try{
            cout<<"New Number of People Attending: ";
            getline(cin, number_people);
            this->validator.validatePeopleString(number_people);
            int_number_people = stoi(number_people);
            this->validator.validatePeople(int_number_people);
            break;
        }
        catch(ValidatorException& exception){
            cout<<exception.what()<<endl;
        }
    }
    this->service.update_service(title, description, date_time, int_number_people, oldLink, newLink);
    cout<<"Event updated successfully\n";
}

void UI::list_event_admin() {
    std::vector<Event> events;
    events = this->service.getAllService();
    int i = 0;
    for(const Event& event:events){
        cout << event.toString() << endl;
        i++;
    }
}

void UI::print_my_events() {
    std::vector<Event> list;
    list = this->userService.getAllUsersService();
    int i = 0;
    unsigned int number_of_events = this->userService.getSizeService();
    if(number_of_events == 0)
        cout<< "You have no events added";
    for(const Event& event:list){
        cout << event.toString() << endl;
        i++;
    }
}

void UI::list_event_user() {
    string monthFilter;
    cout<<"Enter the month you wish to see the events for: ";
    getline(cin, monthFilter);
    std::vector<Event> validEvents;
    validEvents.reserve(this->service.getSizeService());
    std::vector<Event> list;
    list.reserve(this->userService.getSizeService());
    list = this->userService.getAllUsersService();

    int length = this->userService.filterByMonth(validEvents, monthFilter);
    if(length == 0)
        cout<<"There are no events in that month\n";
    string command;
    bool exit = false;
    int i = 0;
    while(!exit){
        if(length == 0)
            cout<<"No events left\n";
        if(i == length)
            i = 0;
        cout<< validEvents[i].toString() << endl;
        cout<<"Add to your list, continue or exit? (Yes/Continue/Exit) \n";
        ShellExecuteA(NULL, NULL, "chrome.exe", validEvents[i].get_link().c_str(), NULL, SW_SHOWMAXIMIZED);
        getline(cin, command);
        if(command == "Yes"){
            int found1 = 0;
            Event event;
            event = validEvents[i];
            for(Event& e: list)
                if(event == e)
                    found1 = 1;
            if(found1 == 1) {
                cout << "You have already added the event in your list\n";
            }
            else{
                this->userService.addUserService(event);
                event.set_number_people(event.get_number_people() + 1);
            }
            i++;
        }   else if(command == "Continue"){
            i++;
        }   else if(command == "Exit")
                exit = true;

    }
}

void UI::open_file()
{
    std::string type=this->userService.getFileService();
    if (type=="C:\\Users\\USER\\OneDrive\\Desktop\\UBB FMI\\SEM 2\\OOP_ ASSIG\\a5-6-holmogigi\\List.csv")
        system("notepad.exe C:\\Users\\USER\\OneDrive\\Desktop\\UBB FMI\\SEM 2\\OOP_ ASSIG\\a5-6-holmogigi\\List.csv");
    else
        ShellExecute(nullptr,L"open",L"C:\\Users\\USER\\OneDrive\\Desktop\\UBB FMI\\SEM 2\\OOP_ ASSIG\\a5-6-holmogigi\\List.html",
                     nullptr, nullptr,SW_SHOWNORMAL);
}

void UI::remove_event_user() {
    string link;
    cout << "Enter the link of the event you want to remove";
    getline(cin, link);
    std::vector<Event> list;
    list.reserve(this->userService.getSizeService());
    list = this->userService.getAllUsersService();
    int found = 0;
    int i;
    for(Event& e: list)
        if(e.get_link() == link)
            found = 1;
    if(found == 0)
        cout<<"That event is not in your list\n";
    else{
        int number_people;
        i = this->service.searchService(link);
        number_people = this->service.getAllService()[i].get_number_people();
        this->service.getAllService()[i].set_number_people(number_people - 1);
        this->service.writeToFileService();
        this->userService.removeUserService(link);
    }
}

void UI::admin_mode() {
    bool exit = false;
    while(!exit){
        try{
            print_menu_admin();
            string command;
            getline(cin, command);
            if(command == "5")
                exit = true;
            else if(command == "1")
                this->add_event();
            else if(command == "2")
                this->remove_event();
            else if(command == "3")
                this->update_event();
            else if(command == "4")
                this->list_event_admin();
            else
                cout<<"Invalid command\n";
        }
        catch(const char* msg){
            cout<<msg<<endl;
        }
        catch(const exception& e){
            cerr<<e.what();
            cout<<endl;
        }
    }
}

void UI::user_mode() {
    bool exit = false;
    while(!exit){
        try{
            print_menu_user();
            string command;
            getline(cin, command);
            if(command == "5")
                exit = true;
            else if(command == "1")
                this->list_event_user();
            else if(command == "2")
                this->print_my_events();
            else if(command == "3")
                this->remove_event_user();
            else if(command == "4")
                this->open_file();
        }
        catch(const char* msg){
            cout << msg << endl;
        }
        catch(const exception &e){
            cerr << e.what();
            cout << endl;
        }
    }
}

void UI::run(){
    cout << "Event organiser!\n";
    int usermode = 0;
    bool exit = false;
    while(!exit){
        print_menu();
        string command;
        std::cin>>command;
        if(command == "1")
            admin_mode();
        else if(command == "2"){
            if(usermode == 0){
                std::cout<<"How do you want to save your list?(csv/html)\n";
                std::string fileType;
                while(true){
                    try{
                        getline(std::cin, fileType);
                        this->userService.RepositoryType(fileType);
                        break;
                    }catch(UserException& ex){
                        std::cout<<ex.what()<<std::endl;
                    }
                }
                usermode = 1;
            }
            user_mode();
        }
        else if(command == "3")
            exit = true;
        else
            cout<< "Invalid command\n";
    }
}

UI::~UI() = default;