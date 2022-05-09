#include "Repo.h"

// Function that checks if the vector is full and resizes it, adding the element afterwards
void Repo::add(const TElem& eleme)
{
    this->elem.push_back(eleme);
}

// Function that returns the element from a given index in the vector

TElem Repo::get_elem(int pos)
{
    return this->elem.at(pos);
}

// Function that removes the element from a given position in the vector
void Repo::remove(int pos)
{
    this->elem.erase(this->elem.begin() + pos);
}

// Function that replaces the element from a given index with another given element
void Repo::update(const TElem& eleme, int pos)
{
    this->elem.at(pos)=eleme;
}