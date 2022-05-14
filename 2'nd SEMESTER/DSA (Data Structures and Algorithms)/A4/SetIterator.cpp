#include "SetIterator.h"
#include "Set.h"


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
        while (this->cur_key<set.m and set.hash_table[this->cur_key]== nullptr)
            this->cur_key++;
        this->cur_val=set.hash_table[this->cur_key];
    }
}


void SetIterator::first()
{
    if (set.isEmpty())
        throw std::exception();

    this->cur_key=0;
    while (set.hash_table[cur_key]== nullptr)
        this->cur_key++;

    this->cur_val=set.hash_table[cur_key];
}


void SetIterator::next()
{
    if (!valid())
        throw std::exception();

    this->cur_val=this->cur_val->next;
    if (this->cur_val== nullptr)
    {
        this->cur_key++;
        while(this->cur_key<set.m and set.hash_table[this->cur_key]== nullptr)
            this->cur_key++;

        if (this->cur_key==set.m)
            this->cur_key=-1;
        else
            this->cur_val=set.hash_table[cur_key];
    }
}


TElem SetIterator::getCurrent()
{
    if (this->cur_key==-1)
        throw std::exception();
    return this->cur_val->val;
}

bool SetIterator::valid() const
{
    if (this->cur_key==-1 || this->cur_val== nullptr)
        return false;
    return true;
}



