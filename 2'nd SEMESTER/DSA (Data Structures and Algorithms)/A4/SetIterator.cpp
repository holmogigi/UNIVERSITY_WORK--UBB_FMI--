#include "SetIterator.h"
#include "Set.h"

// Best case: Theta(1)
// Worst case: Theta(hash_size)
// Total complexity: O(hash_size)
//  Constructor
SetIterator::SetIterator(const Set& m) : set(m)
{
    if (set.isEmpty())
    {
        this->cur_key=-1;
        this->cur_val= nullptr;
    }
    else
    {
        this->cur_key=0;
        while (set.hash_table[this->cur_key]== nullptr)
            this->cur_key++;
        this->cur_val=set.hash_table[this->cur_key];
    }
}


// Best case: Theta(1)
// Worst case: Theta(hash_size)
// Total complexity: O(hash_size)
//  Increments up to the first element and puts its value in the cur_val variable
void SetIterator::first()
{
    if (set.isEmpty())
        throw std::exception();

    this->cur_key=0;
    while (set.hash_table[this->cur_key]== nullptr)
        this->cur_key++;
    this->cur_val=set.hash_table[this->cur_key];
}


// Best case: Theta(1)
// Worst case: Theta(hash_size)
// Total complexity: O(hash_size)
//  Updates the index and value of the next element in the hash
void SetIterator::next()
{
    if (!valid())
        throw std::exception();

    this->cur_val=this->cur_val->next;
    if (this->cur_val== nullptr)
    {
        this->cur_key++;
        while(this->cur_key < set.m && set.hash_table[this->cur_key]== nullptr)
            this->cur_key++;

        if (this->cur_key==set.m)
            this->cur_key=-1;
        else
            this->cur_val=set.hash_table[this->cur_key];
    }
}


// O(1)
// Returns the current element from the hash
TElem SetIterator::getCurrent()
{
    if (this->cur_key==-1)
        throw std::exception();
    return this->cur_val->val;
}


// O(1)
// Checks to see if the current position is valid
bool SetIterator::valid() const
{
    if (this->cur_key==-1 || this->cur_val== nullptr)
        return false;
    return true;
}



