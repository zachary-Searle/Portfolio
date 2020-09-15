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
	if(is_item())
	curr = curr->next;
}

bool Iterator::operator!=(Iterator &other)
{
	return (curr != other.curr);
}

bool Iterator::is_item()
{
	return (curr != nullptr);
}
