/*
 * ComputeFibonacci.cpp
 *
 *  Created on: Dec 27, 2021
 *      Author: mao
 */

#include <iostream>
using namespace std;

// The function for finding the Fibonacci number
double power(double, unsigned int);

int testPower()
{
	// Prompt the user to enter an integer
	cout << "Enter the value of x: ";
	double x;
	cin >> x;

	cout << "Enter a nonnegative integer n: ";
	unsigned int n;
	cin >> n;

	// Display factorial
	cout << x <<" to the power of "<< n << " equals " << power(x, n) << endl;
	return 0;
}

// The function for finding the Fibonacci number
double power (double x, unsigned int n) {
	if (n == 0)
		return 1.0;
	else
		return x * power(x, n-1);
}





