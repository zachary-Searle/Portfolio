#include "Sort.h"

int temp = 0;


Sort::Sort(int size)
{
	data = new int[size];
	this->size = size;
	FillArray();
}


Sort::~Sort()
{
	delete data;
}

void Sort::SelectionSort()
{
	int small = 0;
	for (int i = 0; i < size - 1; i++) {
		small = i;
		for (int j = i + 1; j < size; j++) {
			if (data[j] < data[small]) {
				small = j;
			}
		}
		if (small != i) {
			temp = data[i];
			data[i] = data[small];
			data[small] = temp;
		}
	}
	temp = 0;
}

void Sort::InsertionSort()
{
	for (int i = 1; i < size; i++) {
		int j = i;
		while (j > 0 && data[j] < data[j - 1]) {
			temp = data[j];
			data[j] = data[j - 1];
			data[j - 1] = temp;
			j--;
		}
	}
	temp = 0;
}


void Sort::QuickSort(int data[], int low, int high)
{
	if (high - low == 1 || high - low == 0) {
		return;
	}
	int mid = Partition(data, low, high);
	QuickSort(data, low, mid);
	QuickSort(data, mid + 1, high);
}

int* Sort::GetArray()
{
	return data;
}

int Sort::GetSize()
{
	return size;
}

int Sort::Partition(int data[], int low, int high) {
	int pivot = data[low + (high - low) / 2];
	while (low < high) {
		while (data[low] < pivot) {
			low++;
		}while (data[high] > pivot) {
			high--;
		}if (low >= high) {
			break;
		}
		else {
			temp = data[low];
			data[low] = data[high];
			data[high] = temp;
			low++;
			high--;
		}
	}
	return high;
}

void Sort::Merge(int *data, int low, int high, int mid)
{
	int i, j, k, *temp = new int[high - low + 1];
	i = low;
	k = 0;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (data[i] < data[j])
		{
			temp[k] = data[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = data[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		temp[k] = data[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		temp[k] = data[j];
		k++;
		j++;
	}
	for (i = low; i <= high; i++)
	{
		data[i] = temp[i - low];
	}
}

void Sort::MergeSort(int *data, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		// Split the data into two half.
		MergeSort(data, low, mid);
		MergeSort(data, mid + 1, high);

		// Merge them to get sorted output.
		Merge(data, low, high, mid);
	}
}
void Sort::FillArray()
{
	for (int i = 0; i < size; i++) {
		data[i] = rand();
	}
}
