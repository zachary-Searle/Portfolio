#include "DynamicArray.h"
#include <stdexcept>
using namespace std;


DynamicArray::DynamicArray()
{
	checks = new Check[INITIAL_CAPACITY];
	capacity = INITIAL_CAPACITY;
	used = 0;
}

void DynamicArray::push_back(const Check & newCheck)
{
	if (capacity == used) {
		Realloc();
	}
	checks[used++] = newCheck;
	used++;
	numChecksCashed++;
}
int DynamicArray::size() const
{
	return used;
}

Check & DynamicArray::at(int index)
{
	if (index >= used || index < 0) {
		throw out_of_range("out of bounds exception");
	}
	else {
		return checks[index];
	}
}

void DynamicArray::Realloc()
{
	capacity *= 2;
	Check * temp = new Check[capacity];
	for (int i = 0; i <= used; i++) {
		temp[i] = checks[i];
	}
	delete[]checks;
	checks = temp;
}


DynamicArray::~DynamicArray()
{
	delete[]checks;
}
