#pragma once
#include "Country.h"

typedef struct
{
    Country* objects;
    int capacity;
    int number_of_elements;
} Repository;

Repository createRepository();
Country* getObjects(Repository* p);
int getCapacity(Repository* p);
int getNumberOfElements(Repository* p);
int repo_search(Repository* p, Country* country);
int add(Repository* p, Country* country);
int repo_remove(Repository* p, Country* country);
int repo_replace(Repository* p, Country* country);
int repo_migrate(Repository* p, Country* country_from, Country* country_to, float amount);
void repo_to_String(Repository* p, char str[]);
void free_repository(Repository* p);
void initialise_repo(Repository* p);
void sort_repo(Repository* p);
void sort_repo_alphabetically(Repository* p);
void sort_repo_reversed(Repository* p);
void resize_smaller(Repository* p);
void resize_bigger(Repository* p);
Repository copy_repo(Repository* p);
