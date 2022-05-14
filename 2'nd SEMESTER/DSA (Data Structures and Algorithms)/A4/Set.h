#pragma once
#define NULL_TELEM -111111

#define ALPHA 0.75

typedef int TElem;
class SetIterator;


class Set{

	friend class SetIterator;
    private:

    struct Node
    {
        TElem val;
        Node* next;
    };
    Node** hash_table;
    int m;
    int h(TElem elem) const;
    int hash_size;
    void resize(int new_cap);

    public:
        //implicit constructor
        Set();

        //adds an element to the set
		//returns true if the element was added, false otherwise (if the element was already in the set and it was not added)
        bool add(TElem e);

        //removes an element from the set
		//returns true if e was removed, false otherwise
        bool remove(TElem e);

        //checks whether an element belongs to the set or not
        bool search(TElem elem) const;

        //returns the number of elements;
        int size() const;

        //check whether the set is empty or not;
        bool isEmpty() const;

        //return an iterator for the set
        SetIterator iterator() const;

        // destructor
        ~Set();

};





