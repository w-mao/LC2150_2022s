/*
 * Lab2_LinkedListFun.cpp
 *
 *  Created on: Jan. 25, 2022
 *      Author: mao
 */

#include "GenSLListLab.h"
#include "GenDLListLab.h"

#include <iostream>
using namespace std;

/*
 * Print all the elements of a singly linked list.
 */

void printSLinkedList(SLinkedListLab<int> *tmpSLlist)
{
	/*
	 * Your Code
	 */


}

/*
 * Concatenating two singly linked lists tmpSLlist1 and tmpSLlist2,
 * given only references to the first node (head) of each list,
 * into a single list tmpSLlist1 that contains all the nodes of
 * tmpSLlist1 followed by all the nodes of tmpSLlist2.
 * Determine the time complexity of the algorithm.
 */

void concatenateSLinkedList(SLinkedListLab<int> *tmpSLlist1, SLinkedListLab<int> *tmpSLlist2)
{
	/*
	 * Your Code
	 */

}



void printDLinkedList(DoublyLinkedListLab<int> *tmpDLlist)
{
	/*
	 * Your Code
	 */

}

void concatenateDLinkedList(DoublyLinkedListLab<int> *tmpDLlist1, DoublyLinkedListLab<int> *tmpDLlist2)
{
	/*
	 * Your Code
	 */

}

int linkedListFun()
{
	cout << endl << "Singly Linked List: " << endl;

	SLinkedListLab<int> *SLlist1 = new SLinkedListLab<int>();
	// bool isempty = false;

	cout<< "Checking whether the initial list is empty: " << SLlist1->empty()<< endl;

	SLlist1->addFront(10);
	SLlist1->addFront(8);
	SLlist1->addFront(50);

	cout<< "Checking whether 50 is in the list before calling deleteFromHead(): " << SLlist1->front() << endl;
	SLlist1->removeFront();
	cout<< "Checking whether 50 is in the list after calling deleteFromHead(): " << SLlist1->front() << endl;

	printSLinkedList(SLlist1);


	SLinkedListLab<int> *SLlist2 = new SLinkedListLab<int>();

	SLlist2->addFront(9);
	SLlist2->addFront(5);
	SLlist2->addFront(0);

	concatenateSLinkedList(SLlist1, SLlist2);
	cout << "After concatenation: " << endl;
	printSLinkedList(SLlist1);

	cout << endl << "Doubly Linked List: " << endl;


	/*
	 * Test a doubly linked list
	 * Your Code
	 */

	return 0;
}

