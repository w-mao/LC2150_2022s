/*
 * IntSLList.h
 *
 *  Created on: Dec 30, 2021
 *      Author: mao
 */

//************************ IntSLList.h **************************
// singly-linked list class to store integers
#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class IntSLLNode {
public:
	IntSLLNode() {
		info = 0;
		next = 0;
	}
	IntSLLNode(int el, IntSLLNode *ptr = 0) {
		info = el; next = ptr;
	}
	int info;
	IntSLLNode *next;
};

class IntSLList {
public:
	IntSLList() {
		head = tail = 0;
	}
	~IntSLList();
	int isEmpty() {
		return head == 0;
	}
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead(); // delete the head and return its info;
	int deleteFromTail(); // delete the tail and return its info;
	void deleteNode(int);
	bool isInList(int) const;

private:
	IntSLLNode *head, *tail;
};
#endif

