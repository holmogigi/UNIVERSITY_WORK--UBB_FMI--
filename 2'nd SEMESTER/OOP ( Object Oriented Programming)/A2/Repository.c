#include "Repository.h"
#include <string.h>
#include <stdlib.h>

/*
  Function that creates the repository, also known as a dynamic vector in this case
*/
Repository createRepository()
{
    Repository p;
    p.capacity = 2;
    p.number_of_elements = 0;
    Country* array=(Country*)malloc(2*sizeof(Country));
    p.objects = array;
    return p;
}

/*
  Getter for number of elements
*/
int getNumberOfElements(Repository* p)
{
    return p->number_of_elements;
}

/*
  Getter for vector capacity
*/
int getCapacity(Repository* p)
{
    return p->capacity;
}

/*
  Function that searches for a given country in the vector
*/
int repo_search(Repository* p, Country* country)
{
    int number_of_elements = getNumberOfElements(p), counter = 0;
    for (counter = 0; counter < number_of_elements; counter++)
    {
        if (strcmp((p->objects + counter)->name, country->name)== 0){
            return counter;
        }}
    return -1;
}

/*
  Function that resizes the vector if a country was deleted
*/
void resize_smaller(Repository* p)
{
    Country* new_elements;
    new_elements = (Country*) malloc((p->capacity) * 3/4 * sizeof(Country));
    memcpy(new_elements, p->objects, p->number_of_elements * sizeof(Country));
    free_repository(p);
    p->objects = new_elements;
    p->capacity = p->capacity * 3/4;
}

/*
  Function that resizes the vector if a country is added
*/
void resize_bigger(Repository* p)
{
    Country* new_elements;
    new_elements = (Country*)malloc((p->capacity) * 3/2 * sizeof(Country));
    memcpy(new_elements, p->objects, p->number_of_elements* sizeof(Country));
    free_repository(p);
    p->objects = new_elements;
    p->capacity = p->capacity * 3/2;
}

/*
  Function that adds a given country to the vector
*/
int add(Repository* p, Country* country)
{
    int position = 0;
    if (p == NULL)
        return 4;
    if (p->objects == NULL)
        return 4;
    if (p->capacity == p->number_of_elements)
        resize_bigger(p);
    position = repo_search(p, country);
    if (position == -1){
        *(p->objects + p->number_of_elements) = *country;
        p->number_of_elements ++;
        return 0;}
    else return 1;
}

/*
  Function that removes a given country from the vector
*/
int repo_remove(Repository* p, Country* country)
{
    int position = 0, number_of_elements = 0;
    if (p == NULL)
        return 4;
    if (p->objects == NULL)
        return 4;
    if (p->number_of_elements < p->capacity / 2)
        resize_smaller(p);
    number_of_elements = getNumberOfElements(p);
    position = repo_search(p, country);
    if (position != -1)
    {
        p->objects[position] = p->objects[number_of_elements - 1];
        p->number_of_elements--;
        return 0;
    }
    else return 1;
}

/*
  Function that creates a copy of an already existent country
*/
void repo_to_String(Repository* p, char str[])
{
    int counter = 0;
    char intermediary_string[100];
    for (counter = 0; counter < p->number_of_elements; counter++)
    {
        toString(*(p->objects + counter), intermediary_string);
        strcat(str, intermediary_string);
    }

}

/*
  Function that updates a given country in the vector
*/
int repo_replace(Repository* p, Country* country)
{
    int position = 0;
    position = repo_search(p, country);
    if (position != -1){

        *(p->objects + position) = *country;
        return 0;
    }
    else return 1;
}

/*
  Function that migrates the population from one country to the other
*/
int repo_migrate(Repository* p, Country* country_from, Country* country_to, float amount)
{
    int position_from = 0, position_to = 0;
    Country country_from_new, country_to_new, actual_country_from, actual_country_to;
    position_from = repo_search(p, country_from);
    position_to = repo_search(p, country_to);
    if (position_to != -1 && position_from != -1){
        actual_country_from = p->objects[position_from];
        actual_country_to = p->objects[position_to];
        if (actual_country_from.population - amount < 0)
            return 2;
        country_from_new = createCountry(actual_country_from.name, actual_country_from.continent, actual_country_from.population - amount);
        country_to_new = createCountry(actual_country_to.name, actual_country_to.continent, actual_country_to.population + amount);
        repo_replace(p, &country_from_new);
        repo_replace(p, &country_to_new);
        return 0;
    }
    return 1;
}

/*
  Function that frees the allocated memory of the repository
*/
void free_repository(Repository* p)
{
    free(p->objects);
}

/*
  Function that initializes the vector with 10 countries
*/
void initialise_repo(Repository* p)
{
    Country country_1, country_2, country_3, country_4, country_5, country_6, country_7, country_8, country_9, country_10;
    country_1 = createCountry("Romania", "Europe", 19.41f);
    country_2 = createCountry("Germany", "Europe", 83.02f);
    country_3 = createCountry("Nigeria", "Africa", 195.99f);
    country_4 = createCountry("Argentina", "America", 44.49f);
    country_5 = createCountry("USA", "America", 328.25f);
    country_6 = createCountry("China", "Asia", 1393.64f);
    country_7 = createCountry("Australia", "Australia", 24.99f);
    country_8 = createCountry("New Zealand", "Australia", 4.82f);
    country_9 = createCountry("Ghana", "Africa", 29.77f);
    country_10 = createCountry("Uganda", "Africa", 42.72f);
    add(p, &country_1);
    add(p, &country_2);
    add(p, &country_3);
    add(p, &country_4);
    add(p, &country_5);
    add(p, &country_6);
    add(p, &country_7);
    add(p, &country_8);
    add(p, &country_9);
    add(p, &country_10);
}

/*
  Function that sorts the vector in ascending order
*/
void sort_repo(Repository* p)
{
    qsort(p->objects, p->number_of_elements, sizeof(Country), cmpCountry);
}

/*
  Function that sorts the vector in descending order
*/
void sort_repo_reversed(Repository* p)
{
    qsort(p->objects, p->number_of_elements, sizeof(Country), cmpCountryReversed);
}

/*
  Function that sorts the vector alphabetically
*/
void sort_repo_alphabetically(Repository* p)
{
    qsort(p->objects, p->number_of_elements, sizeof(Country), cmpCountryName);
}

/*
  Function that copies the vector
*/
Repository copy_repo(Repository* p)
{
    int number_of_elements;
    Repository new_repository;
    number_of_elements = p->number_of_elements;
    new_repository = createRepository();
    for (int index = 0; index < number_of_elements; index++)
    {
        add(&new_repository, p->objects + index);
    }
    return new_repository;
}
