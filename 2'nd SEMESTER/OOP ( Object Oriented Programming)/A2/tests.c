#include "Country.h"
#include "Repository.h"
#include "Service.h"
#include "Undo_Redo_Stack.h"
#include "UNDO.h"
#include "UndoAction.h"
#include "Complex_Undo.h"
#include <assert.h>
#include "string.h"
#include "tests.h"
#include <stdio.h>


/*
  Country tester
*/
void test_create_country()
{
    Country country1, country2, country3;
    country1 = createCountry("Romania", "Europe", 22.02f);
    country2 = createCountry("England", "Asia", 44);
    country3 = createCountry("USA", "America", 100.0f);
    assert(strcmp(country1.name,"Romania") == 0);
    assert(strcmp(country1.continent, "Europe") == 0);
    assert(country1.population == 22.02f);
    assert(strcmp(country2.name,"England") == 0);
    assert(strcmp(country2.continent, "Asia") == 0);
    assert(country2.population == 44);
    assert(strcmp(country3.name,"USA") == 0);
    assert(strcmp(country3.continent, "America") == 0);
    assert(country3.population == 100.0f);
    printf("Test create country passed!\n");
}

void test_getters()
{
    Country country1, country2, country3;
    country1 = createCountry("Romania", "Europe", 22.02f);
    country2 = createCountry("England", "Asia", 44);
    country3 = createCountry("USA", "America", 100.0f);
    assert(strcmp(getName(&country1), "Romania") == 0);
    assert(strcmp(getName(&country2), "England") == 0);
    assert(strcmp(getName(&country3), "USA") == 0);
    assert(strcmp(getContinent(&country1), "Europe") == 0);
    assert(strcmp(getContinent(&country2), "Asia") == 0);
    assert(strcmp(getContinent(&country3), "America") == 0);
    assert(getPopulation(&country1) == 22.02f);
    assert(getPopulation(&country2) == 44.00f);
    assert(getPopulation(&country3) == 100.00f);
    printf("Test getters country passed!\n");
}

void test_contains_string()
{
    Country country1, country2, country3;
    country1 = createCountry("Romania", "Europe", 22.02f);
    country2 = createCountry("England", "Asia", 44);
    country3 = createCountry("USA", "America", 100.0f);
    assert(containsString(&country1, "Ro") == 1);
    assert(containsString(&country2, "gl") == 1);
    assert(containsString(&country3, "US") == 1);
    assert(containsString(&country1, "ig") == 0);
    assert(containsString(&country2, "ig") == 0);
    assert(containsString(&country3, "ig") == 0);
    printf("Test contains string passed!\n");
}

void test_cmp_country()
{
    Country country1, country2, country3;
    country1 = createCountry("Romania", "Europe", 22.02f);
    country2 = createCountry("England", "Asia", 44);
    country3 = createCountry("USA", "America", 100.0f);
    assert(cmpCountry(&country1, &country1) == 0);
    assert(cmpCountry(&country2, &country1) == 1);
    assert(cmpCountry(&country2, &country3) == -1);
    printf("Test cmp country passed!\n");
}

void test_cmp_country_alphabetically()
{
    Country country1, country2, country3;
    country1 = createCountry("Romania", "Europe", 22.02f);
    country2 = createCountry("England", "Asia", 44);
    country3 = createCountry("USA", "America", 100.0f);
    assert(cmpCountryName(&country1, &country1) == 0);
    assert(cmpCountryName(&country2, &country1) < 0);
    assert(cmpCountryName(&country3, &country1) >0);
    printf("Test cmp country alphabetically passed!\n");
}

void test_copy_country()
{
    Country country1, country2;
    country1 = createCountry("Romania", "Europe", 22.02f);
    country2 = copyCountry(&country1);
    assert(strcmp(country1.name, country2.name) == 0);
    assert(strcmp(country1.continent, country1.continent) == 0);
    assert(country1.population == country2.population);
    country2.population = 25.05f;
    assert(country1.population != country2.population);
    printf("Test copy country passed!\n");
}

