#pragma once
#include <cassert>
#include "Event.h"
#include "Repo.h"
#include "Service.h"

class Tests
{
public:
    void run_all_tests();
private:
    void test_create_event();
    void test_people_nr_setter();
    void test_service_add();
    void test_check_duplicate();
    void test_remove();
    void test_update_nr_people();
    void test_generate_entries();
    void test_return_element();
    void test_remove_vector();
    void test_create_vector();
    void test_service_add2();
    void test_check_duplicate2();
    void test_search_elem_by_pos2();
    void test_remove2();
};

