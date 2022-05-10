#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>
using namespace std;

// AC: theta(1)
ListIterator::ListIterator(const SortedIndexedList& list) : list(list)
{
    if (list.head>=0)
        this->position=list.head;
    else
        this->position=-1;
}

// AC: theta(1)
void ListIterator::first()
{
    if (list.head>=0)
        this->position=list.head;
    else
        this->position=-1;
}

// AC: theta(1)
void ListIterator::next()
{
    if (this->position==-1)
        throw std::exception();
    else
        this->position=list.elements[this->position].next;
}

// AC: theta(1)
bool ListIterator::valid() const
{
    if (this->position==-1)
        return false;
    return true;
}

// AC: theta(1)
TComp ListIterator::getCurrent() const
{
    if (!valid())
        throw std::exception();
    else
        return this->list.elements[this->position].elem;
}