void country_test_all()
{
    test_create_country();
    test_getters();
    test_contains_string();
    test_cmp_country();
    test_cmp_country_alphabetically();
    test_copy_country();
}


/*
  Repository tester
*/
void test_create_repo()
{
    Repository repository;
    repository = createRepository();
    assert(repository.capacity == 2);
    assert(repository.number_of_elements == 0);
    free_repository(&repository);
    printf("Test create repo passed!\n");
}

void test_resizes()
{
    Repository repository;
    repository = createRepository();
    assert(repository.capacity == 2);
    resize_bigger(&repository);
    assert(repository.capacity == 3);
    resize_bigger(&repository);
    assert(repository.capacity == 4);
    resize_bigger(&repository);
    assert(repository.capacity == 6);
    resize_bigger(&repository);
    assert(repository.capacity == 9);
    resize_bigger(&repository);
    assert(repository.capacity == 13);
    resize_smaller(&repository);
    assert(repository.capacity == 9);
    resize_smaller(&repository);
    assert(repository.capacity == 6);
    resize_smaller(&repository);
    assert(repository.capacity == 4);
    free_repository(&repository);
    printf("Test resizes passed!\n");
}

void test_repo_add()
{
    Country country1, country2, country3, country4;
    Repository repository;
    repository = createRepository();
    country1 = createCountry("Romania", "Europe", 22.02f);
    country2 = createCountry("England", "Asia", 44);
    country3 = createCountry("USA", "America", 100.0f);
    assert(add(&repository, &country1) == 0);
    assert(repository.number_of_elements == 1);
    assert(add(&repository, &country2) == 0);
    assert(repository.number_of_elements == 2);
    assert(repository.capacity == 2);
    assert(add(&repository, &country3) == 0);
    assert(repository.number_of_elements == 3);
    assert(repository.capacity == 3);
    assert(add(&repository, &country2) == 1);
    free_repository(&repository);
    printf("Test add repo passed!\n");
}

void test_repo_remove()
{
    Country country1, country2, country3;
    Repository repository;
    repository = createRepository();
    country1 = createCountry("Romania", "Europe", 22.02f);
    country2 = createCountry("England", "Asia", 44);
    country3 = createCountry("USA", "America", 100.0f);
    assert(add(&repository, &country1) == 0);
    assert(add(&repository, &country2) == 0);
    assert(add(&repository, &country3) == 0);
    assert(repository.number_of_elements == 3);
    assert(repo_remove(&repository, &country1) == 0);
    assert(repository.number_of_elements == 2);
    assert(repo_remove(&repository, &country1) == 1);
    assert(repo_remove(&repository, &country2) == 0);
    assert(repository.number_of_elements == 1);
    assert(repo_remove(&repository, &country3) == 0);
    assert(repository.number_of_elements == 0);
    assert(repository.capacity == 3);
    free_repository(&repository);
    printf("Test remove repo passed!\n");
}

void test_repo_replace()
{
    Country country1, country2, country3, country4;
    Repository repository;
    repository = createRepository();
    country1 = createCountry("Romania", "Europe", 22.02f);
    country2 = createCountry("England", "Asia", 44);
    country3 = createCountry("USA", "America", 100.0f);
    assert(add(&repository, &country1) == 0);
    assert(add(&repository, &country2) == 0);
    assert(add(&repository, &country3) == 0);
    country1 = createCountry("Romania", "Europe", 69.69f);
    country2 = createCountry("England", "Asia", 4.20f);
    country3 = createCountry("USA", "America", 1336.99f);
    assert(repo_replace(&repository, &country1) == 0);
    assert(repo_replace(&repository, &country2) == 0);
    assert(repo_replace(&repository, &country3) == 0);
    country4 = createCountry("Hungary", "Europe", 0.10f);
    assert(repo_replace(&repository, &country4) == 1);
    assert(repository.objects->population == 69.69f);
    assert((repository.objects + 1)->population == 4.20f);
    assert((repository.objects + 2)->population == 1336.99f);
    free_repository(&repository);
    printf("Test repo replace passed!\n");
}

