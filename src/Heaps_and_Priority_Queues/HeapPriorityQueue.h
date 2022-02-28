/*
 * HeapPriorityQueue.h
 *
 *  Created on: Feb 24, 2022
 *      Author: mao
 */

#ifndef HEAPS_AND_PRIORITY_QUEUES_HEAPPRIORITYQUEUE_H_
#define HEAPS_AND_PRIORITY_QUEUES_HEAPPRIORITYQUEUE_H_

#include "ArrayMaxHeap.h"
#include "PriorityQueueInterface.h"

template<class ItemType>
class Heap_PriorityQueue : public PriorityQueueInterface<ItemType>, private ArrayMaxHeap<ItemType>
{
public:
	Heap_PriorityQueue();
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();

	/** @pre The priority queue is not empty. */
	ItemType peek() const;
}; // end Heap_PriorityQueue

template<class ItemType>
Heap_PriorityQueue<ItemType>::Heap_PriorityQueue()
{
	ArrayMaxHeap<ItemType>();
}  // end constructor

template<class ItemType>
bool Heap_PriorityQueue<ItemType>::isEmpty() const
{
	return ArrayMaxHeap<ItemType>::isEmpty();
}  // end isEmpty

template<class ItemType>
bool Heap_PriorityQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	return ArrayMaxHeap<ItemType>::add(newEntry);
}  // end add

template<class ItemType>
bool Heap_PriorityQueue<ItemType>::dequeue()
{
	return ArrayMaxHeap<ItemType>::remove();
}  // end remove

template<class ItemType>
ItemType Heap_PriorityQueue<ItemType>::peek() const
{
	if (isEmpty()){
		std::cout << "Attempted peek into an empty priority queue." << std::endl;
		exit(1);
	}

	return ArrayMaxHeap<ItemType>::peekTop();
	// end try/catch
}  // end peek

#endif /* HEAPS_AND_PRIORITY_QUEUES_HEAPPRIORITYQUEUE_H_ */
