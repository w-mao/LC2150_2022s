/*
 * GenSLList.h
 *
 *  Created on: Dec 31, 2021
 *      Author: mao
 */

#ifndef LINKED_LISTS_GENSLLIST_LAB_H_
#define LINKED_LISTS_GENSLLIST_LAB_H_


template <typename E>
class SLinkedListLab;

template <typename E>
class SNodeLab { // singly linked list node
public:
	E elem; // linked list element value
	SNodeLab<E>* next; // next item in the list
	friend class SLinkedListLab<E>; // provide SLinkedListLab with access to private, protected and public members of SNodeLab.
};

template <typename E>
class SLinkedListLab { // a singly linked list
public:
	SLinkedListLab(); // empty list constructor
	~SLinkedListLab(); // destructor
	bool empty() const; // is list empty?
	const E& front() const; // return front element
	void addFront(const E& e); // add to front of list
	void removeFront(); // remove front item list
public:
	SNodeLab<E>* head; // head of the list
};

template <typename E>
SLinkedListLab<E>::SLinkedListLab() // constructor
: head(nullptr) { }

template <typename E>
bool SLinkedListLab<E>::empty() const // is list empty?
{ return head == nullptr; }

template <typename E>
const E& SLinkedListLab<E>::front() const // return front element
{ return head->elem; }

template <typename E>
SLinkedListLab<E>::~SLinkedListLab() // destructor
{ while (!empty()) removeFront(); }

template <typename E>
void SLinkedListLab<E>::addFront(const E& e) { // add to front of list
	SNodeLab<E>* v = new SNodeLab<E>; // create new node
	v->elem = e; // store data
	v->next = head; // head now follows v
	head = v; // v is now the head
}

template <typename E>
void SLinkedListLab<E>::removeFront() { // remove front item
	SNodeLab<E>* old = head; // save current head
	head = old->next; // skip over old head
	delete old; // delete the old head
}



#endif /* LINKED_LISTS_GENSLLIST_H_ */