void test_repo_migrate()
{
    Country country1, country2, country3, country4;
    Repository repository;
    repository = createRepository();
    country1 = createCountry("Romania", "Europe", 22.02f);
    country2 = createCountry("England", "Asia", 44);
    country3 = createCountry("USA", "America", 100.0f);
    country4 = createCountry("Hungary", "Europe", 0.10f);
    assert(add(&repository, &country1) == 0);
    assert(add(&repository, &country2) == 0);
    assert(add(&repository, &country3) == 0);
    assert(repo_migrate(&repository, &country1, &country2, 10) == 0);
    assert(repository.objects->population == 12.02f);
    assert((repository.objects + 1)->population == 54);
    assert(repo_migrate(&repository, &country1, &country2, 20) == 2);
    assert(repo_migrate(&repository, &country4, &country2, 0.001f) == 1);
    assert(repo_migrate(&repository, &country1, &country4, 0.001f) == 1);
    free_repository(&repository);
    printf("Test repo migrate passed!\n");
}

void repo_test_all()
{
    test_create_repo();
    test_resizes();
    test_repo_add();
    test_repo_remove();
    test_repo_replace();
    test_repo_migrate();
}


/*
  Service tester
*/
void test_service_add()
{
    Service service;
    Repository repository;
    UndoService undoService;
    StackUndoAction undo_actions, redo_actions;
    undo_actions = createStackUndoAction();
    redo_actions = createStackUndoAction();
    undoService = createUndoService(&undo_actions, &redo_actions);
    repository = createRepository();
    service = createService(&repository, &undoService);
    assert(service_add(&service, "Romania", "Europe", 22.02f) == 0);
    assert(service.repo.number_of_elements == 1);
    assert(service_add(&service, "Romania", "Asia", 100.50f) == 1);
    assert(service_add(&service, "Hungary", "East Coast", 0.05f) == 2);
    assert(service_add(&service, "England", "Asia", 44) == 0);
    assert(service.repo.number_of_elements == 2);
    assert(service_add(&service, "USA", "America", 100.0f) == 0);
    assert(service.repo.number_of_elements == 3);
    assert(strcmp(service.repo.objects->name, "Romania") == 0);
    assert(service.repo.objects->population == 22.02f);
    assert(strcmp(service.repo.objects->continent, "Europe") == 0);
    assert(strcmp((service.repo.objects + 1)->name, "England") == 0);
    assert((service.repo.objects + 1)->population == 44.00f);
    assert(strcmp((service.repo.objects + 1)->continent, "Asia") == 0);
    assert(strcmp((service.repo.objects + 2)->name, "USA") == 0);
    assert((service.repo.objects + 2)->population == 100.00f);
    assert(strcmp((service.repo.objects + 2)->continent, "America") == 0);
    free_service(&service);
    free_undo_service(&service);
    printf("Test service add passed!\n");
}

void test_service_remove()
{
    Service service;
    Repository repository;
    UndoService undoService;
    StackUndoAction undo_actions, redo_actions;
    undo_actions = createStackUndoAction();
    redo_actions = createStackUndoAction();
    undoService = createUndoService(&undo_actions, &redo_actions);
    repository = createRepository();
    service = createService(&repository, &undoService);
    assert(service_add(&service, "Romania", "Europe", 22.02f) == 0);
    assert(service_add(&service, "Romania", "Asia", 100.50f) == 1);
    assert(service_add(&service, "Hungary", "East Coast", 0.05f) == 2);
    assert(service_add(&service, "England", "Asia", 44) == 0);
    assert(service_add(&service, "USA", "America", 100.0f) == 0);
    assert(service_remove(&service, "Romania") == 0);
    assert(service.repo.number_of_elements == 2);
    assert(strcmp(service.repo.objects->name, "USA") == 0);
    assert(service_remove(&service, "Romania") == 1);
    assert(service.repo.number_of_elements == 2);
    assert(service_remove(&service, "USA") == 0);
    assert(service.repo.number_of_elements == 1);
    assert(strcmp(service.repo.objects->name, "England") == 0);
    free_service(&service);
    free_undo_service(&service);
    printf("Test service remove passed!\n");
}

