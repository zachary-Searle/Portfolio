#pragma once
#include "Node.h"

class AVLTree
{
public:
	AVLTree();
	~AVLTree();
	void PreOrderTraversal();
//	void Print();
	Node *Insert(int data);
private:
	int Height(Node *temp);
	void PreHelper(Node *temp);
//	void PrintHelper(Node *temp);
	AVLTree(int data);
	Node *InsertHelper(Node *temp, int data);
	Node *Rightrotate(Node *parent);
	Node *Leftrotate(Node *parent);
	Node *Balance(Node *temp);
	void DestructorHelp(Node *root);
	Node *root;
	void FixHeight(Node *temp);
	int HeightDiff(Node *temp);
};

