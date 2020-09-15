#pragma once
#include<iostream>
using namespace std;
class Node
{
public:
	Node() { next = nullptr; }
	~Node();
	Node *next;
	int data;
};
