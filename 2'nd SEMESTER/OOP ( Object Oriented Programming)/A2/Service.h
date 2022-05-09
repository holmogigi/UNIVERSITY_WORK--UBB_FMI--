#pragma once
#include "Country.h"
#include "Repository.h"
#include "UNDO.h"

typedef struct
{
    Repository repo;
    UndoService undoService;
} Service;


Service createService(Repository* repository, UndoService* undoService);
int service_add(Service* service, char name[], char continent[], float population);
int service_remove(Service* service, char name[]);
int service_replace(Service* service, char name[], char continent[], float population);
void service_get_all(Service* service, char str[]);
Service service_string_countries(Service* service, char str[]);
Service service_string_countries_2nd_method(Service* service, char str[]);
void free_service(Service* service);
void free_undo_service(Service* service);
int service_migrate(Service* service, char from_name[], char to_name[], float amount);
Service find_countries_on_a_given_continent(Service* service, char str[]);
Service find_countries_with_a_greater_population(Service* service, float amount);
Service find_looked_for_countries(Service* service, char str[], float amount, char choice[]);
int execute_undo_service(Service* service);
int execute_redo_service(Service* service);
Service find_country_on_cont_sorted(Service* service, char str[]);
