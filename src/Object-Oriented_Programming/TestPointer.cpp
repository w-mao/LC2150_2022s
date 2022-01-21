/*
 * TestPointer.cpp
 *
 *  Created on: Dec 28, 2021
 *      Author: mao
 */


#include <iostream>
using namespace std;

int testPointer()
{
	int count = 5, i;
	int* pCount = &count;

	cout << "The value of count is " << count << endl;
	cout << "The address of count is " << &count << endl;
	cout << "The address of count is " << pCount++ << endl;
	cout << "The value of count is " << *pCount << endl;


	delete pCount;
	cout<< "After executing delete pCount, pointer pCount still keeps the address: " << pCount << endl;

	return 0;
}
