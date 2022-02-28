/*
 * TestVariousSortingMethods.cpp
 *
 *  Created on: Jan 5, 2022
 *      Author: mao
 */


#include<iostream>
using namespace std;

int SIZE = 0;

/*
 * Bubble Sort
 */
void bubbleSort(double list[], int listSize)
{
	int tmp;

	for(int i = 0; i < listSize - 1; i++) {
		for(int j = 0; j < listSize - i - 1; j++)
		{
			if(list[j] > list[j+1]) {
				tmp = list[j];
				list[j] = list[j+1];
				list[j+1] = tmp;
			}
		}
	}
}

/*
 * Selection Sort
 */
void selectionSort(double list[], int listSize)
{
	for (int i = 0; i < listSize - 1; i++)
	{
		// Find the minimum in the list[i..listSize-1]
		double currentMin = list[i];
		int currentMinIndex = i;

		for (int j = i + 1; j < listSize; j++)
		{
			if (currentMin > list[j])
			{
				currentMin = list[j];
				currentMinIndex = j;
			}
		}

		// Swap list[i] with list[currentMinIndex] if necessary;
		if (currentMinIndex != i)
		{
			list[currentMinIndex] = list[i];
			list[i] = currentMin;
		}


		for(int i = 0; i < 8; i++) {
			cout <<list[i]<<"\t";
		}
		cout << endl;
	}
}

/*
 * Insertion Sort
 */
void insertionSort(double list[], int listSize) {

	int key, j;

	for(int i = 1; i<listSize; i++) {
		key = list[i];//take value
		j = i;
		while(j > 0 && list[j-1]>key) {
			list[j] = list[j-1];
			j--;
		}
		list[j] = key;   //insert in right place

	}
}

/*
 * Quicksort algorithm
 */

// Swap two elements - Utility function
void quickSortSwap(double* a, double* b)
{
	double t = *a;
	*a = *b;
	*b = t;
}


int quickSortPartition (double list[], int low, int high)
{
	// partition the array using last element as pivot
	double pivot = list[high];
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++)
	{
		//if current element is smaller than pivot, increment the low element
		//swap elements at i and j
		if (list[j] <= pivot)
		{
			i++; // increment index of smaller element
			quickSortSwap(&list[i], &list[j]);
		}
	}

	quickSortSwap(&list[i + 1], &list[high]);

	return (i + 1);
}

void quickSort(double list[], int low, int high)
{
	if (low < high)
	{
		//partition the array
		int pivot = quickSortPartition(list, low, high);

		//sort the sub arrays independently
		quickSort(list, low, pivot - 1);
		quickSort(list, pivot + 1, high);
	}
}

/*
 * Merge sort algorithm
 */

void merge(double list[], int left, int mid, int right)
{
	int subListOne = mid - left + 1;
	int subListTwo = right - mid;

	// Create temporary arrays using pointers
	double *leftList = new double[subListOne];
	double *rightList = new double[subListTwo];

	// Copy data to temporary arrays leftList[] and rightList[]
	for (int i = 0; i < subListOne; i++)
		leftList[i] = list[left + i];
	for (int j = 0; j < subListTwo; j++)
		rightList[j] = list[mid + 1 + j];

	int indexOfSubListOne = 0; // Initial index of first sub list
	int indexOfSubListTwo = 0; // Initial index of second sub list
	int indexOfMergedList = left; // Initial index of merged list

	// Merge the temporary lists back into list[left..right]
	while (indexOfSubListOne < subListOne && indexOfSubListTwo < subListTwo) {
		if (leftList[indexOfSubListOne] <= rightList[indexOfSubListTwo]) {
			list[indexOfMergedList] = leftList[indexOfSubListOne];
			indexOfSubListOne++;
		}
		else {
			list[indexOfMergedList] = rightList[indexOfSubListTwo];
			indexOfSubListTwo++;
		}
		indexOfMergedList++;
	}
	// Copy the remaining elements of left[], if there are any
	while (indexOfSubListOne < subListOne) {
		list[indexOfMergedList] = leftList[indexOfSubListOne];
		indexOfSubListOne++;
		indexOfMergedList++;
	}
	// Copy the remaining elements of right[], if there are any
	while (indexOfSubListTwo < subListTwo) {
		list[indexOfMergedList] = rightList[indexOfSubListTwo];
		indexOfSubListTwo++;
		indexOfMergedList++;
	}
}


void mergeSort(double list[], int begin, int end)
{
	if (begin >= end)
		return; // Returns recursively

	int mid = begin + (end - begin) / 2;
	mergeSort(list, begin, mid);
	mergeSort(list, mid + 1, end);
	merge(list, begin, mid, end);
}


/*
 * Test
 */
int testVariousSortingMethods()
{
	double a[] = {6, 0, 2, 1, 7, 8, 3, 5};
	//double a[] = {5.0, 4.0, 3.0, 2.0, 1.0};
	//double a[] = {6.0, 10.0, 2.0, 1.0, 7.0, 8.0, 3.0, 5.0, 9.0, 0.0, 5.0};

	cout <<"Input list ...\n";
	for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
		cout <<a[i]<<"\t";
	}
	cout<<endl;
	SIZE = sizeof(a)/sizeof(a[0]);
	// sizeof(a[0]) returns the data type size (of the first element).
	//bubbleSort(a, sizeof(a)/sizeof(a[0]));
	selectionSort(a, sizeof(a)/sizeof(a[0]));
	//insertionSort(a, sizeof(a)/sizeof(a[0]));
	//quickSort(a, 0, sizeof(a)/sizeof(a[0])-1); // high = sizeof(a)/sizeof(a[0])-1, postion of the last element
	//mergeSort(a, 0, sizeof(a)/sizeof(a[0])-1);
	cout <<"Sorted Element List ...\n";
	for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
		cout <<a[i]<<"\t";
	}
	return 0;
}

