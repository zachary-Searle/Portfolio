#include "Search.h"


Search::Search(int size)
{
	numbers.resize(size);
	InitSortedArray();
}

Search::~Search()
{
}

bool Search::SequentialSearch(int target)
{
	int totalTime = 0;
	time.Start();
	for (int i = 0; i < numbers.size() - 1; i++) {
		if (numbers.at(i) == target) {
			time.End();
			cout << time.DurationInNanoSeconds() << " nanoseconds to search with a sequential search" << endl;
			return true;
		}
		else {
			if(i == numbers.size() - 1)
			time.End();
			cout << time.DurationInNanoSeconds() << " nanoseconds to search with a binary search" << endl;
			return false;
		}
	}
}

bool Search::RecursiveBinarySearch(int target){
	int middle = 0;
	int lowest = 0;
	int highest = 0;
	highest = numbers.size() - 1;
	if (highest >= lowest)
		middle = (highest + lowest) / 2;
	time.Start();
	RecursiveHelper(target, lowest, highest, middle);
	time.End();
	cout << time.DurationInNanoSeconds() << " nanoseconds to search with a recursive binary search" << endl;
	return false;
}
bool Search::RecursiveHelper(int target, int low, int high, int mid)
{
	mid = (low + high) / 2;
	if (high < low) {
		return false;
	}else if (target == numbers.at(mid)) {
		return true;
	}
	else if (target < numbers.at(mid)) {
		high = mid - 1;
		if (RecursiveHelper(target, low, high, mid) == true)
			return true;
		else
			return false;
	}
	else {
		low = mid + 1;
		if (RecursiveHelper(target, low, high, mid) == true)
			return true;
		else
			return false;
	}
	return false;
}

bool Search::IterativeBinarySearch(int target){
	int middle = 0;
	int lowest = 0;
	int highest = 0;
	highest = numbers.size() - 1;
	time.Start();
	while (highest >= lowest) {
		middle = (highest + lowest) / 2;
		if (numbers.at(middle) < target) {
			lowest = middle + 1;
		}
		else if (numbers.at(middle) > target) {
			highest = middle - 1;
		}
		else {
			time.End();
			cout << time.DurationInNanoSeconds() << " nanoseconds to search with an iterative binary search" << endl;
			return true;
		}
	}
	time.End();
	cout << time.DurationInNanoSeconds() << " nanoseconds to search with an iterative binary search" << endl;
	return false;
}

void Search::InitSortedArray(){
	srand(0);
	numbers.at(0) = rand() % 5;
	for (int i = 0; i < numbers.size() - 1; i++) {
		numbers.at(i + 1) = numbers.at(i) + rand() % 5;
	}
	numbers.at(numbers.size() - 1);
}
