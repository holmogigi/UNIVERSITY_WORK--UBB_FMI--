#include "Tests.h"
#include <iostream>

/*
// Function that runs all tests for the app
void Tests::run_all_tests()
{
    test_create_event();
    test_people_nr_setter();
    test_service_add();
    test_check_duplicate();
    test_remove();
    test_update_nr_people();
    test_generate_entries();
    test_return_element();
    test_remove_vector();
    test_create_vector();
    test_service_add2();
    test_check_duplicate2();
    test_search_elem_by_pos2();
    test_remove2();
    std::cout<<"!All tests done!";
}

void Tests::test_create_event()
{
    Event event1;
    assert(event1.get_title()=="");
    assert(event1.get_description()=="");
    assert(event1.get_date()==0);
    assert(event1.get_time()==0);
    assert(event1.get_people_nr()==0);
    assert(event1.get_link()=="");

    Event event={"TestTitle","TestDescription",1,2,3,"TestLink"};
    assert(event.get_title()=="TestTitle");
    assert(event.get_description()=="TestDescription");
    assert(event.get_date()==1);
    assert(event.get_time()==2);
    assert(event.get_people_nr()==3);
    assert(event.get_link()=="TestLink");
}

void Tests::test_people_nr_setter()
{
    Event event={"TestTitle","TestDescription",1,2,3,"TestLink"};
    assert(event.get_people_nr()==3);
    event.set_people_nr(0);
    assert(event.get_people_nr()==0);
}

void Tests::test_service_add()
{
    Repo <Event>vector;
    Service service{};
    Event event={"TestTitle","TestDescription",1,2,3,"TestLink"};
    Event event2={"TestTitle2","TestDescription2",11,22,33,"TestLink2"};
    service.add(event);
    assert(service.get_lenght()==1);
    service.add(event2);
    assert(service.get_lenght()==2);

}

void Tests::test_service_add2()
{
    Service service{};
    Event event={"TestTitle","TestDescription",1,2,3,"TestLink"};
    service.add2(event);
    assert(service.get_lenght2()==1);
    Event event1=service.return_element2(0);
    service.add2(event1);
    assert(service.get_lenght2()==2);
}

void Tests::test_check_duplicate()
{
    Repo<Event> vector;
    Service service{};
    std::string test1="TestTitle";
    std::string test2="NoTest";
    Event event={"TestTitle","TestDescription",1,2,3,"TestLink"};
    service.add(event);
    assert(service.check_duplicate(test1)==0);
    assert(service.check_duplicate(test2)==1);
    vector.operator[](1);
}

void Tests::test_remove()
{
    Repo<Event> vector;
    Service service{};
    std::string test1="TestTitle";
    Event event={"TestTitle","TestDescription",1,2,3,"TestLink"};
    service.add(event);
    assert(service.get_lenght()==1);
    service.remove(test1);
    assert(service.get_lenght()==0);
    vector.operator[](0);
}

void Tests::test_update_nr_people()
{
    Service service{};
    std::string test1="TestTitle";
    Event event={"TestTitle","TestDescription",1,2,3,"TestLink"};
    service.add(event);
    service.update_nr_people(test1,33);
    Event event1;
    event1=service.return_element(0);
    assert(event1.get_people_nr()==33);
}

void Tests::test_generate_entries()
{
    Service service{};
    service.generate_entries();
    assert(service.get_lenght()==10);
    Event event0;
    event0=service.return_element(0);
    assert(event0.get_title()=="Museum");
    assert(event0.get_description()=="Entertaiment");
    assert(event0.get_date()==12);
    assert(event0.get_time()==19);
    assert(event0.get_people_nr()==30);
    assert(event0.get_link()=="https://www.macluj.ro");
}

void Tests::test_return_element()
{
    Repo<int> vector{ 2 };
    int first=1, second=5;
    vector.add(first);
    vector.add(second);
    assert(vector.get_elem(1) == 5);
}

void Tests::test_remove_vector()
{
    Repo<int> vector{ 2 };
    vector.add(1);
    vector.add(2);
    vector.add(3);
    vector.remove(2);
    assert(vector.getSize()==2);
    vector.add(4);
    vector.add(5);
    vector.add(6);
    vector.remove(5);
    assert(vector.getSize()==4);
}

void Tests::test_create_vector()
{
    Repo<int> vector{ 5 };
    assert(vector.getCapacity() == 5);
}

void Tests::test_check_duplicate2()
{
    Repo<Event> vector;
    Service service{};
    std::string test1="TestTitle";
    std::string test2="NoTest";
    Event event={"TestTitle","TestDescription",1,2,3,"TestLink"};
    service.add2(event);
    assert(service.check_duplicate2(test1)==0);
    assert(service.check_duplicate2(test2)==1);
}

void Tests::test_search_elem_by_pos2()
{
    Repo<Event> vector;
    Service service{};
    Event event={"TestTitle","TestDescription",1,2,3,"TestLink"};
    Event event2={"TestTitle","TestDescription",1,2,3,"TestLink"};
    service.add2(event);
    assert(service.search_elem_by_pos2("TestTitle")==0);
}

void Tests::test_remove2()
{
    Repo<Event> vector;
    Service service{};
    std::string test1="TestTitle";
    Event event={"TestTitle","TestDescription",1,2,3,"TestLink"};
    service.add2(event);
    assert(service.get_lenght2()==1);
    service.remove2(test1);
    assert(service.get_lenght2()==0);
}
*/