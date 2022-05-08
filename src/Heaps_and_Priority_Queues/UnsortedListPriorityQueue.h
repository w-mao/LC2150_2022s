///*
// * ListPriorityQueue.h
// *
// *  Created on: Feb 24, 2022
// *      Author: mao
// */
//
//#ifndef HEAPS_AND_PRIORITY_QUEUES_LISTPRIORITYQUEUE_H_
//#define HEAPS_AND_PRIORITY_QUEUES_LISTPRIORITYQUEUE_H_
//
//#include <list>
//
//template <class E>
//class UnsortedListPriorityQueue {
//public:
//	UnsortedListPriorityQueue() {
//	}
//	int size() const; // number of elements
//	bool isEmpty() const; // is the queue empty?
//	void enqueue(const E& e); // insert element
//	const E& peek(); // minimum element
//	void dequeue(); // remove minimum
//private:
//	std::list<E> L; // priority queue contents
//};
//
//template <class E> // number of elements
//int UnsortedListPriorityQueue<E>::size() const
//{ return L.size(); }
//
//template <class E> // is the queue empty?
//bool UnsortedListPriorityQueue<E>::isEmpty() const
//{ return L.empty(); }
//
//template <class E>			// insert element
//void UnsortedListPriorityQueue<E>::enqueue(const E& e) {
//	L.push_front(e);			// insert e before p
//}
//
//template <class E>			// minimum element
//const E& UnsortedListPriorityQueue<E>::peek()
//{
//	typename std::list<E>::iterator p;
//	p = L.begin();
//	typename std::list<E>::iterator pMin;
//	pMin = p;
//	while (p != L.end()){
//		if(*pMin > *p) pMin = p;
//		++p;
//	}
//	return *pMin;
//
//}				// minimum is at the front
//
//template <class E>			// remove minimum
//void UnsortedListPriorityQueue<E>::dequeue()
//{
//	typename std::list<E>::iterator p;
//	typename std::list<E>::iterator pMin;
//	p = L.begin();
//	pMin = p;
//	while (p != L.end()){
//		if(*pMin > *p) pMin = p;
//		++p;
//	}
//	L.erase(pMin);
//}
//
//#endif /* HEAPS_AND_PRIORITY_QUEUES_LISTPRIORITYQUEUE_H_ */
