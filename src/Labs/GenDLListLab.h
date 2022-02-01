/*
 * GenDLList.h
 *
 *  Created on: Dec 30, 2021
 *      Author: mao
 */


//***************************** GenDLList.h ***************************
#ifndef DOUBLY_LINKED_LAB_LIST
#define DOUBLY_LINKED_LAB_LIST

template<class T>
class DLLNodeLab {
public:
	DLLNodeLab() {
		next = prev = nullptr;
	}
	DLLNodeLab(const T& el, DLLNodeLab *n = nullptr, DLLNodeLab *p = nullptr) {
		info = el; next = n; prev = p;
	}
	T info;
	DLLNodeLab *next, *prev;
};

template<class T>
class DoublyLinkedListLab {
public:
	DoublyLinkedListLab() {
		head = tail = nullptr;
	}
	void addToDLLTail(const T&);
	T deleteFromDLLTail();
public:
	DLLNodeLab<T> *head, *tail;
};

template<class T>
void DoublyLinkedListLab<T>::addToDLLTail(const T& el) {
	if (tail != nullptr) {
		tail = new DLLNodeLab<T>(el,nullptr,tail);
		tail->prev->next = tail;
	}
	else head = tail = new DLLNodeLab<T>(el);
}

template<class T>
T DoublyLinkedListLab<T>::deleteFromDLLTail() {
	T el = tail->info;
	if (head == tail) { // if only one node in the list;
		delete head;
		head = tail = nullptr;
	}
	else { // if more than one node in the list;
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}
	return el;
}
#endif
