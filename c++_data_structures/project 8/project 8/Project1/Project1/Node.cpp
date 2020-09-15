#include "Node.h"



Node::Node()
{
	left = nullptr;
	right = nullptr;
	height = 0;
}

Node::Node(int data) {
	this->data = data;
	left = nullptr;
	right = nullptr;
	height = 0;
}


Node::~Node()
{
}


