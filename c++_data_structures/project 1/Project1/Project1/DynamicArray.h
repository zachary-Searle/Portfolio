#ifndef __DynamicArray__
#define __DynamicArray__

#include "Check.h"

class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();

	void push_back(const Check & newCheck);
	int size() const;
	Check& at(int index);

private:
	Check * checks;
	int capacity;
	int used;
	int numChecksCashed;

	void Realloc();

	static const int INITIAL_CAPACITY = 2;
};

#endif
