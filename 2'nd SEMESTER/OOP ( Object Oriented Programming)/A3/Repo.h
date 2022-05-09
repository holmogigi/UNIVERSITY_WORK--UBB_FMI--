#pragma once
#include "Event.h"
#include <vector>
typedef Event TElem;

// Implementation of the stl vector
class Repo
{
protected:
    std::vector<Event> elem;
public:
    Repo() {};
    void add(const TElem& elem);
    TElem get_elem(int pos);
    void remove(int pos);
    void update(const TElem& elem, int pos);
    int getSize() const { return this->elem.size(); }
};
