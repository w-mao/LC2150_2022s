///*
// * 	Assignment #3, CPSC 2150 (30 points)
// *
// *	Author: Your Name
// *  	Comments : Describe what the code is doing in your own words.
// *	Add comments to those lines that need explanations.
// *  	[6 points]
// */
//
//#include "../Stacks_and_Queues/GenListQueue.h"
//#include "../Stacks_and_Queues/GenListStack.h"
//
//#include <iostream>
//using namespace std;
//
///*
// * Comment
// */
//template<class D>
//void displayStack(ListStack<D> * s )
//{
//	D elem;
//	/*
//	 * Your code (7 points)
//	 * Recursion.
//	 * Other than "D elem;",
//	 * you are not allowed to create other objects or pointers.
//	 */
//
//}
//
///*
// * Comment
// */
//template<class D>
//void repeatStackElements(ListStack<D> * s )
//{
//	D elem;
//	/*
//	 * Your code (7 points)
//	 * Recursion.
//	 * Other than "D elem;",
//	 * you are not allowed to create other objects or pointers.
//	 */
//}
//
///*
// * Comment
// */
//template<class D>
//void displayQueueForward(ListQueue<D> * p, ListQueue<D> * pExtra, bool& flag)
//{
//	D elem;
//	/*
//	 * Your code (10 points)
//	 * Recursion.
//	 * Other than "D elem;",
//	 * you are not allowed to create other objects or pointers.
//	 */
//}
//
//int stackQueue()
//{
//	/*
//	 * Working on stacks
//	 */
//	cout << "Testing stack:" << endl;
//
//	ListStack<double> stack;
//	stack.push(1.0);
//	stack.push(2.0);
//	stack.push(3.0);
//	stack.push(4.0);
//	stack.push(5.0);
//    ListStack<double> * s = & stack;
//    cout << "Original stack: " << endl;
//    displayStack(s);
//    cout << endl;
//	repeatStackElements(s);
//	cout << "Repeated Stack: " << endl;
//	displayStack(s);
//	cout << endl;
//
//	/*
//	 * Working on queues
//	 */
//	cout << endl << "Testing queue:" << endl;
//
//	ListQueue<double> queue;
//	queue.enqueue(1.0);
//	queue.enqueue(2.0);
//	queue.enqueue(3.0);
//	queue.enqueue(4.0);
//	queue.enqueue(5.0);
//	ListQueue<double> * p = & queue;
//	ListQueue<double> * pExtra = new ListQueue<double>;
//	bool flag = 0;
//	cout << "Original queue: " << endl;
//	displayQueueForward(p, pExtra, flag);
//	cout << endl;
//	cout << "After display: " << endl;
//	flag = 0;
//	displayQueueForward(p, pExtra, flag);
//	cout << endl;
//
//	return 0;
//}
