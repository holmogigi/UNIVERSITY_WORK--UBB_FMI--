#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;

// Theta(1)
MapIterator::MapIterator(const Map& d) : map(d)
{
    this->current=0;
}

// Theta(1)
void MapIterator::first()
{
    this->current=0;
}

// Theta(1)
void MapIterator::next()
{
    if(!valid())
    {
        throw exception();
    }
    else
        this->current++;
}

// Theta(1)
TElem MapIterator::getCurrent() const
{
    if (!valid())
    {
        throw exception();
    }
    return this->map.elements[this->current];
}

// Theta(1)
bool MapIterator::valid() const {
    if (this->current < this->map.size())
        return true;
    else
        return false;
}