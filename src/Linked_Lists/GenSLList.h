/*
 * GenSLList.h
 *
 *  Created on: Dec 31, 2021
 *      Author: mao
 */

#ifndef LINKED_LISTS_GENSLLIST_H_
#define LINKED_LISTS_GENSLLIST_H_

template <typename E>
class SLinkedList;

template <typename E>
class SNode { // singly linked list node
private:
	E elem; // linked list element value
	SNode<E>* next; // next item in the list
	friend class SLinkedList<E>; // provide SLinkedList with access to private, protected and public members of SNode.
};

template <typename E>
class SLinkedList { // a singly linked list
public:
	SLinkedList(); // empty list constructor
	~SLinkedList(); // destructor
	bool empty() const; // is list empty?
	const E& front() const; // return front element
	void addFront(const E& e); // add to front of list
	void removeFront(); // remove front item list
private:
	SNode<E>* head; // head of the list
};

template <typename E>
SLinkedList<E>::SLinkedList() // constructor
: head(NULL) { }

template <typename E>
bool SLinkedList<E>::empty() const // is list empty?
{ return head == NULL; }

template <typename E>
const E& SLinkedList<E>::front() const // return front element
{ return head->elem; }

template <typename E>
SLinkedList<E>::~SLinkedList() // destructor
{ while (!empty()) removeFront(); }

template <typename E>
void SLinkedList<E>::addFront(const E& e) { // add to front of list
	SNode<E>* v = new SNode<E>; // create new node
	v->elem = e; // store data
	v->next = head; // head now follows v
	head = v; // v is now the head
}

template <typename E>
void SLinkedList<E>::removeFront() { // remove front item
	SNode<E>* old = head; // save current head
	head = old->next; // skip over old head
	delete old; // delete the old head
}



#endif /* LINKED_LISTS_GENSLLIST_H_ */
