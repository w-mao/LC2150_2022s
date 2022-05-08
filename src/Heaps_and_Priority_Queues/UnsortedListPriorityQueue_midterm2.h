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
class UnsortedListPriorityQueue {
public:
	UnsortedListPriorityQueue() {
	}
	int size() const; // number of elements
	bool isEmpty() const; // is the queue empty?
	void enqueue(const E& e); // insert element
	const E& peek(); // minimum element
	void dequeue(); // remove minimum
	void dequeue2ndMin();
private:
	std::list<E> L; // priority queue contents
};

template <class E> // number of elements
int UnsortedListPriorityQueue<E>::size() const
{ return L.size(); }

template <class E> // is the queue empty?
bool UnsortedListPriorityQueue<E>::isEmpty() const
{ return L.empty(); }

template <class E>			// insert element
void UnsortedListPriorityQueue<E>::enqueue(const E& e) {
	L.push_front(e);			// insert e before p
}

template <class E>			// minimum element
const E& UnsortedListPriorityQueue<E>::peek()
{
	typename std::list<E>::iterator p;
	p = L.begin();
	typename std::list<E>::iterator pMin;
	pMin = p;
	while (p != L.end()){
		if(*pMin > *p) pMin = p;
		++p;
	}
	return *pMin;

}				// minimum is at the front

template <class E>			// remove minimum
void UnsortedListPriorityQueue<E>::dequeue()
{
	typename std::list<E>::iterator p;
	typename std::list<E>::iterator pMin;
	p = L.begin();
	pMin = p;
	while (p != L.end()){
		if(*pMin > *p) pMin = p;
		++p;
	}
	L.erase(pMin);
}

