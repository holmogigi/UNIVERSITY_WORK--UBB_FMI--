#pragma once
#include <vector>
#include <utility>
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111);
using namespace std;
class SMMIterator;
class ValueIterator;
typedef bool(*Relation)(TKey, TKey);

struct BSTNode {
    TKey k;
    TValue* elems;

    int size;
    int capacity;

    void add(TValue e);
    std::vector<TValue> getValues() const;
    void resize();
    bool remove(TValue e);
};

class SortedMultiMap {
	friend class SMMIterator;
    private:

    BSTNode* data;
    int* left;
    int* right;
    int head;
    int firstFree;
    int capacity, elems;
    Relation rel;
    void resize();
    void removeNode(int pos, int prev);
    BSTNode createNode(TKey c);

    public:

    // constructor
    SortedMultiMap(Relation r);

	//adds a new key value pair to the sorted multi map
    void add(TKey c, TValue v);

    bool search2(TKey c);

	//returns the values belonging to a given key
    vector<TValue> search(TKey c) const;

	//removes a key value pair from the sorted multimap
	//returns true if the pair was removed (it was part of the multimap), false if nothing is removed
    bool remove(TKey c, TValue v);

    //returns the number of key-value pairs from the sorted multimap
    int size() const;

    //verifies if the sorted multi map is empty
    bool isEmpty() const;

    // returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)	
    SMMIterator iterator() const;

    // destructor
    ~SortedMultiMap();

    // adds all pairs from the given SortedMultiMap, whose key is not in the SortedMultiMap already.
    // returns the number of added pairs
    int addIfNotPresent(SortedMultiMap& smm);
};


