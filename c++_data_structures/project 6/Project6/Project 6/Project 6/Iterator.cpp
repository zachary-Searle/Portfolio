#include "Iterator.h"


Iterator::Iterator(Node * start){
	curr = start;
}

Iterator::~Iterator()
{
	delete curr;
}

int Iterator::operator*()
{
	return curr->data;
}

void Iterator::operator++()
{
	if(curr->next != NULL)
	curr = curr->next;
}

bool Iterator::operator!=(Iterator &other)
{
	if (curr == other.curr)
		return true;
	else
		return false;
}

bool Iterator::is_item()
{
	if (curr != NULL)
		return true;
	else
		return false;
}
