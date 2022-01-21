/*
 * Lab1_FindCombinations.cpp
 *
 *  Created on: Jan. 19, 2022
 *      Author: mao
 *     Comment: C++ program to find out all combinations of
 *            	positive numbers that add up to a given number
 */

#include <iostream>
using namespace std;

/*
 * 	arr - array to store the combination
 *  index - next location in array
 *  num - given number
 *  reducedNum - reduced number
 */
void findCombinationsByRecursion(int arr[], int index,
		int num, int reducedNum)
{
	// Base condition
	if (reducedNum < 0)
		return;

	// If combination is found, print it
	if (reducedNum == 0)
	{
		for (int i = 0; i < index; i++)
			cout << arr[i] << " ";
		cout << endl;
		return;
	}

	// Find the previous number stored in arr[]
	// It helps in maintaining increasing order
	int prev = (index == 0)? 1 : arr[index-1];

	// note loop starts from previous number
	// i.e. at array location index - 1
	for (int k = prev; k <= num ; k++)
	{
		// next element of array is k
		arr[index] = k;

		// call recursively with reduced number
		findCombinationsByRecursion(arr, index + 1, num,
				reducedNum - k);
	}
}

int findCombinations()
{
	cout << "Enter a number: ";
	int n;
	cin >> n;
	cout << "The combinations of positive numbers that add up to this number are:" << endl;

	// An array is used to store the combinations,
	// and it can contain max n elements.
	int * arr = new int[n];

	//find all combinations
	findCombinationsByRecursion(arr, 0, n, n);

	return 0;
}

