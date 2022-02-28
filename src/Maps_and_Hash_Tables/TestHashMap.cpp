/*
 * TestHashMap.cpp
 *
 *  Created on: Feb 26, 2022
 *      Author: mao
 */

#include <iostream>
#include "HashMap.h"
using namespace std;


/*
 * Using a class to handle hash function
 * getKey() is hash function here
 */
class HashFunction
{
public:
	HashFunction(): size(100) {};
	HashFunction(int s): size(s) {};
	int getKey(int value){
		return value % size;
	}
private:
	int size;
};


int testHashMap()
{
	HashMap<int, string, HashFunction> h;
	h.put(1, "abc");
	h.put(5, "edf");
	cout << h.size() << endl;
	cout << h.getValue(1) << endl;

	return 0;
}


