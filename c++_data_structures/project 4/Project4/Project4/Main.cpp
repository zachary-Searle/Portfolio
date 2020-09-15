#include<iostream>
#include<vector>
#include"Search.h"

using namespace std;

int main(){
	Search search = Search(1000000);
	// begining array
	cout << "search for an element at the begining of an array " << endl;
	search.SequentialSearch(search.numbers.at(0));
	search.IterativeBinarySearch(search.numbers.at(0));
	search.RecursiveBinarySearch(search.numbers.at(0));
	cout << endl;

	// end array
	cout << "search for an element at the end of an array " << endl;
	search.SequentialSearch(search.numbers.at(search.numbers.size() - 1));
	search.IterativeBinarySearch(search.numbers.at(search.numbers.size() - 1));
	search.RecursiveBinarySearch(search.numbers.at(search.numbers.size() - 1));
	cout << endl;

	// not in array
	cout << "search for an element not in the array " << endl;
	search.SequentialSearch(-5);
	search.IterativeBinarySearch(-5);
	search.RecursiveBinarySearch(-5);
	getchar();
	return 0;
}