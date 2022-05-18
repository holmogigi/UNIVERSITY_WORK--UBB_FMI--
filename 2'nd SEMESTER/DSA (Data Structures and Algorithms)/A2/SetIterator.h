#pragma once
#include "Set.h"
#include <iostream>

class SetIterator
{

	friend class Set;
private:

	const Set& set;
	SetIterator(const Set& s);
    int cur_key;
    Set::Node* cur_val;

public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
};