void test_service_replace()
{
    Service service;
    Repository repository;
    UndoService undoService;
    StackUndoAction undo_actions, redo_actions;
    undo_actions = createStackUndoAction();
    redo_actions = createStackUndoAction();
    undoService = createUndoService(&undo_actions, &redo_actions);
    repository = createRepository();
    service = createService(&repository, &undoService);
    assert(service_add(&service, "Romania", "Europe", 22.02f) == 0);
    assert(service_add(&service, "England", "Asia", 44) == 0);
    assert(service_add(&service, "USA", "America", 100.0f) == 0);
    assert(service_replace(&service, "Romania", "Asia", 420.20f) == 0);
    assert(strcmp(service.repo.objects->continent, "Asia") == 0);
    assert(service.repo.objects->population == 420.20f);
    assert(service_replace(&service, "Romania", "Narnia", 100.50f) == 2);
    assert(service_replace(&service, "Narnia", "Europe", 100.50f) == 1);
    printf("Test service replace passed!\n");
    free_service(&service);
    free_undo_service(&service);
}

void test_service_migrate()
{
    Service service;
    Repository repository;
    UndoService undoService;
    StackUndoAction undo_actions, redo_actions;
    undo_actions = createStackUndoAction();
    redo_actions = createStackUndoAction();
    undoService = createUndoService(&undo_actions, &redo_actions);
    repository = createRepository();
    service = createService(&repository, &undoService);
    assert(service_add(&service, "Romania", "Europe", 22.02f) == 0);
    assert(service_add(&service, "England", "Asia", 44) == 0);
    assert(service_add(&service, "USA", "America", 100.0f) == 0);
    assert(service_migrate(&service, "Romania", "England", 10) == 0);
    assert(service.repo.objects->population == 12.02f);
    assert((service.repo.objects + 1)->population == 54);
    assert(service_migrate(&service, "Romania", "USA", 10) == 0);
    assert(service_migrate(&service, "Romania", "England", 4) == 2);
    assert(service_migrate(&service, "Romania", "Narnia", 0.02f) == 1);
    printf("Test service migrate passed!\n");
    free_service(&service);
    free_undo_service(&service);
}

void test_service_string_countries()
{
    Service service, new_service;
    Repository repository;
    UndoService undoService;
    StackUndoAction undo_actions, redo_actions;
    undo_actions = createStackUndoAction();
    redo_actions = createStackUndoAction();
    undoService = createUndoService(&undo_actions, &redo_actions);
    repository = createRepository();
    initialise_repo(&repository);
    service = createService(&repository, &undoService);
    new_service = service_string_countries(&service, "Ro");
    assert(new_service.repo.number_of_elements == 1);
    free_service(&new_service);
    new_service = service_string_countries(&service, "g");
    assert(new_service.repo.number_of_elements == 3);
    free_service(&new_service);
    new_service = service_string_countries(&service, "~");
    assert(new_service.repo.number_of_elements == 10);
    free_service(&new_service);
    free_service(&service);
    free_undo_service(&service);
    printf("Test string country passed!\n");
}

void test_find_country_on_continent()
{
    Service service, new_service;
    Repository repository;
    UndoService undoService;
    StackUndoAction undo_actions, redo_actions;
    undo_actions = createStackUndoAction();
    redo_actions = createStackUndoAction();
    undoService = createUndoService(&undo_actions, &redo_actions);
    repository = createRepository();
    initialise_repo(&repository);
    service = createService(&repository, &undoService);
    new_service = find_countries_on_a_given_continent(&service, "Europe");
    assert(new_service.repo.number_of_elements == 2);
    free_service(&new_service);
    new_service = find_countries_on_a_given_continent(&service, "Africa");
    assert(new_service.repo.number_of_elements == 3);
    free_service(&new_service);
    new_service = find_countries_on_a_given_continent(&service, "Asia");
    assert(new_service.repo.number_of_elements == 1);
    free_service(&new_service);
    new_service = find_countries_on_a_given_continent(&service, "Australia");
    assert(new_service.repo.number_of_elements == 2);
    free_service(&new_service);
    free_service(&service);
    free_undo_service(&service);
    printf("Test countries on continent passed!\n");
}

