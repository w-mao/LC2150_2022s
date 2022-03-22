/*
 * TestPriorityQueue.cpp
 *
 *  Created on: Feb 24, 2022
 *      Author: mao
 */

#include <iostream>
#include "ListPriorityQueue.h"

using namespace std;

template<typename V>
class PriorityElement
{
public:

	PriorityElement(){
		key = 0;
		value = 0;
	}

	PriorityElement(int key, V value){
		this->key = key;
		this->value = value;
	}

	PriorityElement& operator=(const PriorityElement& other){
		this->key = other.key;
		this->value = other.value;

		return *this;
	}


public:
	int key;
	V value;
};

bool operator>(const PriorityElement<int>& e1, const PriorityElement<int>& e2)
{
	return (e1.key > e2.key);
}

bool operator<(const PriorityElement<int>& e1, const PriorityElement<int>& e2)
{
	return (e1.key < e2.key);
}

bool operator==(const PriorityElement<int>& e1, const PriorityElement<int>& e2)
{
	return (e1.key == e2.key);
}

int testPriorityQueue()
{
	ListPriorityQueue<PriorityElement<int>> q;
	q.enqueue(PriorityElement<int>(3, 7));
	q.enqueue(PriorityElement<int>(5, 2));
	q.enqueue(PriorityElement<int>(1, 8));
	q.enqueue(PriorityElement<int>(10, 0));

	PriorityElement<int> el = q.peek();
	cout << "The element's key and value are: " << el.key << " : " << el.value << endl;
	q.dequeue();
	el =q.peek();
	cout << "The element's key and value are: " << el.key << " : " << el.value << endl;

	return 0;
}


