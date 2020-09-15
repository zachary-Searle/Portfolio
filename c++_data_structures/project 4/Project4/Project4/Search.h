#pragma once
#ifndef _Search_
#define _Search_
#include "Timer.h"
#include<iostream>
#include<vector>
#include<random>

using namespace std;

class Search
{
public:
	vector<int> numbers;
	Search(int size);
	~Search();
	bool SequentialSearch(int target);
	bool RecursiveBinarySearch(int target);
	bool IterativeBinarySearch(int target);
private:
	bool RecursiveHelper(int target, int low, int high, int mid);
	Timer time = Timer();
	void InitSortedArray();
};
#endif // !
