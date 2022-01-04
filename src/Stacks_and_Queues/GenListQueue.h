/*
 * GenListQueue.h
 *
 *  Created on: Dec 31, 2021
 *      Author: mao
 */

//********************** genQueue.h *************************
// generic queue implemented with doubly linked list
#ifndef DLL_QUEUE
#define DLL_QUEUE

#include <list>
using namespace std;

template<class T>
class ListQueue {
public:
	ListQueue() {
	}
	void clear() {
		lst.clear();
	}
	bool isEmpty() const {
		return lst.empty();
	}
	T& front() {
		return lst.front();
	}
	T dequeue() {
		T el = lst.front();
		lst.pop_front();
		return el;
	}
	void enqueue(const T& el) {
		lst.push_back(el);
	}
private:
	list<T> lst;
};
#endif
