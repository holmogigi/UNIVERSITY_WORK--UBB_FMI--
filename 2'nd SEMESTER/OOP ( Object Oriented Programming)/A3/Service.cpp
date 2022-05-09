#include "Service.h"
#include "Event.h"

Service::Service(RepoFile& repo): list(repo) {}

// Function that recives the event element and adds it to the admin vector
void Service::add(Event &elem)
{
    this->list.store_event(elem);
}

// Function that checks if a given string is found in the admin vector
int Service::check_duplicate(std::string name)
{
    int i=0;
    while (i<this->list.getSize())
    {
        Event event=list.get_elem(i);
        if(event.get_title()==name)
            return 0;
        i++;
    }
    return 1;
}

// Function that recives the title of the event and removes the element from the found index in the admin vector
void Service::remove(std::string title)
{
    this->list.delete_event(list.get_elem(list.find_pos(title)));
}

// Function that returns the position where an element is found in the admin vector
int Service::search_elem_by_pos(std::string title)
{
    int i=0,pos;
    while(i<list.getSize())
    {
        Event event=list.get_elem(i);
        if(event.get_title()==title)
            pos=i;
        i++;
    }
    return pos;
}

// Function that updated the number of people attending a given event
void Service::update_nr_people(std::string title,int people_nr)
{
    int i=0, pos=search_elem_by_pos(title);
    Event event=list.get_elem(pos);
    event.set_people_nr(people_nr);
    list.update_event(event,pos);
}

// Function that generates 10 entries at the beggining of the app
void Service::generate_entries()
{
    Event event1{"Museum","Entertaiment",12,19,30,"https://www.macluj.ro"};
    Event event2{"Football","Sport",1,20,5000,"https://cfr1907.ro"};
    Event event3{"Concert","Entertaiment",29,21,200,"https://www.facebook.com/formcafe"};
    Event event4{"Party","Entertaiment",3,23,125,"https://www.facebook.com/RevolutionClubCluj"};
    Event event5{"Gym","Health",25,17,40,"https://18gym.ro"};
    Event event6{"Handball","Sport",2,19,500,"https://u-cluj.ro/handbal-masculin"};
    Event event7{"Marathon","Health",30,10,100,"https://maraton-cluj.ro"};
    Event event8{"Theater","Entertaiment",17,19,75,"https://www.huntheater.ro"};
    Event event9{"Volleyball","Sport",15,19,175,"https://u-cluj.ro/volei-feminin-2"};
    Event event10{"Aerobic","Health",6,18,25,"https://evolve-fitness.ro"};
    this->add(event1);
    this->add(event2);
    this->add(event3);
    this->add(event4);
    this->add(event5);
    this->add(event6);
    this->add(event7);
    this->add(event8);
    this->add(event9);
    this->add(event10);
}

// Function that returns an Event from the given index in the admin vector
Event Service::return_element(int i)
{
    return list.get_elem(i);
}

// Function that returns an Event from the given index in the user vector
Event Service::return_element2(int i)
{
    return list2.get_elem(i);
}

// Function that adds a given Event in the user vector
void Service::add2(const Event &elem)
{
    std::string name=elem.get_title();
    int nr=elem.get_people_nr();
    nr++;
    update_nr_people(name,nr);
    int pos=search_elem_by_pos(name);
    this->list2.add(return_element(pos));
}

// Function that checks if a given string is found in the user vector
int Service::check_duplicate2(std::string name)
{
    int i=0;
    while (i<this->get_lenght2())
    {
        Event event= return_element2(i);
        if(event.get_title()==name)
            return 0;
        i++;
    }
    return 1;
}

// Function that searches a given string in the user vector and returns it's position
int Service::search_elem_by_pos2(std::string title)
{
    int i=0,pos=-1;
    while(i<get_lenght2())
    {
        Event event= return_element2(i);
        if(event.get_title()==title)
            pos=i;
        i++;
    }
    return pos;
}

// Function that removes an element from a given position in the user vector
void Service::remove2(std::string title)
{
    int i= search_elem_by_pos2(title);
    this->list2.remove(i);
}