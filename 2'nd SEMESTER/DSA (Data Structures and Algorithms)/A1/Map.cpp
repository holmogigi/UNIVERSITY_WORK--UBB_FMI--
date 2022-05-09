#include "Map.h"
#include "MapIterator.h"

Map::Map()
{
    this->capacity=2;
    this->nr_elem=0;
    this->elements=new TElem[capacity];
}

Map::~Map()
{
    delete[] this->elements;
}

// Best case: Theta(1) ; Worst case: Theta(size) ; Total complexity: O(size)
TValue Map::add(TKey c, TValue v)
{
    if (size()== this->capacity)
    {
        resize();
    }
    if(search(c)!=NULL_TVALUE)
    {
        int pos=-1;
        for(int i=0;i<size()&&pos==-1;i++)
        {
            if(this->elements[i].first==c)
                pos=i;
        }
        TValue old_value;
        old_value= this->elements[pos].second;
        this->elements[pos].second=v;
        return old_value;
    }
    this->elements[size()].first=c;
    this->elements[size()].second=v;
    this->nr_elem++;
    return NULL_TVALUE;
}

// Best case: Theta(1) ; Worst case: Theta(size) ; Total complexity: O(size)
TValue Map::search(TKey c) const
{
    for(int i=0;i<size();i++)
    {
        if(this->elements[i].first==c)
            return this->elements[i].second;
    }
    return NULL_TVALUE;
}

// Best case: Theta(1) ; Worst case: Theta(size) ; Total complexity: O(size)
TValue Map::remove(TKey c)
{
    if (search(c) != NULL_TVALUE)
    {
        int pos=-1;
        for(int i=0;i<size()&&pos==-1;i++)
        {
            if(this->elements[i].first==c)
                pos=i;
        }
        TValue old_value;
        old_value= this->elements[pos].second;
        this->elements[pos]=this->elements[size()-1];
        this->nr_elem--;
        return old_value;
    }
    return NULL_TVALUE;
}

// Theta(1)
int Map::size() const
{
    return this->nr_elem;
}

// Theta(1)
bool Map::isEmpty() const
{
    if (this->nr_elem==0)
        return true;
    return false;
}

// Theta(1)
MapIterator Map::iterator() const
{
    return MapIterator(*this);
}

// O(size)
void Map::resize()
{
    this->capacity+=10;
    TElem* new_elem= new TElem[this->capacity];
    for(int i=0;i<size();i++)
        new_elem[i]= this->elements[i];
    delete this->elements;
    this->elements=new_elem;
}

void Map::replaceAll(Transformer t)
{
    for(int i=0;i<size();i++)
    {
        this->elements[i].second=t(this->elements[i].first, this->elements[i].second);
    }
}


