/*
 * StackQueue.cpp
 *
 *  Created on: Feb 3, 2022
 *      Author: mao
 */

#include "../Stacks_and_Queues/GenListQueue.h"
#include "../Stacks_and_Queues/GenListStack.h"

#include <iostream>
using namespace std;

/*
 * Comment
 */
template<class D>
void displayStack(ListStack<D> * s )
{
	if (! s->isEmpty())
	{
		D elem = s->pop();
		cout << elem << " ";
		displayStack(s);
		s->push(elem);
	}


}

/*
 * Comment
 */
template<class D>
void repeatStackElements(ListStack<D> * s )
{
	if (! s->isEmpty())
	{
		D elem = s->pop();
		repeatStackElements(s);
		s->push(elem);
		s->push(elem);
	}
}

template<class D>
void displayQueueForward(ListQueue<D> * p, ListQueue<D> * pExtra)
{
	if (! p->isEmpty())
	{
		D elem = p->dequeue();
		cout << elem << " ";
		pExtra->enqueue(elem);
		displayQueueForward(p, pExtra);
		//p->enqueue(pExtra->dequeue());
	}
}

template<class D>
void displayQueueBackward(ListQueue<D> * p)
{
	if (! p->isEmpty())
	{
		D elem = p->dequeue();
		displayQueueBackward(p);
		//p->enqueue(elem);
		cout << elem << " ";
	}
}

int stackQueue()
{
	/*
	 * Working on stacks
	 */
	cout << "Testing stack:" << endl;

	ListStack<double> stack;
	stack.push(1.0);
	stack.push(2.0);
	stack.push(3.0);
	stack.push(4.0);
	stack.push(5.0);
    ListStack<double> * s = & stack;
	//displayStack(s);
	//cout << endl;

	repeatStackElements(s);

	displayStack(s);
	cout << endl;

	/*
	 * Working on queues
	 */
	cout << endl << "Testing queue:" << endl;

	delete s;
	s = nullptr;

	ListQueue<double> queue;
	queue.enqueue(1.0);
	queue.enqueue(2.0);
	queue.enqueue(3.0);
	queue.enqueue(4.0);
	queue.enqueue(5.0);
	ListQueue<double> * p = & queue;
	ListQueue<double> * pExtra = new ListQueue<double>;
	displayQueueForward(p, pExtra);
	cout << endl;
//	cout<< p->front();
//	cout << endl;

	displayQueueBackward(p);
	cout << endl;

//	//use cout.flush() to clear buffer if you try to free the pointers, otherwise there will be errors.
//	cout.flush();
//	delete s;
//	s = nullptr;
//	delete p;
//	p = nullptr;
//	delete pExtra;
//	pExtra = nullptr;
	return 0;
}
