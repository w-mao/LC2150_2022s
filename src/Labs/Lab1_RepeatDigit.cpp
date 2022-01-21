/*
 * Lab1_RepeatDigit.cpp
 *
 *  Created on: Jan. 19, 2022
 *      Author: mao
 */

#include <iostream>
using namespace std;

void repeatDigit(string digits)
{
	if (digits.length() > 0) {
		cout << digits[0] << digits[0];
		//string.substr(): first parameter is the initial position, and the second is the length sliced.
		repeatDigit(digits.substr(1, digits.length()-1));
	}
	else
		return;
}

int testRepeatDigit ()
{

	cout << "Enter a sequence of digits: ";
	string digits; // "12345";
	cin >> digits;
	repeatDigit(digits);
	return 0;

}
