/*
 * TestUnsortedPriorityQueue.cpp
 *
 *  Created on: Feb 24, 2022
 *      Author: mao
 */

#include <iostream>
#include "UnsortedListPriorityQueue.h"

using namespace std;

template<typename V>
class PriorityElement1
{
public:

	PriorityElement1(){
		key = 0;
		value = 0;
	}

	PriorityElement1(int key, V value){
		this->key = key;
		this->value = value;
	}

	PriorityElement1& operator=(const PriorityElement1& other){
		this->key = other.key;
		this->value = other.value;

		return *this;
	}


public:
	int key;
	V value;
};

bool operator>(const PriorityElement1<int>& e1, const PriorityElement1<int>& e2)
{
	return (e1.key > e2.key);
}

bool operator<(const PriorityElement1<int>& e1, const PriorityElement1<int>& e2)
{
	return (e1.key < e2.key);
}

bool operator==(const PriorityElement1<int>& e1, const PriorityElement1<int>& e2)
{
	return (e1.key == e2.key);
}

int testUnsortedPriorityQueue()
{
	UnsortedListPriorityQueue<PriorityElement1<int>> q;
	q.enqueue(PriorityElement1<int>(3, 7));
	q.enqueue(PriorityElement1<int>(5, 2));
	q.enqueue(PriorityElement1<int>(1, 8));
	q.enqueue(PriorityElement1<int>(10, 0));

	PriorityElement1<int> el = q.peek();
	cout << "The element's key and value are: " << el.key << " : " << el.value << endl;
	q.dequeue();
	el =q.peek();
	cout << "The element's key and value are: " << el.key << " : " << el.value << endl;

	return 0;
}


