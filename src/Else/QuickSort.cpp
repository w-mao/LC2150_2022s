/*
 * QuickSort.CPP
 *
 *  Created on: Apr 14, 2022
 *      Author: mao
 */

#include <iostream>
using namespace std;

void quickSortSwapExam(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

int partition (int A[], int low, int high)
{
	int pivot = A[high];
	int i = low;
	int j = high - 1;

	while (true){
		while (i < j && A[j] >= pivot) j--;
		while (i < j && A[i] < pivot) i++;

		if (i >= j) break;
		quickSortSwapExam(A[i], A[j]);

	}
	if (A[i] > A[high])
	{
		quickSortSwapExam(A[i], A[high]);
		return i;
	}
	else
	{
		quickSortSwapExam(A[i+1], A[high]);
		return i + 1;
	}
}

void quickSortExam(int list[], int low, int high)
{
	if (low < high)
	{
		//partition the array
		int pivot = partition(list, low, high);

		//sort the sub arrays independently
		quickSortExam(list, low, pivot - 1);
		quickSortExam(list, pivot + 1, high);
	}
}

int testQuickSortExam()
{
	int a[] = {6, 0, 2, 1, 7, 8, 3, 5};

	cout <<"Input list ...\n";
	for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
		cout <<a[i]<<"\t";
	}
	cout<<endl;

	quickSortExam(a, 0, sizeof(a)/sizeof(a[0])-1); // high = sizeof(a)/sizeof(a[0])-1, postion of the last element

	cout <<"Sorted Element List ...\n";
	for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
		cout <<a[i]<<"\t";
	}
	return 0;
}
void nothing(){
	int a = 0;

}