void test_find_countries_with_greater_population()
{
    Service service, new_service;
    Repository repository;
    UndoService undoService;
    StackUndoAction undo_actions, redo_actions;
    undo_actions = createStackUndoAction();
    redo_actions = createStackUndoAction();
    undoService = createUndoService(&undo_actions, &redo_actions);
    repository = createRepository();
    initialise_repo(&repository);
    service = createService(&repository, &undoService);
    new_service = find_countries_with_a_greater_population(&service, 20.02f);
    assert(new_service.repo.number_of_elements == 8);
    free_service(&new_service);
    new_service = find_countries_with_a_greater_population(&service, 1500.50f);
    assert(new_service.repo.number_of_elements == 0);
    free_service(&new_service);
    new_service = find_countries_with_a_greater_population(&service, 150.50f);
    assert(new_service.repo.number_of_elements == 3);
    free_service(&new_service);
    new_service = find_countries_with_a_greater_population(&service, 0.52f);
    assert(new_service.repo.number_of_elements == 10);
    free_service(&new_service);
    free_service(&service);
    free_undo_service(&service);
    printf("Test countries with greater population passed!\n");
}

void test_find_looked_for_countries()
{
    Service service, new_service;
    Repository repository;
    UndoService undoService;
    StackUndoAction undo_actions, redo_actions;
    undo_actions = createStackUndoAction();
    redo_actions = createStackUndoAction();
    undoService = createUndoService(&undo_actions, &redo_actions);
    repository = createRepository();
    initialise_repo(&repository);
    service = createService(&repository, &undoService);
    new_service = find_looked_for_countries(&service, "Europe", 20, "ascending");
    assert(new_service.repo.number_of_elements == 1);
    free_service(&new_service);
    new_service = find_looked_for_countries(&service, "Africa", 20.50f, "ascending");
    assert(new_service.repo.number_of_elements == 3);
    assert(new_service.repo.objects->population < (new_service.repo.objects + 1)->population);
    assert((new_service.repo.objects + 1)->population < (new_service.repo.objects + 2)->population);
    free_service(&new_service);
    new_service = find_looked_for_countries(&service, "America", 44.40f, "ascending");
    assert(new_service.repo.number_of_elements == 2);
    assert(new_service.repo.objects->population < (new_service.repo.objects + 1)->population);
    free_service(&new_service);
    free_service(&service);
    free_undo_service(&service);
    printf("Test looked for countries passed!\n");

}

void test_find_country_on_continent_sorted()
{
    Service service, new_service;
    Repository repository;
    UndoService undoService;
    StackUndoAction undo_actions, redo_actions;
    undo_actions = createStackUndoAction();
    redo_actions = createStackUndoAction();
    undoService = createUndoService(&undo_actions, &redo_actions);
    repository = createRepository();
    initialise_repo(&repository);
    service = createService(&repository, &undoService);
    new_service = find_country_on_cont_sorted(&service, "Europe");
    assert(new_service.repo.number_of_elements == 2);
    assert(strcmp(new_service.repo.objects->name, (new_service.repo.objects + 1)->name));
    free_service(&new_service);
    new_service = find_countries_on_a_given_continent(&service, "Africa");
    assert(new_service.repo.number_of_elements == 3);
    assert(strcmp(new_service.repo.objects->name, (new_service.repo.objects + 1)->name));
    assert(strcmp((new_service.repo.objects + 1)->name, (new_service.repo.objects + 2)->name));
    free_service(&new_service);
    new_service = find_countries_on_a_given_continent(&service, "Asia");
    assert(new_service.repo.number_of_elements == 1);
    free_service(&new_service);
    new_service = find_countries_on_a_given_continent(&service, "Australia");
    assert(new_service.repo.number_of_elements == 2);
    assert(strcmp(new_service.repo.objects->name, (new_service.repo.objects + 1)->name));
    free_service(&new_service);
    free_service(&service);
    free_undo_service(&service);
    printf("Test countries on continent sorted passed!\n");
}

