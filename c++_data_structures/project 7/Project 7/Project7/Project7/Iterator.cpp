#include"HashMap.h"
#include<string>

using namespace std;

Iterator::Iterator(int index, Node ** hashArray, int sizeOfArray)
{

	this->index = index;
	this->hashArray = hashArray;
	this->sizeOfArray = sizeOfArray;
	if (hashArray == nullptr)
		current = nullptr;
	else {
		while (hashArray[index] == nullptr)
			index++;
		current = hashArray[index];
	}

}

Iterator::Iterator()
{
	hashArray = NULL;
}

string Iterator::operator*()
{
	return current->word;
}

void Iterator::operator++()
{
	if (current != nullptr)
		current = current->next;
	while (current == nullptr && index < sizeOfArray - 1)
		current = hashArray[++index];
}

bool Iterator::operator!=(Iterator & other)
{
	return (current != other.current);
}

bool Iterator::is_item()
{
	return (current != NULL);
}