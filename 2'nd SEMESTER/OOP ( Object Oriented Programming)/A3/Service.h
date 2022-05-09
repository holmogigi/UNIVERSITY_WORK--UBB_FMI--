#pragma once
#include <iostream>
#include "Repo.h"
#include "RepoFile.h"
#include "Event.h"
#include <vector>

class Service
{
private:
    RepoFile& list;
    Repo list2;
public:
    explicit Service(RepoFile& repo);
    ///
    void add(Event &elem);
    int check_duplicate(std::string name);
    int search_elem_by_pos(std::string title);
    void update_nr_people(std::string title,int people_nr);
    void remove(std::string title);
    void generate_entries();
    int get_lenght() const {return list.getSize();}
    ///
    int get_lenght2() const {return list2.getSize();}
    Event return_element(int pos);
    Event return_element2(int i);
    void add2(const Event &elem);
    int check_duplicate2(std::string name);
    int search_elem_by_pos2(std::string title);
    void remove2(std::string title);
};

