#include "AVLTree.h"
#include<iostream>
using namespace std;



AVLTree::AVLTree()
{
	root = nullptr;
}

AVLTree::AVLTree(int data) {
	Node *temp = new Node(data);
}

AVLTree::~AVLTree()
{
	if (root == nullptr)
		return;
	DestructorHelp(root);
}

void AVLTree::PreOrderTraversal()
{
	PreHelper(root);
	cout << endl;
}
void AVLTree::PreHelper(Node *temp) {
	if (temp == nullptr)
		return;

	cout << temp->data << " ";
	PreHelper(temp->left);
	PreHelper(temp->right);
}

void AVLTree::DestructorHelp(Node *root) {
	if (root == nullptr) {
		delete root;
		return;
	}
	DestructorHelp(root->left);
	DestructorHelp(root->right);
}

void AVLTree::FixHeight(Node * temp)
{
	Node *temp2 = temp;
	int left = Height(temp2->left);
	int right = Height(temp2->right);
	temp->height = left - right + 1;
}

int AVLTree::Height(Node *temp){
	return (temp == NULL ? -1 : temp->height);
}

int AVLTree::HeightDiff(Node * temp)
{
	return Height(temp->right) - Height(temp->left);
}

Node *AVLTree::Insert(int data)
{
	if (root == nullptr) {
		root = new Node(data);
	}
	else {
		InsertHelper(root, data);
	}
	return root;
}
Node *AVLTree::InsertHelper(Node *temp, int data) {
	if(temp == nullptr)
		return temp = new Node(data);
	if (data < temp->data) {
		temp->left = InsertHelper(temp->left, data);
		Balance(temp);
	}
	if (data > temp->data) {
		temp->right = InsertHelper(temp->right, data);
		Balance(temp);
	}
	return temp;
}

Node *AVLTree::Rightrotate(Node * parent)
{
	Node *temp = parent->left;
	parent->left = temp->right;
	temp->right = parent->left;
	FixHeight(parent);
	FixHeight(temp);
	return temp;
}

Node * AVLTree::Leftrotate(Node * parent)
{
	Node *temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	FixHeight(parent);
	FixHeight(temp);
	return temp;
}

Node * AVLTree::Balance(Node * temp)
{
	FixHeight(temp);
	int balance = temp->height;
	if (balance == 2) {
		if (HeightDiff(temp->right) < 0) {
			temp->right = Rightrotate(temp->right);
			return Leftrotate(temp);
		}
	}
	if (balance == -2) {
		if (HeightDiff(temp->left) > 0) {
			temp->left = Leftrotate(temp->left);
			return Rightrotate(temp);
		}
	}
	return temp;
}
