#include "Set.h"
#include "SetIterator.h"
#include <math.h>

// 0(hash_size)
// Constructor
Set::Set()
{
    this->m=10;
    this->hash_size=0;
    this->hash_table= new Node*[m];
    for (int i=0;i<m;i++)
        this->hash_table[i]= nullptr;
}


// 0(1)
// Hash function(division method) used to get the hash of an element
int Set::h(TElem elem) const
{
    return abs(elem%m);
}


// 0(hash_size)
// Resize function used for increasing the size of the hash table when the hash size divided by m(capacity) is < 0.9
void Set::resize(int new_cap)
{
    Node** new_hash=new Node*[new_cap];
    for (int i=0;i<new_cap;i++)
        new_hash[i]= nullptr;

    int old_m=m;
    this->m=new_cap;
    for (int i=0;i<old_m;i++)
    {
        auto cur=this->hash_table[i];
        while (cur!= nullptr)
        {
            auto prev=cur;
            int pos= h(cur->val);
            Node* new_node=new Node;
            new_node->next=new_hash[pos];
            new_node->val=cur->val;
            new_hash[pos]=new_node;
            cur=cur->next;
            delete prev;
        }
    }
    delete []this->hash_table;
    this->hash_table=new_hash;
}


// 0(hash_size)
// Adding an element and resizeing if necessary
bool Set::add(TElem elem)
{
    if (search(elem))
        return false;

    if ((float)hash_size/(float)m >= ALPHA)
        resize(2*m);

    int pos=h(elem);
    auto new_node=new Node;
    new_node->val=elem;
    new_node->next=this->hash_table[pos];
    this->hash_table[pos]=new_node;
    this->hash_size++;

    return true;
}


// 0(hash_size)
// Removing an element from the hash table
bool Set::remove(TElem elem)
{
    if (size()==0)
        return false;

    auto cur=this->hash_table[h(elem)];
    Node* prev= nullptr;
    while (cur!= nullptr)
    {
        if (cur->val==elem)
        {
            if (prev==nullptr)
            {
                this->hash_table[h(elem)]=cur->next;
                delete cur;
            }
            else
            {
                prev->next=cur->next;
                delete cur;
            }
            this->hash_size--;
            return true;
        }
        prev=cur;
        cur=cur->next;
    }
    return false;
}


// 0(hash_size)
// Searching for an element in the hash
bool Set::search(TElem elem) const
{
    if (size()==0)
        return false;
    auto cur=this->hash_table[h(elem)];
    while(cur!= nullptr)
    {
        if (cur->val==elem)
            return true;
        cur=cur->next;
    }
    return false;
}


// 0(1)
int Set::size() const
{
    return hash_size;
}


// 0(1)
bool Set::isEmpty() const
{
    if (size()==0)
        return true;
    return false;
}


// 0(hash_size)
// Destructor
Set::~Set()
{
    for (int i=0;i<m;i++)
    {
        auto cur=this->hash_table[i];
        while (cur!= nullptr)
        {
            auto prev=cur;
            cur=cur->next;
            delete prev;
        }
    }
    delete []this->hash_table;
}


// 0(hash_size)
SetIterator Set::iterator() const
{
	return SetIterator(*this);
}
