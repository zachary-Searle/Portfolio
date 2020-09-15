#pragma once
#include"Iterator.h"


class List{
protected:
	Node * head = new Node();
public:
	List();
	~List();
	void push_back(const int& value);
	void push_front(const int& value);
	void remove(const int& value);
	Iterator begin();
	Iterator end();
	int size();
	void printList();
};
