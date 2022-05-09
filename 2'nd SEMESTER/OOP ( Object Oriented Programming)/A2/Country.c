#include "Country.h"
#include <string.h>
#include <stdio.h>

/*
  Function that creates a country with a given name, continent and population
*/
Country createCountry(char name[], char continent[], float population)
{
    Country p;
    strcpy(p.name, name);
    strcpy(p.continent, continent);
    p.population = population;
    return p;
}

/*
  Name getter
*/
char* getName(Country* p)
{
    return p->name;
}

/*
  Contiennt getter
*/
char* getContinent(Country* p)
{
    return p->continent;
}

/*
  Population getter
*/
float getPopulation(Country* p)
{
    return p->population;
}

/*
  Print function
*/
void toString(Country p, char str[])
{
    sprintf(str, "%s ||  %s  || %.2lf million.\n", p.name, p.continent, p.population);
}

/*
  Function that checks if the first string is present in the second one
*/
int containsString(Country* country, char str[])
{
    if (strstr((country->name), str) != NULL)
        return 1;
    return 0;
}

/*
  Function that compares two countries population
*/
int cmpCountry(const void * a, const void * b)
{
    float first_population, second_population, difference;
    first_population = (*(Country*)a).population;
    second_population = (*(Country*)b).population;
    difference = first_population - second_population;
    if (difference > 0)
        return 1;
    if (difference < 0)
        return -1;
    return 0;
}

/*
  Function that creates a copy of an already existent country
*/
Country copyCountry(Country* country)
{
    char name[100], continent[100];
    float population;
    strcpy(name, country->name);
    strcpy(continent, country->continent);
    population = country->population;
    return createCountry(name, continent, population);
}

/*
  Function that compares two country names
*/
int cmpCountryName(const void * pointer_to_country, const void * pointer_to_2nd_country)
{
    return strcmp((*(Country*)pointer_to_country).name, (*(Country*)pointer_to_2nd_country).name);
}


int cmpCountryReversed(const void * a, const void * b)
{
    float first_population, second_population, difference;
    first_population = (*(Country*)a).population;
    second_population = (*(Country*)b).population;
    difference = first_population - second_population;
    if (difference > 0)
        return -1;
    if (difference < 0)
        return 1;
    return 0;
}
