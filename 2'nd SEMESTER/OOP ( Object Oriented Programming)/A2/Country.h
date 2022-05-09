#pragma once
typedef struct
{
    char name[57];
    char continent[15];
    float population;
} Country;

Country createCountry(char name[], char continent[], float population);
char* getName(Country* p);
char* getContinent(Country* p);
float getPopulation(Country* p);
void toString(Country p, char str[]);
int containsString(Country* country, char str[]);
int cmpCountry(const void* p1, const void* p2);
int cmpCountryName(const void* p1, const void* p2);
Country copyCountry(Country* country);
int cmpCountryReversed(const void * a, const void * b);