void test_service_all()
{
    test_service_add();
    test_service_remove();
    test_service_replace();
    test_service_migrate();
    test_service_string_countries();
    test_find_country_on_continent();
    test_find_countries_with_greater_population();
    test_find_looked_for_countries();
    test_find_country_on_continent_sorted();
}


/*
  UNDO tester
*/
void test_create_undo_action()
{
    UndoAction undoAction;
    Repository repository;
    Country country;
    country = createCountry("Romania", "Europe", 50.50f);
    undoAction =createUndoAction(&repository, add, &country, repo_remove, &country);
    assert(undoAction.repository == &repository);
    assert(undoAction.function == add);
    assert(undoAction.inverse_function == repo_remove);
    assert(undoAction.object.population == 50.50f);
    assert(undoAction.inverse_object.population == 50.50f);
    printf("Test create undo action passed!\n");
}

void test_undo_redo()
{
    UndoAction undoAction, second_undo_action;
    Repository repository;
    Country country, another_country;
    repository = createRepository();
    country = createCountry("Romania", "Europe", 50.50f);
    another_country = createCountry("Romania", "Europe", 69.69f);
    undoAction =createUndoAction(&repository, repo_remove, &country, add, &country);
    assert(executeUndo(&undoAction) == 0);
    assert(executeUndo(&undoAction) == 1);
    assert(repository.number_of_elements == 1);
    assert(executeRedo(&undoAction) == 0);
    assert(repository.number_of_elements == 0);
    assert(executeRedo(&undoAction) == 1);
    second_undo_action = createUndoAction(&repository, repo_replace, &country, repo_replace, &another_country);
    assert(executeUndo(&undoAction) == 0);
    assert(executeUndo(&second_undo_action) == 0);
    assert(repository.objects->population == 69.69f);
    assert(executeRedo(&second_undo_action) == 0);
    assert(repository.objects->population == 50.50f);
    free_repository(&repository);
    printf("Test undo action passed!\n");
}

void test_undo_action_all()
{
    test_create_undo_action();
    test_undo_redo();
}


/*
  Undo_Redo_Stack tester
*/
void test_create_destroy_stack_undo_action()
{
    StackUndoAction stackUndoAction;
    stackUndoAction = createStackUndoAction();
    assert(stackUndoAction.length == 0);
    clear(&stackUndoAction);
    printf("Test create destroy stack undo action passed!\n");
}

void test_push_stack()
{
    ComplexUndoAction complexUndoAction, complexUndoAction1, complexUndoAction2, complexUndoAction3;
    StackUndoAction stackUndoAction;
    complexUndoAction = createComplexUndoAction(1);
    complexUndoAction1 = createComplexUndoAction(2);
    stackUndoAction = createStackUndoAction();
    push_stack(&stackUndoAction, &complexUndoAction);
    assert(stackUndoAction.length == 1);
    assert(stackUndoAction.complexUndoActions->capacity == 1);
    push_stack(&stackUndoAction, &complexUndoAction1);
    assert(stackUndoAction.length == 2);
    assert((stackUndoAction.complexUndoActions + 1)->capacity == 2);
    complexUndoAction2 = pop_stack(&stackUndoAction);
    assert(stackUndoAction.length == 1);
    assert(complexUndoAction2.capacity == 2);
    complexUndoAction3 = pop_stack(&stackUndoAction);
    assert(stackUndoAction.length == 0);
    assert(complexUndoAction3.capacity == 1);
    clear(&stackUndoAction);
    assert(stackUndoAction.length == 0);
    printf("Test push stack undo action passed!\n");
    destroyComplexUndoAction(&complexUndoAction2);
    destroyComplexUndoAction(&complexUndoAction3);

}

void test_stack_undo_action_all()
{
    test_create_destroy_stack_undo_action();
    test_push_stack();
}


