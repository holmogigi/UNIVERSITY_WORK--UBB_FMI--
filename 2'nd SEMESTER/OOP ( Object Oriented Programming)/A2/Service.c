#include "Service.h"
#include <string.h>

/*
  Function that creates the service structure
*/
Service createService(Repository *repository, UndoService* undoService)
{
    Service service;
    service.repo = *repository;
    service.undoService = *undoService;
    return service;
}

/*
  Function that takes care of the add functionality
*/
int service_add(Service* service, char name[], char continent[], float population)
{   int all_good = 5;
    Country country, copy;
    UndoAction undoAction;
    ComplexUndoAction complexUndoAction;

    if (strcmp(continent, "America") == 0 || strcmp(continent, "Europe") == 0 || strcmp(continent, "Africa") == 0 || strcmp(continent, "Australia") == 0 || strcmp(continent, "Asia") == 0){
        country = createCountry(name, continent, population);
        all_good = add(&service->repo, &country);
        if (all_good == 0)
        {complexUndoAction = createComplexUndoAction(1);
            copy = copyCountry(&country);
            undoAction = createUndoAction(&service->repo, add, &copy, repo_remove, &copy);
            add_action(&complexUndoAction, &undoAction);
            push_stack(service->undoService.undo_actions, &complexUndoAction);
            clear(service->undoService.redo_actions);
            *service->undoService.redo_actions = createStackUndoAction();
            return 0;}
        if (all_good == 1) {
            return 1;
        }
        else
            return 3;

    }
    return 2;
}

/*
  Function that takes care of the remove functionality
*/
int service_remove(Service *service, char name[])
{   int all_good = 5, position = -1;
    Country country, copy;
    UndoAction undoAction;
    ComplexUndoAction complexUndoAction;

    country = createCountry(name, "Europe", 1.2f);
    position = repo_search(&service->repo, &country);
    if (position != -1)
        copy = copyCountry(service->repo.objects + repo_search(&service->repo, &country));
    all_good = repo_remove(&service->repo, &country);
    if (all_good == 0)

    {complexUndoAction = createComplexUndoAction(1);
        undoAction = createUndoAction(&service->repo, repo_remove, &copy, add, &copy);
        add_action(&complexUndoAction, &undoAction);
        push_stack(service->undoService.undo_actions, &complexUndoAction);
        clear(service->undoService.redo_actions);
        *service->undoService.redo_actions = createStackUndoAction();
        return 0;
    }
    else
        return 1;
}

/*
  Function that takes care of the repalce/update functionality
*/
int service_replace(Service* service, char name[], char continent[], float population)
{   int all_good = 5;
    char str[100], str2[100];
    Country country, copy, original_copy;
    UndoAction undoAction;
    ComplexUndoAction complexUndoAction;

    if (strcmp(continent, "America") == 0 || strcmp(continent, "Europe") == 0 || strcmp(continent, "Africa") == 0 || strcmp(continent, "Australia") == 0 || strcmp(continent, "Asia") == 0){
        country = createCountry(name, continent, population);

        original_copy = copyCountry(service->repo.objects + repo_search(&service->repo, &country));
        all_good = repo_replace(&service->repo, &country);
        if (all_good == 0)
        { complexUndoAction = createComplexUndoAction(1);
            copy = copyCountry(&country);
            undoAction = createUndoAction(&service->repo, repo_replace, &copy, repo_replace, &original_copy);
            add_action(&complexUndoAction, &undoAction);
            push_stack(service->undoService.undo_actions, &complexUndoAction);
            clear(service->undoService.redo_actions);
            *service->undoService.redo_actions = createStackUndoAction();
            return 0;}
        else
            return 1;}
    else
        return 2;
}

/*
  Function that takes care of the migration functionality
*/
int service_migrate(Service* service, char from_name[], char to_name[], float amount)
{   int all_good = 5;
    int position_1, position_2;
    Country country_from, country_to, country_from_initial_copy, country_to_initial_copy, country_from_final_copy, country_to_final_copy;
    UndoAction undoAction1, undoAction2;
    ComplexUndoAction complexUndoAction;
    country_from = createCountry(from_name, "Europe", 0);
    country_to = createCountry(to_name, "Europe", 0);
    position_1 = repo_search(&service->repo, &country_from);
    position_2 = repo_search(&service->repo, &country_to);
    if (position_1 != -1 && position_2 != -1)
    {country_from_initial_copy = copyCountry(service->repo.objects + position_1);
        country_to_initial_copy = copyCountry(service->repo.objects + position_2);
    }
    all_good = repo_migrate(&service->repo, &country_from, &country_to, amount);
    if (position_1 != -1 && position_2 != -1)
    {country_from_final_copy = copyCountry(service->repo.objects + position_1);
        country_to_final_copy = copyCountry(service->repo.objects + position_2);
    }
    if (all_good == 0)
    { complexUndoAction = createComplexUndoAction(2);
        undoAction1 = createUndoAction(&service->repo, repo_replace, &country_from_final_copy, repo_replace, &country_from_initial_copy);
        undoAction2 = createUndoAction(&service->repo, repo_replace, &country_to_final_copy, repo_replace, &country_to_initial_copy);
        add_action(&complexUndoAction, &undoAction1);
        add_action(&complexUndoAction, &undoAction2);
        push_stack(service->undoService.undo_actions, &complexUndoAction);
        clear(service->undoService.redo_actions);
        *service->undoService.redo_actions = createStackUndoAction();
    }
    return all_good;
}

