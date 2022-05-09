#include "Console.h"
#include <stdio.h>
#include <string.h>
#include "tests.h"

Console createConsole(Service* service)
{
    Console console;
    console.service = *service;
    return console;
}

void print_menu()
{
    printf("\n");
    printf(" '0' to EXIT the application\n");
    printf(" '1' to ADD a country\n");
    printf(" '2' to REMOVE a country\n");
    printf(" '3' to UPDATE a country\n");
    printf(" '4' to LIST ALL countries\n");
    printf(" '5' to LIST ALL COUNTRIES WITH A GIVEN STRING\n");
    printf(" '6' to LIST ALL COUNTRIES ON A GIVEN CONTINENT WITH A POPULATION GREATER THAN A GIVEN NUMBER\n");
    printf(" '7' to LIST ALL COUNTRIES ON A GIVEN CONTINENT IN ASCENDING ORDER\n");
    printf(" '8' to UNDO the last action\n");
    printf(" '9' to REDO the last action\n");
    printf(" '100' to TEST all functions\n");
}

void console_add(Console* console)
{
    int all_good = 5;
    char name[57];
    char continent[15];
    float population;
    printf("The name of the country you want to add is:\n");
    scanf("%s", name);
    printf("The continent of the country you want to add is:\n");
    scanf("%s", continent);
    printf("The population (in millions) of the country you want to add is:\n");
    scanf("%f.2", &population);
    all_good = service_add(&console->service, name, continent, population);
    if (all_good == 1)
        printf("Country already exists!\n");
    if (all_good == 2)
        printf("Continent of the country must be one of Europe, America, Africa, Australia or Asia!\n");
    if (all_good == 3)
        printf("Cannot add any more countries because container is full!\n");
}

void console_remove(Console* console)
{
    int all_good = 5;
    char name[57];
    printf("The name of the country you want to remove is:\n");
    scanf("%s", name);
    all_good = service_remove(&console->service, name);
    if (all_good == 1)
        printf("Country does not exist!\n");
}

void console_replace(Console* console)
{
    int all_good = 5;
    int choice;
    printf("Do you want to change or to migrate?\n1 for a complete change\n2 for migrate\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        char name[57];
        char continent[15];
        float population;
        printf("The name of the country you want to replace with is:\n");
        scanf("%s", name);
        printf("The continent of the country you want to replace with is:\n");
        scanf("%s", continent);
        printf("The population (in millions) of the country you want to replace with is:\n");
        scanf("%f.2", &population);
        all_good = service_replace(&console->service, name, continent, population);
        if (all_good == 1)
            printf("Continent of the country must be one of Europe, America, Africa, Australia or Asia!\n");
        if (all_good == 2)
            printf("Country does not exist!\n");
    }
    else if (choice == 2)
    {
        float amount;
        char name_from[57], name_to[57];
        printf("The name of the country you want to migrate from is:\n");
        scanf("%s", name_from);
        printf("The name of the country you want to migrate to is:\n");
        scanf("%s", name_to);
        printf("The population that migrates is:\n");
        scanf("%f", &amount);
        all_good = service_migrate(&console->service, name_from, name_to, amount);
        if (all_good == 1)
            printf("Either country does not exist!\n");
        if (all_good == 2)
            printf("Amount given to migrate larger than the population!\n");
    }
}

void console_print_all(Console* console)
{
    char str[10000] = {0};
    service_get_all(&console->service, str);
    printf("%s", str);
}

void console_print_countries_with_string(Console* console)
{
    char str[100], printing_str[10000] = {0};
    Service new_service;
    printf("The string you want to search after is:\n");
    scanf("%s", str);
    //new_service = service_string_countries(&console->service, str);
    new_service = service_string_countries_2nd_method(&console->service, str);
    service_get_all(&new_service, printing_str);
    printf("%s", printing_str);
    free_service(&new_service);
}

void console_print_countries_on_continent_with_greater_population(Console* console)
{
    char str[100], printing_str[10000] = {0}, choice[100];
    float minimum_population;
    Service new_service;
    printf("The continent you want to search after is:\n");
    scanf("%s", str);
    printf("The minimum amount of millions you want the countries to have is:\n");
    scanf("%f.2", &minimum_population);
    printf("Do you want to sort them ascending or descending with relation to the population? A/D\n");
    scanf("%s", choice);
    if (strcmp(choice, "A") != 0 && strcmp(choice, "D") != 0)
        printf("Invalid choice!\n");
    else{
        if (strcmp(choice, "A") == 0)
            new_service = find_looked_for_countries(&console->service, str, minimum_population, "ascending");
        else
            new_service = find_looked_for_countries(&console->service, str, minimum_population, "descending");
        service_get_all(&new_service, printing_str);
        printf("%s", printing_str);
        free_service(&new_service);
    }
}

void console_print_countries_on_continent_ascending(Console* console)
{
    char str[100], printing_str[10000] = {0};
    Service new_service;
    printf("The continent you want to search after is:\n");
    scanf("%s", str);
    new_service = find_country_on_cont_sorted(&console->service, str);
    service_get_all(&new_service, printing_str);
    printf("%s", printing_str);
    free_service(&new_service);
}

void console_undo(Console* console)
{
    int all_good;
    all_good = execute_undo_service(&console->service);
    if (all_good == 1)
        printf("No more undos or redos left!\n");
}

void console_redo(Console* console)
{
    int all_good;
    all_good = execute_redo_service(&console->service);
    if (all_good == 1)
        printf("No more undos or redos left!\n");
}

void console_run(Console* console)
{
    int done = 1, input;
    while (done == 1)
    {
        print_menu();
        printf(" >>");
        scanf("%d", &input);
        printf("\n");
        if (input == 0)
        {
            free_service(&console->service);
            free_undo_service(&console->service);
            done = 0;
        }
        if (input == 1)
        {
            console_add(console);
        }
        if (input == 2)
        {
            console_remove(console);
        }
        if (input == 3)
        {
            console_replace(console);
        }
        if (input == 4){
            console_print_all(console);
        }
        if (input == 5)
        {
            console_print_countries_with_string(console);
        }
        if (input == 6)
        {
            console_print_countries_on_continent_with_greater_population(console);
        }
        if (input == 7)
        {
            console_print_countries_on_continent_ascending(console);
        }
        if (input == 8)
        {
            console_undo(console);
        }
        if (input == 9)
        {
            console_redo(console);
        }
        if(input==100)
        {
            test_all();
        }
    }
}