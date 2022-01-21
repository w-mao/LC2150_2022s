/*
 * Quiz1.cpp
 *
 *  Created on: Jan. 19, 2022
 *      Author: mao
 */

#include <iostream>
using namespace std;
int mystery(int a, int b)
{
	if (b == 1)
		cout<< (a) << endl;
	else
	{
		cout << (a * a) << endl;
		return mystery(a + 2, b - 1);
	}
}

int test_mystery ()
{
	mystery(5, 6);
	return 0;
}
