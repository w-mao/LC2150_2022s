/*
 * ComputeFibonacci.cpp
 *
 *  Created on: Dec 27, 2021
 *      Author: mao
 */

#include <iostream>
using namespace std;

// The function for finding the Fibonacci number
int fib(int);

int testFibonacci()
{
	// Prompt the user to enter an integer
	cout << "Enter an index for the Fibonacci number: ";
	int index;
	cin >> index;

	// Display factorial
	cout << "Fibonacci number at index " << index << " is " << fib(index) << endl;
	return 0;
}

// The function for finding the Fibonacci number
int fib(int index)
{
	if (index == 0) // Base case
		return 0;
	else if (index == 1) // Base case
		return 1;
	else // Reduction and recursive calls
		return fib(index - 1) + fib(index - 2);
}





