#pragma once
#include "service.h"
#include "userService.h"
#include "validators.h"

class UI {
private:
    Service& service;
    UserService& userService;
    EventValidator& validator;
public:
    explicit UI(Service& service, UserService& userService, EventValidator& validator1);

    void print_menu();
    static void print_menu_admin();
    void add_event();
    void remove_event();
    void update_event();
    void list_event_admin();
    void list_event_user();
    void print_my_events();
    void print_menu_user();
    void user_mode();
    void admin_mode();
    ~UI();
    void open_file();
    void remove_event_user();
    void run();
};