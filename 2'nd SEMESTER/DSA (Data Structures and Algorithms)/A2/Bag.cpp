#include "Bag.h"
#include "BagIterator.h"
#include <exception>
using namespace std;

Bag::Bag()
{
	this->head= nullptr;
    this->elem_nr=0;
}

// Best case: Theta(1) ; Worst case: Theta(elem_nr) ; Total complexity: O(elem_nr)
void Bag::add(TElem elem)
{
	Node* aux_node= this->search_elem(elem);
    if (aux_node== nullptr)
    {
        aux_node= new Node;
        aux_node->val=elem;
        aux_node->freq=1;
        aux_node->next= this->head;
        this->head=aux_node;
    }
    else
    {
        aux_node->freq++;
    }
    this->elem_nr++;
}

// Best case: Theta(1) ; Worst case: Theta(elem_nr) ; Total complexity: O(elem_nr)
bool Bag::remove(TElem elem)
{
	Node *rem, *prev;
    this->search_cur_prev(elem,prev,rem);
    if (rem!= nullptr)
    {
        if (rem->freq>1)
            rem->freq--;
        else
        {
            if (rem==this->head)
                head=head->next;
            else
            {
                prev->next=rem->next;
            }
            delete rem;
        }
        this->elem_nr--;
        return true;
    }
	return false; 
}

// Best case: Theta(1) ; Worst case: Theta(elem_nr) ; Total complexity: O(elem_nr)
bool Bag::search(TElem elem) const
{
    Node* aux=this->head;
    while(aux!= nullptr)
    {
        if (aux->val==elem)
            return true;
        aux=aux->next;
    }
	return false; 
}

// Best case: Theta(1) ; Worst case: Theta(1) ; Total complexity: O(1)
int Bag::nrOccurrences(TElem elem) const
{
	Node* aux= this->search_elem(elem);
    if (aux== nullptr)
	    return 0;
    return aux->freq;
}

// Best case: Theta(1) ; Worst case: Theta(1) ; Total complexity: O(1)
int Bag::size() const
{
    return this->elem_nr;
}

// Best case: Theta(1) ; Worst case: Theta(1) ; Total complexity: O(1)
bool Bag::isEmpty() const
{
    if (this->elem_nr==0)
        return true;
    return false;
}

// Best case: Theta(1) ; Worst case: Theta(1) ; Total complexity: O(1)
BagIterator Bag::iterator() const
{
	return BagIterator(*this);
}

// Best case: Theta(1) ; Worst case: Theta(elem_nr) ; Total complexity: O(elem_nr)
Bag::~Bag()
{
	Node* aux= this->head, *next;
    while (aux!= nullptr)
    {
        next=aux->next;
        delete aux;
        aux=next;
    }
}

// Best case: Theta(1) ; Worst case: Theta(elem_nr) ; Total complexity: O(elem_nr)
Bag::Node *Bag::search_elem(TElem elem) const
{
    Node* aux_node= this->head;
    while (aux_node!= nullptr)
    {
        if (aux_node->val==elem)
            return aux_node;
        aux_node=aux_node->next;
    }
    return nullptr;
}

// Best case: Theta(1) ; Worst case: Theta(elem_nr) ; Total complexity: O(elem_nr)
void Bag::search_cur_prev(TElem elem, Bag::Node *&prev, Bag::Node *&cur)
{
    prev= nullptr;
    cur=this->head;
    while (cur!= nullptr && cur->val!=elem)
    {
        prev=cur;
        cur=cur->next;
    }
}

int Bag::elementsWithMaximumFrequency() const
{
    Node* aux_node= this->head;
    int max_freq=-1,nr_elem=0;

    while (aux_node!= nullptr)
    {
        if (aux_node->freq>max_freq)
            max_freq=aux_node->freq;
        aux_node=aux_node->next;
    }

    Node* aux_node2= this->head;
    while (aux_node2!= nullptr)
    {
        if (aux_node2->freq==max_freq)
            nr_elem++;
        aux_node2=aux_node2->next;
    }
    return nr_elem;
}
