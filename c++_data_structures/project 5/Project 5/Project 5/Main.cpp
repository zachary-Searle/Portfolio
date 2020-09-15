// I Zachary Searle have not used any code other than my own (or that in the textbook) for this
//project.I understand that any violation of this disclaimer will result in a 0 for the
//project.

#include"Sort.h"
#include"Timer.h"
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int size = 100000;
	Timer timer = Timer();
	Sort selection = Sort(size);
	Sort insertion = Sort(size);
	Sort merge = Sort(size);
	Sort quick = Sort(size);
	vector<int> vect;
	for (int i = 0; i < 100000; i++) {
		vect.push_back(rand());
	}
	timer.Start();
	selection.SelectionSort();
	timer.End();
	cout << "selection sort took " << timer.DurationInMilliSeconds() << " milliseconds" << endl;
	timer.Start();
	insertion.InsertionSort();
	timer.End();
	cout << "insertion sort took " << timer.DurationInMilliSeconds() << " milliseconds" << endl;
	timer.Start();
	merge.MergeSort(merge.GetArray(), 0, size - 1);
	timer.End();
	cout << "merge sort took " << timer.DurationInMilliSeconds() << " milliseconds" << endl;
	timer.Start();
	quick.QuickSort(quick.GetArray(), 0, size - 1);
	timer.End();
	cout << "quick sort took " << timer.DurationInMilliSeconds() << " milliseconds" << endl;
	timer.Start();
	sort(vect.begin(), vect.end());
	timer.End();
	cout << "algorithm sort took " << timer.DurationInMilliSeconds() << " milliseconds" << endl;
	getchar();
	return 0;
}