#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <exception>

SortedIndexedList::SortedIndexedList(Relation r)
{
    this->capacity = 5;
    this->elements = new DLLANode[capacity];
    this->first_free = 0;
    this->head = -1;
    this->tail = -1;
    this->relation = r;
    this->elem_nr=0;
}

// AC: theta(1)
int SortedIndexedList::size() const
{
    return elem_nr;
}

// AC: theta(1)
bool SortedIndexedList::isEmpty() const
{
    if (elem_nr == 0)
        return true;
    return false;
}

// AC: theta(1)
TComp SortedIndexedList::getElement(int i) const
{
    if (i < 0 || i >= first_free)
        throw std::exception();
    return this->elements[i].elem;
}

// AC: theta(1)
TComp SortedIndexedList::remove(int i)
{
    if (i <0 || i >= first_free )
        throw std::exception();

    TComp nr= this->elements[i].elem;

    // 1st case: the element that needs to be removed is the first one
    if (i == tail)
    {
        this->elements[this->elements[i].prev].next = -1;
        tail = this->elements[i].prev;
    }

    // 2nd case: the element that needs to be removed is the last one
    else if (i == head)
    {
        this->elements[this->elements[i].next].prev = -1;
        head = this->elements[i].next;
        this->elements[i].elem = this->elements[this->elements[i].next].elem;
        this->elements[i].next = this->elements[this->elements[i].next].next;
    }

    // 3rd case: the element is somewhere else in the list
    else
    {
        this->elements[this->elements[i].next].prev = this->elements[i].prev;
        this->elements[this->elements[i].prev].next = this->elements[i].next;
        this->elements[i].elem = this->elements[this->elements[i].next].elem;
        this->elements[i].next = this->elements[this->elements[i].next].next;
    }

    elem_nr--;
    return nr;
}

// AC: theta(elem_nr)
int SortedIndexedList::search(TComp e) const
{
    int poz = head;
    if (isEmpty())
        return -1;

    while (poz != tail && this->elements[poz].elem != e)
        poz = this->elements[poz].next;

    if (this->elements[poz].elem == e)
        return poz;

    else if (poz == head)
    {
        if(this->elements[poz].elem== e)
            return poz;
    }
    else if (this->elements[this->elements[poz].prev].elem == e)
        return this->elements[poz].prev;

    return -1;
}

// AC: theta(elem_nr)
void SortedIndexedList::add(TComp e)
{

    if (elem_nr == capacity)
    {
        resize();
    }

    int poz = head;
    while (poz != -1 && this->relation(this->elements[poz].elem, e))
        poz = this->elements[poz].next;

    // 1st case add the element to the beggining
    if (poz == -1)
    {
        this->elements[first_free].next = -1;
        this->elements[first_free].prev = tail;
        this->elements[first_free].elem = e;
        if (head != -1)
        {
            this->elements[tail].next = first_free;
            tail = first_free;
        }
        else
        {
            head = first_free;
            tail = first_free;
        }

    }
    // 2nd case add the element to the end
    else if (poz==head)
    {

        this->elements[first_free].elem = e;
        this->elements[first_free].prev = -1;
        this->elements[first_free].next = head;
        this->elements[head].prev = first_free;
        head = first_free;

    }
    // 3rd case add the element to the middle
    else
    {
        int nr = this->elements[poz].prev;
        this->elements[first_free].prev = nr;
        this->elements[first_free].next = poz;
        this->elements[first_free].elem = e;
        this->elements[nr].next = first_free;
        this->elements[poz].prev = first_free;
    }

    first_free++;
    elem_nr++;
}

// AC: theta(1)
ListIterator SortedIndexedList::iterator()
{
    return ListIterator(*this);
}

//destructor
SortedIndexedList::~SortedIndexedList()
{}

// AC: theta(elem_nr)
void SortedIndexedList::resize()
{
    capacity *= 2;
    DLLANode* copy = new DLLANode[capacity];
    for (int i = 0; i < first_free; i++)
        copy[i] = this->elements[i];

    delete[] this->elements;
    this->elements = copy;
}

// AC: theta(elem_nr)
void SortedIndexedList::filter(Condition cond)
{
    int pos=this->head;
    while (pos!=-1)
    {
        if (!cond(this->elements[pos].elem))
        {
            this->elements[this->elements[pos].next].prev = this->elements[pos].prev;
            this->elements[this->elements[pos].prev].next = this->elements[pos].next;
            this->elements[pos].elem = this->elements[this->elements[pos].next].elem;
            this->elements[pos].next = this->elements[this->elements[pos].next].next;
            this->elem_nr--;
        }
        else
            pos=this->elements[pos].next;
    }
}
