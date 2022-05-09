#include <iostream>
#include "UI.h"
#include "Event.h"

UI::UI(Service& service): service { service }{}

void UI::print_app_menu()
{
    std::cout<<"    LIFE AFTER SCHOOL\n";
    std::cout<<" '1' ADMIN mode\n";
    std::cout<<" '2' USER mode\n";
    std::cout<<" '0' EXIT app\n";
    std::cout<<">> ";
}

void UI::run_app()
{
    int choice,ok= true;
    //service.generate_entries();
    while (ok)
    {
        print_app_menu();
        std::cin>>choice;
        if (choice==1)
            run_admin();
        else if (choice==2)
            run_user();
        else if (choice==0)
        {
            ok= false;
            std::cout<<"    Exiting...";
        }
    }
}

void UI::print_admin_menu()
{
    std::cout<<"\n";
    std::cout<<"    !ADMIN MODE!\n";
    std::cout<<" '1' ADD event\n";
    std::cout<<" '2' DELETE event\n";
    std::cout<<" '3' UPDATE event\n";
    std::cout<<" '4' PRINT event\n";
    std::cout<<" '0' EXIT admin\n";
    std::cout<<">> ";
}

void UI::run_admin()
{
    int ok=1, choice;
    while (ok)
    {
        print_admin_menu();
        std::cin>>choice;
        if (choice==1)
        {
            std::string title, description, link,input;
            int date=0,time=0,people_nr=0;
            std::cout<<"Title: ";
            std::cin>>input;
            title=input.substr(0, input.size());
            std::cout<<"Description: ";
            std::cin>>input;
            description=input.substr(0, input.size());
            std::cout<<"Date: ";
            std::cin>>date;
            std::cout<<"Time: ";
            std::cin>>time;
            std::cout<<"Number of people: ";
            std::cin>>people_nr;
            std::cout<<"Link: ";
            std::cin>>input;
            link=input.substr(0, input.size());
            add_operation(title, description, link, date, time, people_nr);
        }
        else if (choice==2)
        {
            std::string title,input;
            std::cout<<"Title: ";
            std::cin>>input;
            title=input.substr(0, input.size());
            remove_operation(title);
        }
        else if (choice==3)
        {
            std::string title,input;
            int people_nr;
            std::cout<<"Ttile: ";
            std::cin>>input;
            title=input.substr(0, input.size());
            std::cout<<"NEW number of people: ";
            std::cin>>people_nr;
            update_operation(title,people_nr);
        }
        else if (choice==4)
        {
            int i=0;
            while(i<service.get_lenght())
            {
                std::cout<<"\n";
                Event event=service.return_element(i);
                std::cout<<"Title: "<<event.get_title()<<"  ||  ";
                std::cout<<"Description: "<<event.get_description()<<"  ||  ";
                std::cout<<"Day: "<<event.get_date()<<"  ||  ";
                std::cout<<"Time: "<<event.get_time()<<"  ||  ";
                std::cout<<"Number of people: "<<event.get_people_nr()<<"  ||  ";
                std::cout<<"Link: "<<event.get_link();
                i++;
            }
            std::cout<<"\n";
        }
        else if (choice==0)
            ok=0;
    }
    return;
}

void UI::add_operation(std::string title, std::string description, std::string link, int date, int time, int people_nr)
{
    Event event{title,description,date,time,people_nr,link};
    if(service.check_duplicate(title)==0)
    {
        std::cout<<" !ERROR! This name is already in the list!\n";
    }
    else
        service.add(event);
}

void UI::remove_operation(std::string title)
{
    if(service.check_duplicate(title)==1)
    {
        std::cout<<"!ERROR! This name is not in the list!\n";
    }
    else
        service.remove(title);
}

void UI::update_operation(std::string title, int people_nr)
{
    if(service.check_duplicate(title)==1)
    {
        std::cout<<"!ERROR! This name is not in the list!\n";
    }
    else
        service.update_nr_people(title,people_nr);
}

void UI::print_user_menu()
{
    std::cout<<"\n";
    std::cout<<"     !USER MODE!\n";
    std::cout<<" '1' CHOOSE from ALL events\n";
    std::cout<<" '2' CHOOSE a SPECIFIC event\n";
    std::cout<<" '3' DELETE attendance from an event\n";
    std::cout<<" '4' SHOW all events in the calendar\n";
    std::cout<<" '0' EXIT user\n";
    std::cout<<">> ";
}

