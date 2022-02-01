///*
// * 	Assignment #2, CPSC 2150 (30 points)
// *
// *	Author: Your Name
// *  	Comments : Describe what the code is doing in your own words.
// *	Add comments to those lines that need explanations.
// *  	[6 points]
// */
//
//#ifndef ASSIGNMENTS_GENDLLISTA_H_
//#define ASSIGNMENTS_GENDLLISTA_H_
//
//
//template<class T>
//class DLLNodeA {
//public:
//	DLLNodeA() {
//		next = prev = nullptr;
//	}
//	DLLNodeA(const T& el, DLLNodeA *n = nullptr, DLLNodeA *p = nullptr) {
//		info = el; next = n; prev = p;
//	}
//	T info;
//	DLLNodeA *next, *prev;
//};
//
//template<class T>
//class DoublyLinkedListA {
//public:
//	DoublyLinkedListA() {
//		head = tail = nullptr;
//	}
//	void addToDLLTail(const T&);
//	T deleteFromDLLTail();
//
//	void addToDLLHead(const T&); // 4 points
//	T deleteFromDLLHead(); // 4 points
//
//	bool empty() const; // is list empty?  (2 points)
//	T front() const; // return front element  (2 points)
//	bool isInList(T) const; // is a node within the list  (4 points)
//	void deleteNode(T); // delete a node (8 points)
//
//protected:
//	DLLNodeA<T> *head, *tail;
//};
//
//
//template<class T>
//void DoublyLinkedListA<T>::addToDLLTail(const T& el) {
//	if (tail != nullptr) {
//		tail = new DLLNodeA<T>(el,nullptr,tail);
//		tail->prev->next = tail;
//	}
//	else head = tail = new DLLNodeA<T>(el);
//}
//
//template<class T>
//T DoublyLinkedListA<T>::deleteFromDLLTail() {
//	T el = tail->info;
//	if (head == tail) { // if only one node in the list;
//		delete head;
//		head = tail = nullptr;
//	}
//	else { // if more than one node in the list;
//		tail = tail->prev;
//		delete tail->next;
//		tail->next = nullptr;
//	}
//	return el;
//}
//
///*
// * Your code
// */
//
//#endif /* ASSIGNMENTS_GENDLLISTA_H_ */
