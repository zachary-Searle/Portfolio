#pragma once
#include<iostream>

using namespace std;
class Sort
{
public:
	Sort(int size);
	~Sort();
	void SelectionSort();
	void InsertionSort();
	void MergeSort(int *data, int low, int high);
	void QuickSort(int data[], int low, int high);
	int* GetArray();
	int GetSize();
private:
	int size;
	void FillArray();
	int *data;
	int Partition(int data[], int low, int high);
	void Merge(int *data, int low, int high, int mid);
};

