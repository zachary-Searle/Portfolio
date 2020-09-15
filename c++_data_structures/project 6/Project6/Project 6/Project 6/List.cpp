#include "List.h"
#include<iostream>

using namespace std;

List::List() = default;
List::~List() {
	delete head;
}

void List::push_back(const int & value)
{
	Node *curr = new Node();
	Node *temp = new Node();
	curr->data = value;
	curr->next = NULL;
	temp = head;
	if (head->next == NULL) {
		head = curr;
	}
	else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = curr;
	}
	
}

void List::push_front(const int & value)
{
	Node *curr = new Node();
	curr->data = value;
	curr->next = head;
	Node *temp = head;
	if (temp->next == NULL) {
		head = curr;
	}
	else {
		curr->next = temp->next;
		temp->next = curr;
	}
}

void List::remove(const int & value)
{
	Node *curr = new Node();
	Node *temp = head;
	curr = head->next;
	while (temp != NULL) {
		if (head->next->data == value) {
			head->next = temp->next;
			delete temp;
		}
		else if (temp->next->data == value) {
			curr->next = temp->next;
			delete temp;
		}
		else {
			curr = curr->next;
			temp = temp->next;
		}
	}
}

Iterator List::begin()
{
	cout << head->next->data;
	Iterator begin = Iterator(head->next);
	return begin;
}

Iterator List::end()
{
	Node *temp = new Node();
	temp = head;
	while (temp != NULL) {
		temp = temp->next;
	}
	Iterator end = Iterator(temp);
	return end;
}

int List::size()
{
	Node *temp = new Node();
	temp = head;
	int size = 0;
	if (head == NULL) {
		return 0;
	}
	else {
		while (temp != NULL) {
			size++;
			temp = temp->next;
		}
	}
	cout << size;
	return size;
}

void List::printList()
{
	Node *temp = new Node();
	temp = head->next;
	while (temp != NULL) {
		cout << temp->data << ", ";
		temp = temp->next;
	}
}



