/*
 * ListPriorityQueue.h
 *
 *  Created on: Feb 24, 2022
 *      Author: mao
 */

#ifndef HEAPS_AND_PRIORITY_QUEUES_LISTPRIORITYQUEUE_H_
#define HEAPS_AND_PRIORITY_QUEUES_LISTPRIORITYQUEUE_H_

#include <list>

template <class E>
class ListPriorityQueue {
public:
	ListPriorityQueue() {
	}
	int size() const; // number of elements
	bool isEmpty() const; // is the queue empty?
	void enqueue(const E& e); // insert element
	const E& peek() const; // minimum element
	void dequeue(); // remove minimum
private:
	std::list<E> L; // priority queue contents
};

template <class E> // number of elements
int ListPriorityQueue<E>::size() const
{ return L.size(); }

template <class E> // is the queue empty?
bool ListPriorityQueue<E>::isEmpty() const
{ return L.empty(); }

template <class E>			// insert element
void ListPriorityQueue<E>::enqueue(const E& e) {
	typename std::list<E>::iterator p;
	p = L.begin();
	while (p != L.end() && e > *p) ++p;
	L.insert(p, e);					// insert e before p
}

template <class E>			// minimum element
const E& ListPriorityQueue<E>::peek() const
{ return L.front(); }				// minimum is at the front

template <class E>			// remove minimum
void ListPriorityQueue<E>::dequeue()
{ L.pop_front(); }

#endif /* HEAPS_AND_PRIORITY_QUEUES_LISTPRIORITYQUEUE_H_ */
