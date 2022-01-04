#include <iostream>
using namespace std;

// Return the factorial for a specified index
int factorial(int n)
{
	if (n == 0) // Base case
		return 1;
	else
		return n * factorial(n - 1); // Recursive call
}

int factorialLoop(int n)
{
	int fac = 1;
	for (int i = n; i>=1; i--){
		fac *= i;
	}
	return fac;
}


int testFactorial()
{
	// Prompt the user to enter an integer
	cout << "Please enter a non-negative integer: ";
	int n;
	cin >> n;
	
	// Display factorial
	cout << "Factorial of " << n << " is " << factorial(n) << endl;
	cout << "Factorial using loop of " << n << " is " << factorialLoop(n) << endl;
	 
	return 0;
}

// Returns sum of first
// n natural numbers
int computeSum(int n)
{
    if (n <= 1)
        return n;
    return n + computeSum(n - 1);
}

