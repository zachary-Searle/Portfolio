#include "HashMap.h"
#include<iostream>
using namespace std;

//I Zachary Searle claim that all code written in this project is mine and not plagerised

int HashMap::GenerateHash(string key) const
{
	int temp = 0;
	for (int i = 0; i < key.length(); i++) {
		 temp += key.at(i);
	}
	return temp % sizeOfArray;
}

HashMap::HashMap(int size)
{
	hashArray = new Node*[size];
	for (int i = 0; i < size; i++) {
		hashArray[i] = nullptr;
	}
	sizeOfArray = size;
}

HashMap::~HashMap()
{
	for (int i = 0; i < sizeOfArray; i++) {
		if (hashArray[i] != nullptr){
			Node* temp = hashArray[i];
			do{
				hashArray[i] = temp->next;
				delete temp;
				temp = hashArray[i];
			} while (temp != nullptr);
		}
	}
	delete[] hashArray;
}

bool HashMap::IsKeyPresent(string const & key) const
{
	int index = GenerateHash(key);
	if(hashArray[index] == nullptr)
		return false;
	Node *temp = hashArray[index];
	while (temp != nullptr && temp->word != key ) {
		temp = temp->next;
	}
	return (temp != nullptr);
	
}

void HashMap::SetKeyValue(string const & key, int value)
{
	int index = GenerateHash(key);
	if (hashArray[index] == nullptr) {
		hashArray[index] = new Node(key, value);
	}
	else if (!IsKeyPresent(key)) {
		Node *temp2 = new Node(key, value);
		temp2->next = hashArray[index];
		hashArray[index] = temp2;
	}
	else {
		Node *temp = hashArray[index];
		while (temp->word != key)
			temp = temp->next;
		temp->count = value;
	}
}

bool HashMap::GetKeyValue(string const & key, int & value)
{
	if (!IsKeyPresent(key)) {
		value = 0;
		return false;
	}
	else {
		Node *temp = hashArray[GenerateHash(key)];
		while (temp->word != key) {
			temp = temp->next;
		}
		value = temp->count;
		return true;
	}
}

Iterator HashMap::begin()
{
	return Iterator(0, hashArray, sizeOfArray);

}

Iterator HashMap::end()
{
	return Iterator(sizeOfArray, nullptr, sizeOfArray);
}
