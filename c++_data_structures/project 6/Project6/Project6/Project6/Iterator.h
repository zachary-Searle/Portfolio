#pragma once
#include "Node.h"
class Iterator
{
	
public:
	Iterator(Node *start);
	~Iterator();
	int operator*();
	void operator++();
	bool operator!=(Iterator &other);
	bool is_item();
private:
	Node *curr;
};