template <class E>			// remove minimum
void UnsortedListPriorityQueue<E>::dequeue2ndMin()
{

	//	typename std::list<E>::iterator p;
	//	typename std::list<E>::iterator pMax;
	//	typename std::list<E>::iterator p2nd;
	//	p = L.begin();
	//	pMax = p;
	//	p++;
	//	p2nd = p;
	//	if(*pMax < *p2nd){
	//		p2nd = pMax;
	//		pMax = p;
	//	}
	//	while(p != L.end()){
	//		if(*pMax < *p) {
	//			p2nd = pMax;
	//			pMax = p;
	//		}else if(*p2nd < *p){
	//			p2nd = p;
	//		}
	//		++p;
	//	}
	//	L.erase(p2nd);
	//end func
	typename std::list<E>::iterator p;
	typename std::list<E>::iterator pMin;
	typename std::list<E>::iterator p2Min;
	p = L.begin();
	pMin = L.begin();
	p2Min = L.begin();
	//
	//	typename std::list<E>::iterator pMax;
	//	typename std::list<E>::iterator pMax2;
	//	pMax = p;
	//	pMax2 = p;
	//	while (p != L.end()){
	//		if(*pMax < *p){
	//			pMax = p;
	//		}
	//		if((*pMax > *p) && (*p > *pMax2)){
	//			pMax2 = p;
	//		}
	//		++p;
	//	}
	//	L.erase(pMax2);
	//	typename std::list<E>::iterator pMax;
	//	typename std::list<E>::iterator tmp1;
	//	typename std::list<E>::iterator tmp2;
	//	p = L.begin();
	//	pMax = p;
	//	tmp1 = pMax;
	//	tmp2 = pMax;
	//	while(p!=L.end()){
	//		tmp2 = pMax;
	//		pMax = tmp1;
	//		if(*pMax<*p){
	//			pMax = p; }
	//
	//		pMax = p ;
	//		++p;
	//	}
	//	L.erase(pMax);


	/*
	 * The following solution won't for 11 10 1 3 5
	 */
	// pMin -> 1 P2Min ->11
	//	while (p != L.end()){
	//		if(*pMin > *p) {
	//			p2Min = pMin;
	//			pMin = p;
	//		}
	//		++p;
	//	}

	/*
	 * pMin gets affected by removing p2Min
	 */
	//	typename std::list<E>::iterator p2;
	//	//Dequeue first time
	//	p = L.begin();
	//	pMin = p;
	//	while (p != L.end()){
	//		if(*pMin > *p) pMin = p;
	//		++p;
	//	}
	//	L.erase(pMin);
	//
	//	//Dequeue second time
	//	//Noticed that we cannot reset p to L.begin() for reuse it in the loop,
	//	//because we need p for insert the original minimum to its correct location.
	//	p2 = L.begin();
	//	p2Min = p2;
	//	while (p2 != L.end()){
	//		if(*p2Min > *p2) p2Min = p2;
	//		++p2;
	//	}
	//	L.erase(p2Min);
	//
	//	//Insert original minimum back to its original position
	//	L.insert(pMin, *p);



	//	p = L.begin();
	//	pMin = p2Min = p;
	//	while(p != L.end()){
	//		if (!(*pMin > *p) && *p2Min > *p){
	//			p2Min = p;
	//		}
	//		else if (*pMin > *p){
	//			p2Min = pMin;
	//			pMin = p;
	//		}
	//		p++;
	//	}

	//	p = L.begin();
	//	pMin = p;
	//	p2Min = p;
	//	while (p != L.end()){
	//		if (*pMin > *p ){
	//			p2Min = pMin;
	//			pMin = p;
	//		}
	//		++p;
	//	}
	//
	//	if (*p2Min > *pMin){
	//		p = L.end();
	//		pMin = p;
	//		p2Min = p;
	//		while (p != L.begin()){
	//			if (*pMin > *p ){
	//				p2Min = pMin;
	//				pMin = p;
	//			}
	//		}
	//		++p;
	//	}
	//Tuomo Solution
	//    p = L.begin();
	//    pMin = p;
	//    p++;
	//    if(p != L.end()){ //Initialize pMin and pMinSecond
	//        if(*pMin > *p){
	//            p2Min = pMin;
	//            pMin = p;
	//        }
	//    }
	//
	//    while(p != L.end()){
	//        if(*p2Min > *p){ //Check if value is lower than one of our mins
	//            p2Min = p;
	//            if(*pMin > *p2Min){ //Check if new second min is smaller than actual min
	//                  typename std::list<E>::iterator tmp = pMin;
	//                  pMin = p2Min;
	//                  p2Min = tmp;
	//           }
	//        }
	//        p++;
	//     }
	// incorrect solution
	//	bool minIsFirst = true;
	//	while(p!=L.end()){
	//		if(*pMin > *p){
	//			if(*p2Min > *pMin) p2Min = pMin;
	//			pMin = p;
	//			minIsFirst = false;
	//		}
	//		++p;
	//	}
	//	if(minIsFirst){ //if the first element of the array is the lowest prio
	//		p = L.begin();
	//		++p;
	//		p2Min = p;
	//		while(p!=L.end()){
	//			if(*p2Min > *p) p2Min = p;
	//			++p;
	//		}
	//	}

	// solution
	//	while (p != L.end()){
	//		if(*pMin > *p){
	//			p2Min = pMin;
	//			pMin = p;
	//		}
	//		else if (*p2Min > *p){
	//			p2Min = p;
	//		}
	//		++p;
	//	}
	//solution 0

	//	E min = this->peek();
	//	p = L.begin();
	//	p2Min = p;
	//	while (p != L.end())
	//	{
	//		if(*p2Min > *p && *p2Min > min)
	//			p2Min = p;
	//		++p;
	//	}

	//Solution 1
	while(p!=L.end()){
		if(*pMin > *p){
			pMin = p;
		}else if(*p2Min > *p){
			p2Min = p;
		}
		++p;
	}

	//Solution 2
	//	while (p != L.end()){
	//		if(*pMin > *p) pMin = p;
	//		++p;
	//	}
	//
	//	p = L.begin();
	//	p2Min = p;
	//	while (p != L.end()){
	//		if(*p2Min > *p && *p > *pMin) p2Min = p;
	//		++p;
	//	}
	L.erase(p2Min);
}


#endif /* HEAPS_AND_PRIORITY_QUEUES_LISTPRIORITYQUEUE_H_ */