/*
  UndoAction tester
*/
void test_create_undo_action2()
{
    UndoAction undoAction;
    Repository repository;
    Country country;
    country = createCountry("Romania", "Europe", 50.50f);
    undoAction =createUndoAction(&repository, add, &country, repo_remove, &country);
    assert(undoAction.repository == &repository);
    assert(undoAction.function == add);
    assert(undoAction.inverse_function == repo_remove);
    assert(undoAction.object.population == 50.50f);
    assert(undoAction.inverse_object.population == 50.50f);
    printf("Test create undo action passed!\n");
}

void test_undo_redo2()
{
    UndoAction undoAction, second_undo_action;
    Repository repository;
    Country country, another_country;
    repository = createRepository();
    country = createCountry("Romania", "Europe", 50.50f);
    another_country = createCountry("Romania", "Europe", 69.69f);
    undoAction =createUndoAction(&repository, repo_remove, &country, add, &country);
    assert(executeUndo(&undoAction) == 0);
    assert(executeUndo(&undoAction) == 1);
    assert(repository.number_of_elements == 1);
    assert(executeRedo(&undoAction) == 0);
    assert(repository.number_of_elements == 0);
    assert(executeRedo(&undoAction) == 1);
    second_undo_action = createUndoAction(&repository, repo_replace, &country, repo_replace, &another_country);
    assert(executeUndo(&undoAction) == 0);
    assert(executeUndo(&second_undo_action) == 0);
    assert(repository.objects->population == 69.69f);
    assert(executeRedo(&second_undo_action) == 0);
    assert(repository.objects->population == 50.50f);
    free_repository(&repository);
    printf("Test undo action passed!\n");
}

void test_undo_action_all2()
{
    test_create_undo_action2();
    test_undo_redo2();
}


/*
  Complex_Undo tester
*/
void test_create_complex_undo_action()
{
    ComplexUndoAction complexUndoAction;
    complexUndoAction = createComplexUndoAction(7);
    assert(complexUndoAction.number_of_elements == 0);
    assert(complexUndoAction.capacity == 7);
    destroyComplexUndoAction(&complexUndoAction);
    complexUndoAction = createComplexUndoAction(1);
    assert(complexUndoAction.number_of_elements == 0);
    assert(complexUndoAction.capacity == 1);
    destroyComplexUndoAction(&complexUndoAction);
    printf("Test create complex undo action passed!\n");
}

void test_complex_undo_action()
{
    Repository repository;
    UndoAction undoAction, undoAction1;
    ComplexUndoAction complexUndoAction;
    Country country, country2;
    repository = createRepository();
    complexUndoAction = createComplexUndoAction(2);
    country = createCountry("Romania", "Europe", 19.19f);
    country2 = createCountry("SouthAfrica", "Africa", 100.50f);
    undoAction = createUndoAction(&repository, repo_remove, &country, add, &country);
    add_action(&complexUndoAction, &undoAction);
    assert(complexUndoAction.number_of_elements == 1);
    undoAction1 = createUndoAction(&repository, repo_remove, &country2, add, &country2);
    add_action(&complexUndoAction, &undoAction1);
    assert(complexUndoAction.number_of_elements == 2);
    complex_undo_actions(&complexUndoAction);
    assert(repository.number_of_elements == 2);
    complex_redo_actions(&complexUndoAction);
    assert(repository.number_of_elements == 0);
    destroyComplexUndoAction(&complexUndoAction);
    free_repository(&repository);
    printf("Test complex undo action passed!\n");
}

void test_complex_undo_action_all()
{
    test_create_complex_undo_action();
    test_complex_undo_action();
}


/*
  TEST ALL
*/
void test_all()
{
    country_test_all();
    repo_test_all();
    test_service_all();
    test_undo_action_all();
    test_stack_undo_action_all();
    test_undo_action_all2();
    test_complex_undo_action_all();
    printf("\n");
    printf("!!!!!!!!!!!!!ALL TESTS DONE!!!!!!!!!!!!!");
    printf("\n");
}
