#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;

// Best case: Theta(1) ; Worst case: Theta(1) ; Total complexity: O(1)
BagIterator::BagIterator(const Bag& c): bag(c)
{
	this->first();
}

// Best case: Theta(1) ; Worst case: Theta(1) ; Total complexity: O(1)
void BagIterator::first()
{
    this->cur_elem=this->bag.head;
    if (this->cur_elem!= nullptr)
        this->freq=this->bag.head->freq;
}

// Best case: Theta(1) ; Worst case: Theta(1) ; Total complexity: O(1)
void BagIterator::next()
{
	if(!this->valid())
        throw exception();
    if (this->freq==1)
    {
        this->cur_elem = this->cur_elem->next;
        if (this->cur_elem != nullptr)
            this->freq = this->cur_elem->freq;
    }
    else
        {
            this->freq--;
        }
}

// Best case: Theta(1) ; Worst case: Theta(1) ; Total complexity: O(1)
bool BagIterator::valid() const
{
	if (this->cur_elem!= nullptr)
        return true;
	return false;
}

// Best case: Theta(1) ; Worst case: Theta(1) ; Total complexity: O(1)
TElem BagIterator::getCurrent() const
{
    if (!this->valid())
        throw exception();
    return this->cur_elem->val;
}
