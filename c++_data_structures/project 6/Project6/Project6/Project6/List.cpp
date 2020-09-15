#include "List.h"
#include<iostream>

using namespace std;

List::List() = default;
List::~List() {
	Node *temp = new Node();
	temp = head->next;
	if (head->next == nullptr)
		return;
	while (head->next == nullptr) {
		head->next = temp->next;
		delete temp;
		temp == head;
	}
}

void List::push_back(const int & value)
{
	Node *curr = new Node();
	Node *temp = new Node();
	curr->data = value;
	curr->next = nullptr;
	temp = head;
	if (head->next == nullptr) {
		head = curr;
	}
	else {
		while (temp->next != nullptr) {
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
	if (temp->next == nullptr) {
		head = curr;
	}
	else {
		curr->next = temp->next;
		temp->next = curr;
	}
}

void List::remove(const int & value)
{
	Node *temp = head;
	Node *temp2 = head;
	while (temp != nullptr) {
		if(temp->data == value){

			if (temp == head) {
				head = head->next;
				temp2 = head;
				delete temp;
				temp = head;
			}
			else {
				temp2->next = temp->next;
				delete temp;
				temp = temp2->next;
			}
		}
		else {
			temp2 = temp;
			temp = temp->next;
		}
	}
}

Iterator List::begin()
{
	return head;
}

Iterator List::end()
{
	Node *temp = head;
		while (temp) {
			temp = temp->next;
		}
	return temp;
}

int List::size()
{
	Node *temp = new Node();
	temp = head;
	int size = 0;
	if (head == nullptr) {
		return 0;
	}
	else {
		while (temp != nullptr) {
			size++;
			temp = temp->next;
		}
	}
	cout << size;
	return size;
}

void List::printList()
{
	Node *temp = head;
	while (temp != nullptr) {
		cout << temp->data << ", ";
		temp = temp->next;
	}
}



