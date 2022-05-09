#pragma once
#include "Service.h"

class UI
{
private:
    Service& service;
public:
    UI(Service& service);
    void print_app_menu();
    void run_app();
    void print_admin_menu();
    void run_admin();
    void add_operation(std::string title, std::string description, std::string link, int date, int time, int people_nr);
    void remove_operation(std::string title);
    void update_operation(std::string title, int people_nr);
    void print_user_menu();
    void run_user();
};

