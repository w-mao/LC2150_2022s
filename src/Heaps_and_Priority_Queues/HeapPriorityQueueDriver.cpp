/** 
 A driver that demonstrates the class PriorityQueue.

 @author Frank M. Carrano
 @version 3.0
 */

#include "HeapPriorityQueue.h" // ADT Priority Queue operations
#include <iostream>
#include <string>

void pqTester(PriorityQueueInterface<std::string>* pqPtr)
{
	std::string items[] = {"one", "two", "three", "four", "five", "six"};
	std::cout << "Empty: " << pqPtr->isEmpty() << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout<<"Adding " << items[i] << std::endl;
		bool success = pqPtr->enqueue(items[i]);
		if (!success)
			std::cout << "Failed to add " << items[i] << " to the priority queue." << std::endl;
	}

	std::cout << "Empty?: " << pqPtr->isEmpty() << std::endl;

	for (int i = 0; i < 6; i++) 
	{
		std::cout << "Loop " << i << std::endl;
		std::cout << "peek: " << pqPtr->peek() << std::endl;
		//std::cout << "Empty: " << pqPtr->isEmpty() << std::endl;
		//std::cout << "Remove: " << pqPtr->dequeue() << std::endl;
	}

	//std::cout << "remove with an empty priority queue: " << std::endl;
	//std::cout << "Empty: " << pqPtr->isEmpty() << std::endl;
	//std::cout << "Remove: " << pqPtr->dequeue() << std::endl; // nothing to remove!

	//std::cout << "peek with an empty priority queue: " << std::endl;
	//std::cout << "peek: " << pqPtr->peek() << std::endl; // nothing to see!


} // end pqTester

int HeapPriorityQueueDriver()
{
	PriorityQueueInterface<std::string>* pqPtr = new Heap_PriorityQueue<std::string>();
	std::cout << "Testing the priority queue:" <<std::endl;
	pqTester(pqPtr);

	return 0;
}  // end main
/*
 Testing the priority queue:
 Empty: 1
 Adding one
 Adding two
 Adding three
 Adding four
 Adding five
 Adding six
 Empty?: 0
 Loop 0
 peek: two
 Empty: 0
 Remove: 1
 Loop 1
 peek: three
 Empty: 0
 Remove: 1
 Loop 2
 peek: six
 Empty: 0
 Remove: 1
 Loop 3
 peek: one
 Empty: 0
 Remove: 1
 Loop 4
 peek: four
 Empty: 0
 Remove: 1
 Loop 5
 peek: five
 Empty: 0
 Remove: 1
 remove with an empty priority queue:
 Empty: 1
 Remove: 0
 peek with an empty priority queue:
 peek: Precondition Violated Exception: Attempted peek into an empty priority queue.
 */