void UI::run_user()
{
    int ok=1, choice;
    while (ok)
    {
        print_user_menu();
        std::cin>>choice;
        if (choice==1)
        {
            int ok2=1,j=0,day,yes_no=-1;
            while(yes_no!=0)
            {
                day=1;
                while(day<=31&&yes_no!=0)
                {
                    for (int i=0;i<service.get_lenght();i++)
                    {
                        Event event = service.return_element(i);
                        if (event.get_date() == day)
                        {
                            std::cout << "\n";
                            std::cout << "Title: " << event.get_title() << "  ||  ";
                            std::cout << "Description: " << event.get_description() << "  ||  ";
                            std::cout << "Day: " << event.get_date() << "  ||  ";
                            std::cout << "Time: " << event.get_time() << "  ||  ";
                            std::cout << "Number of people: " << event.get_people_nr() << "  ||  ";
                            std::cout << "Link: " << event.get_link();
                            std::cout << "\n'1' ADD event \n'2' SKIP event \n'0' QUIT \n>> ";
                            std::cin >> yes_no;
                            if (yes_no == 1)
                            {
                                Event event2 = service.return_element(i);
                                std::string name=event2.get_title();
                                if (service.check_duplicate2(name)==0)
                                    std::cout<<" !ERROR! This event is already in the calendar!\n";
                                else
                                {
                                    service.add2(event2);
                                }
                            }
                        }
                    }
                    day++;
                }
                if(yes_no!=0)
                {
                    std::cout<<"All events shown! Do you want to see them again?\n'1' YES\n'2' NO\n>>";
                    int one_two;
                    std::cin>>one_two;
                    if (one_two==2)
                        yes_no=0;
                }
            }
        }
        else if (choice==2)
        {
            int i=0;
            while(i<service.get_lenght())
            {
                std::cout<<"\n";
                Event event=service.return_element(i);
                std::cout<<"Title: "<<event.get_title()<<"  ||  ";
                std::cout<<"Description: "<<event.get_description()<<"  ||  ";
                std::cout<<"Day: "<<event.get_date()<<"  ||  ";
                std::cout<<"Time: "<<event.get_time()<<"  ||  ";
                std::cout<<"Number of people: "<<event.get_people_nr()<<"  ||  ";
                std::cout<<"Link: "<<event.get_link();
                i++;
            }
            std::cout<<"\n\n";
            std::cout<<"Name of the Event you want to add to your calendar: ";
            std::string name3;
            std::cin>>name3;
            if (service.check_duplicate2(name3)==0)
                std::cout<<"!ERROR! This event is already in your calendar!";
            else
            {
                Event event = service.return_element(service.search_elem_by_pos(name3));
                service.add2(event);
            }
        }
        else if (choice==3)
        {
            std::cout<<"Name of the Event you want to remove from your calendar: ";
            std::string name10;
            std::cin>>name10;
            if (service.search_elem_by_pos2(name10)!=1)
            {
                Event event1 = service.return_element(service.search_elem_by_pos(name10));
                int people=event1.get_people_nr();
                std::string title=event1.get_title();
                people--;
                service.update_nr_people(name10,people);
                service.remove2(name10);
            }
            else
                std::cout<<"!ERROR! This event is not in your calendar!";
        }
        else if (choice==4)
        {
            int i=0;
            while(i<service.get_lenght2())
            {
                std::cout<<"\n";
                Event event2=service.return_element2(i);
                std::cout<<"Title: "<<event2.get_title()<<"  ||  ";
                std::cout<<"Description: "<<event2.get_description()<<"  ||  ";
                std::cout<<"Day: "<<event2.get_date()<<"  ||  ";
                std::cout<<"Time: "<<event2.get_time()<<"  ||  ";
                std::cout<<"Number of people: "<<event2.get_people_nr()<<"  ||  ";
                std::cout<<"Link: "<<event2.get_link();
                i++;
            }
            std::cout<<"\n";
        }
        else if (choice==0)
            ok=0;
    }
    return;
}
