//============================================================================
// Name        : 2150.cpp
// Author      : Mao
// Version     :
// Copyright   : @Mao
// Description : Welcome to CPSC_2150!
// Updated time: January 4, 2022
//============================================================================

#include <iostream>

#include "Assignments/AllTests.h"
#include "Labs/AllTests.h"

#include "Object-Oriented_Programming/AllTests.h"
#include "Complexity_Analysis/AllTests.h"
#include "Linked_Lists/AllTests.h"
#include "Stacks_and_Queues/AllTests.h"
#include "Recursion/AllTests.h"
//#include "Recursion/ComputeFactorial.h"


using namespace std;

int main() {

	cout << "Welcome to CPSC_2150!" << endl; // prints !!!Hello World!!!


	/*
	*	Object-Oriented_Programming
	*/

	//testGeometricObject(); // Test Inheritance
	//testVisibility();
	//testPointer();
	//testPolymorphism();
	//testGenericMaxValue(); // function template
	//testGenericStack(); // class template

	//testQuotientWithException(); // Test 5/0; quotient with exception
	//testQuotientWithFunction(); // Test 5/0; Quotient with exception from function
	//testQuotientThrowRuntimeError(); // Test 5/0
	//testBadAllocExceptionDemo();


	/*
	*	Complexity_Analysis
	*/

	//testASimpleLoop();


	/*
	*	Linked_Lists
	*/

	//testIntSLList();

	/*
	 * Stacks_and_Queues
	 */
	//testArrayStack();
	//testSinglyLinkedStack();
	//testVectorStack();
	//testListStack();

	//testArrayQueue();
	//testListQueue();


	/*
	*	Recursion
	*/

	//testFactorial();
	//testFibonacci();
	//testPower();
	//testBinarySearch();
	//testTowersOfHanoi();


	// Assign 0
	//testDerivedTriangle();

	/*
	 * Labs
	 */
	//findCombinations();
	//testRepeatDigit ();
	test_mystery ();


	return 0;
}