/*
  Function that takes care of the search by string fuctionality
*/
Service service_string_countries(Service* service, char str[])
{Repository new_repo;
    Service new_service;
    int counter = 0, is_empty = 0;
    new_repo = createRepository();
    if (str[0] == '~'){
        is_empty = 1;
    }
    for (counter = 0; counter < service->repo.number_of_elements; counter++)
    {if ((containsString(service->repo.objects + counter, str) == 1 || is_empty == 1))
            add(&new_repo, &service->repo.objects[counter]);}
    new_service = createService(&new_repo, &service->undoService);
    return new_service;
}

/*
  Function that takes care of the second string match functionality
*/
Service service_string_countries_2nd_method(Service* service, char str[]){
    Repository new_repo;
    Service new_service;
    new_repo = copy_repo(&service->repo);
    int index = 0, is_empty = 0;
    if (str[0] == '~'){
        is_empty = 1;
    }
    for (index = 0; index < service->repo.number_of_elements; index++){
        if (containsString(service->repo.objects + index, str) == 0 && is_empty == 0){
            repo_remove(&new_repo, service->repo.objects + index);
        }
    }
    new_service = createService(&new_repo, &service->undoService);
    return new_service;
}

/*
  Function that return the vector
*/
void service_get_all(Service* service, char str[])
{
    repo_to_String(&service->repo, str);
}

/*
  Function that frees the allocated memory used by the undo function
*/
void free_undo_service(Service* service)
{
    destroy_all_undo_actions(&service->undoService);
}

/*
  Function that frees the allocated memory used by the service function
*/
void free_service(Service* service)
{
    free_repository(&service->repo);

}

/*
  Function that takes care of the find countries by continent
*/
Service find_countries_on_a_given_continent(Service* service, char str[])
{
    Repository new_repo;
    Service new_service;
    int counter, is_empty = 0;
    new_repo = createRepository();
    if (str[0] == '~'){
        is_empty = 1;
    }
    for (counter = 0; counter < service->repo.number_of_elements; counter++)
    {if ((strcmp((service->repo.objects + counter)->continent, str) == 0 || is_empty == 1))
            add(&new_repo, &service->repo.objects[counter]);}
    new_service = createService(&new_repo, &service->undoService);
    return new_service;
}

/*
  Function that takes care of find country with a greater then given population functionality
*/
Service find_countries_with_a_greater_population(Service* service, float amount)
{
    Repository new_repo;
    Service new_service;
    int counter;
    new_repo = createRepository();
    for (counter = 0; counter < service->repo.number_of_elements; counter++)
    {if ((service->repo.objects + counter)->population >= amount)
            add(&new_repo, &service->repo.objects[counter]);}
    new_service = createService(&new_repo, &service->undoService);
    return new_service;
}


/*
  Function that finds and sorts all countries from the vector
*/
Service find_looked_for_countries(Service* service, char str[], float amount, char choice[])
{
    Service first_new_service, second_new_service;
    first_new_service = find_countries_on_a_given_continent(service, str);
    second_new_service = find_countries_with_a_greater_population(&first_new_service, amount);
    free_service(&first_new_service);
    if (strcmp(choice, "ascending") == 0)
        sort_repo(&second_new_service.repo);
    if (strcmp(choice, "descending") == 0)
        sort_repo_reversed(&second_new_service.repo);
    return second_new_service;
}

/*
  Function that takes care of the undo service
*/
int execute_undo_service(Service* service){
    return undo_action(&service->undoService);
}

/*
  Function that takes care of the redo service
*/
int execute_redo_service(Service* service){
    return redo_action(&service->undoService);
}

/*
  Function that find all countries on a continent and sorts the vector alphabetically
*/
Service find_country_on_cont_sorted(Service* service, char str[])
{
    Service new_service;
    new_service = find_countries_on_a_given_continent(service, str);
    sort_repo_alphabetically(&new_service.repo);
    return new_service;
}
