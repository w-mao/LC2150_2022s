///*
// * Lab2_LinkedListFun.cpp
// *
// *  Created on: Jan. 25, 2022
// *      Author: mao
// */
//
//#include "GenSLListLab.h"
//#include "GenDLListLab.h"
//
//#include <iostream>
//using namespace std;
//
///*
// * Print all the elements of a singly linked list.
// */
//
//void printSLinkedList(SLinkedListLab<int> *tmpSLlist)
//{
//	// empty check to be finished
//	SNodeLab<int> *tmp;
//	for (tmp = tmpSLlist->head; tmp != nullptr; tmp = tmp->next)
//	{
//		cout << tmp->elem << endl;
//	}
//}
//
///*
// * Concatenating two singly linked lists tmpSLlist1 and tmpSLlist2,
// * given only references to the first node (head) of each list,
// * into a single list tmpSLlist1 that contains all the nodes of
// * tmpSLlist1 followed by all the nodes of tmpSLlist2.
// * Determine the time complexity of the algorithm.
// */
//
//void concatenateSLinkedList(SLinkedListLab<int> *tmpSLlist1, SLinkedListLab<int> *tmpSLlist2)
//{
//	// empty check to be finished
//	SNodeLab<int> *tmp;
//	for (tmp = tmpSLlist1->head; tmp->next != nullptr; tmp = tmp->next);
//	tmp->next = tmpSLlist2->head;
//}
//
//
//
//void printDLinkedList(DoublyLinkedListLab<int> *tmpDLlist)
//{
//	// empty check to be finished
//	DLLNodeLab<int> *tmp;
//	for (tmp = tmpDLlist->head; tmp != nullptr; tmp = tmp->next)
//	{
//		cout << tmp->info << endl;
//	}
//}
//
//void concatenateDLinkedList(DoublyLinkedListLab<int> *tmpDLlist1, DoublyLinkedListLab<int> *tmpDLlist2)
//{
//	// empty check to be finished
//	// this method hasn't got double checked
//	if (tmpDLlist1->tail != nullptr && tmpDLlist2->head != nullptr)
//	{
//		tmpDLlist1->tail->next = tmpDLlist2->head;
//		tmpDLlist2->head->prev = tmpDLlist1->tail;
//		tmpDLlist1->tail = tmpDLlist2->tail;
//	}
//}
//
//int linkedListFun()
//{
//	cout << endl << "Singly Linked List: " << endl;
//
//	SLinkedListLab<int> *SLlist1 = new SLinkedListLab<int>();
//	// bool isempty = false;
//
//	cout<< "Checking whether the initial list is empty: " << SLlist1->empty()<< endl;
//
//	SLlist1->addFront(10);
//	SLlist1->addFront(8);
//	SLlist1->addFront(50);
//
//	cout<< "Checking whether 50 is in the list before calling deleteFromHead(): " << SLlist1->front() << endl;
//	SLlist1->removeFront();
//	cout<< "Checking whether 50 is in the list after calling deleteFromHead(): " << SLlist1->front() << endl;
//
//	printSLinkedList(SLlist1);
//
//
//	SLinkedListLab<int> *SLlist2 = new SLinkedListLab<int>();
//
//	SLlist2->addFront(9);
//	SLlist2->addFront(5);
//	SLlist2->addFront(0);
//
//	concatenateSLinkedList(SLlist1, SLlist2);
//	cout << "After concatenation: " << endl;
//	printSLinkedList(SLlist1);
//
//	cout << endl << "Doubly Linked List: " << endl;
//
//	DoublyLinkedListLab<int> *DLlist1 = new DoublyLinkedListLab<int>();
//	// bool isempty = false;
//
//	//cout<< "Checking whether the initial list is empty: " << DLlist1->empty()<< endl;
//
//	DLlist1->addToDLLTail(10);
//	DLlist1->addToDLLTail(8);
//	DLlist1->addToDLLTail(50);
//
//	cout<< "Checking whether 50 is in the list before calling deleteFromDLLTail(): " << DLlist1->tail->info << endl;
//	DLlist1->deleteFromDLLTail();
//	cout<< "Checking whether 50 is in the list after calling deleteFromDLLTail(): " << DLlist1->tail->info << endl;
//
//	printDLinkedList(DLlist1);
//
//
//	DoublyLinkedListLab<int> *DLlist2 = new DoublyLinkedListLab<int>();
//
//	DLlist2->addToDLLTail(9);
//	DLlist2->addToDLLTail(5);
//	DLlist2->addToDLLTail(0);
//
//	concatenateDLinkedList(DLlist1, DLlist2);
//	cout << "After concatenation: " << endl;
//	printDLinkedList(DLlist1);
//
//	return 0;
//}
//
