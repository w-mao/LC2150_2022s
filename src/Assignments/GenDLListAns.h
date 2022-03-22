/*
 * 	Assignment #2, CPSC 2150 (30 points)
 *
 *	Author: Your Name
 *  	Comments : Describe what the code is doing in your own words.
 *	Add comments to those lines that need explanations.
 *  	[6 points]
 *
 *  [4 points] void addToDLLHead(const T&);
 *	[4 points] T deleteFromDLLHead();
 *	[2 points] bool empty() const; // is list empty?
 *	[2 points] T front() const; // return front element
 *	[4 points] bool isInList(T) const; // is a node within the list
 *	[8 points] void deleteNode(T);
 */

#ifndef ASSIGNMENTS_GENDLLISTA_H_
#define ASSIGNMENTS_GENDLLISTA_H_


template<class T>
class DLLNodeA {
public:
	DLLNodeA() {
		next = prev = nullptr;
	}
	DLLNodeA(const T& el, DLLNodeA *n = nullptr, DLLNodeA *p = nullptr) {
		info = el; next = n; prev = p;
	}
	T info;
	DLLNodeA *next, *prev;
};

template<class T>
class DoublyLinkedListA {
public:
	DoublyLinkedListA() {
		head = tail = nullptr;
	}
	void addToDLLTail(const T&);
	T deleteFromDLLTail();

	void addToDLLHead(const T&);
	T deleteFromDLLHead();

	bool empty() const; // is list empty?
	T front() const; // return front element
	bool isInList(T) const; // is a node within the list
	void deleteNode(T);

protected:
	DLLNodeA<T> *head, *tail;
};


template<class T>
void DoublyLinkedListA<T>::addToDLLTail(const T& el) {
	if (tail != nullptr) {
		tail = new DLLNodeA<T>(el,nullptr,tail);
		tail->prev->next = tail;
	}
	else head = tail = new DLLNodeA<T>(el);
}

template<class T>
T DoublyLinkedListA<T>::deleteFromDLLTail() {
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

template<class T>
void DoublyLinkedListA<T>::addToDLLHead(const T& el) {
	if (head != nullptr) {
		head = new DLLNodeA<T>(el, head, nullptr);
		head->next->prev = head;
	}
	else head = tail = new DLLNodeA<T>(el);
}

template<class T>
T DoublyLinkedListA<T>::deleteFromDLLHead() {
	// users have to check whether its empty before delete
	T el = head->info;
	if (head == tail) { // if only one node in the list;
		delete head;
		head = tail = nullptr;
	}
	else { // if more than one node in the list;
		head = head->next;
		delete head->prev;
		head->prev = nullptr;
	}
	return el;
}

template <typename T>
bool DoublyLinkedListA<T>::empty() const // is list empty?
{ return head == nullptr; }

template <class T>
T DoublyLinkedListA<T>::front() const // return front element
{ return head->info; }

template <class T>
bool DoublyLinkedListA<T>::isInList(T el) const {
	DLLNodeA<T> *tmp;
	for (tmp = head; tmp != nullptr && !(tmp->info == el); tmp = tmp->next);
	return tmp != nullptr;
}

template <class T>
void DoublyLinkedListA<T>::deleteNode(T el){
	if (head != nullptr) { // if nonempty list;
		if (head == tail && el == head->info) { // if only one
			delete head; // node in the list;
			head = tail = nullptr;
		}
		else if (el == head->info) {// if more than one node in the list
			DLLNodeA<T> *tmp = head;
			head = head->next;
			head->prev = nullptr;
			delete tmp; // and old head is deleted;
		}
		else { // if more than one node in the list
			DLLNodeA<T> *tmp;
			for (tmp = head->next; // and a nonhead node
					tmp != nullptr && !(tmp->info == el);
					tmp = tmp->next);// is deleted;

			if (tmp != nullptr) {
				tmp->prev->next = tmp->next;
				if(tmp->next != nullptr)
					tmp->next->prev = tmp->prev;
				if (tmp == tail)
					tail = tmp->prev;
				delete tmp;
			}
		}
	}

}

#endif /* ASSIGNMENTS_GENDLLISTA_H_ */
