/*
 * GenBST.h
 *
 *  Created on: Jan. 31, 2022
 *      Author: mao
 */

//***********************  genBST.h  *************************
//                 generic binary search tree
#include "Stacks_and_Queues/GenListQueue.h"
#include "Stacks_and_Queues/GenListStack.h"
#include <iostream>
using namespace std;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

//template<class T>
//class Stack : public stack<T> { ... } // as in Figure 4.21
//template<class T>

//class Queue : public queue<T> {
//public:
//	T dequeue() {
//		T tmp = front();
//		queue<T>::pop();
//		return tmp; }
//	void enqueue(const T& el) {
//		push(el);
//	}
//};

template<class T>
class BSTNode {
public:
	BSTNode() {
		left = right = nullptr;
	}
	BSTNode(const T& e, BSTNode<T> *l = nullptr, BSTNode<T> *r = nullptr) {
		el = e; left = l; right = r;
	}
	T el;
	BSTNode<T> *left, *right;
};


template<class T>
class BST {
public:
	BST() {
		root = nullptr;
	}
	~BST() {
		clear();
	}
	void clear() {
		clear(root);
		root = nullptr;
	}
	bool isEmpty() const {
		return root == nullptr;
	}
	void preorder() {
		preorder(root);
	}
	void inorder() {
		inorder(root);
	}
	void postorder() {
		postorder(root);
	}
	T* search(const T& el) const {
		return search(root,el);
	}
	void breadthFirst();
	void iterativePreorder();
	void iterativeInorder();
	void iterativePostorder();
	void MorrisInorder();
	void insert(const T&);
	void deleteByMerging(BSTNode<T>*&);
	void findAndDeleteByMerging(const T&);
	void deleteByCopying(BSTNode<T>*&);
	void balance(T*,int,int);

protected:
	BSTNode<T>* root;
	void clear(BSTNode<T>*);
	T* search(BSTNode<T>*, const T&) const; // Figure 6.9
	void preorder(BSTNode<T>*);
	void inorder(BSTNode<T>*);
	void postorder(BSTNode<T>*);
	virtual void visit(BSTNode<T>* p) {
		cout << p->el << ' ';
	}
};

template<class T>
void BST<T>::breadthFirst() {
	ListQueue<BSTNode<T>*> queue;
	BSTNode<T> *p = root;
	if (p != nullptr) {
		queue.enqueue(p);
		while (!queue.empty()) {
			p = queue.dequeue();
			visit(p);
			if (p->left != nullptr)
				queue.enqueue(p->left);
			if (p->right != nullptr)
				queue.enqueue(p->right);
		}
	}
}

template<class T>
void BST<T>::inorder(BSTNode<T> *p) {
	if (p != nullptr) {
		inorder(p->left);
		visit(p);
		inorder(p->right);
	} }
template<class T>
void BST<T>::preorder(BSTNode<T> *p) {
	if (p != nullptr) {
		visit(p);
		preorder(p->left);
		preorder(p->right);
	}
}
template<class T>
void BST<T>::postorder(BSTNode<T>* p) {
	if (p != nullptr) {
		postorder(p->left);
		postorder(p->right);
		visit(p);
	} }

template<class T>
void BST<T>::iterativePreorder() {
	ListStack<BSTNode<T>*> travStack;
	BSTNode<T> *p = root;
	if (p != nullptr) {
		travStack.push(p);
		while (!travStack.empty()) {
			p = travStack.pop();
			visit(p);
			if (p->right != nullptr)
				travStack.push(p->right);
			if (p->left != nullptr)   // left child pushed after right
				travStack.push(p->left); // to be on the top of the stack;
		}
	}
}

template<class T>
void BST<T>::iterativePostorder() {
	ListStack<BSTNode<T>*> travStack;
	BSTNode<T>* p = root, *q = root;
	while (p != nullptr) {
		for ( ; p->left != nullptr; p = p->left)
			travStack.push(p);
		while (p->right == nullptr || p->right == q) {
			visit(p);
			q = p;
			if (travStack.empty())
				return;
			p = travStack.pop();
		}
		travStack.push(p);
		p = p->right;
	}
}

template<class T>
void BST<T>::iterativeInorder() {
	ListStack<BSTNode<T>*> travStack;
	BSTNode<T> *p = root;
	while (p != nullptr) {
		while (p != nullptr) {
			if (p->right) // stack the right child (if any) and the node itself when going
				travStack.push(p->right); // to the left;
			travStack.push(p);
			p = p->left;
		}
		p = travStack.pop(); // pop a node with no left child while (!travStack.empty() && p->right == nullptr) { // visit it
		while (!travStack.empty() && p->right == nullptr) { // visit it
			visit(p);
			p = travStack.pop();
		}
		visit(p); // visit also the first node with
		if (!travStack.empty()) // a right child (if any);
			p = travStack.pop();
		else p = nullptr;
	}
}

template<class T>
void BST<T>::MorrisInorder() {
	BSTNode<T> *p = root, *tmp;
	while (p != nullptr)
		if (p->left == nullptr) {
			visit(p);
			p = p->right;
		}
		else {
			tmp = p->left;
			while (tmp->right != nullptr && tmp->right != p) // go to the rightmost node of the left subtree or to the temporary parent of p;
				tmp = tmp->right;
			if (tmp->right == nullptr) // if 'true' rightmost node was reached, make it a temporary parent of the current root,
			{
				tmp->right = p;
				p = p->left;
			}
			else { // else a temporary parent has been found; visit node p and then cut the right pointer of the current parent, whereby it ceases to be a parent;

				visit(p);
				tmp->right = nullptr;
				p = p->right;
			}
		}
}

template<class T>
  void BST<T>::insert(const T& el) {
      BSTNode<T> *p = root, *prev = nullptr;
      while (p != nullptr) {  // find a place for inserting new node;
          prev = p;
          if (el < p->el)
               p = p->left;
          else p = p->right;
      }
      if (root == nullptr)    // tree is empty;
           root = new BSTNode<T>(el);
      else if (el < prev->el)
           prev->left   = new BSTNode<T>(el);
      else prev->right  = new BSTNode<T>(el);
}

template<class T>
T* BST<T>::search(BSTNode<T>* p, const T& el) const {
	while (p != nullptr)
		if (el == p->el)
			return &p->el;
		else if (el < p->el)
			p = p->left;
		else p = p->right;
	return nullptr;
}

template<class T>
void BST<T>::deleteByMerging(BSTNode<T>*& node) {
	BSTNode<T> *tmp = node;
	if (node != nullptr) {
		if (!node->right) // node has no right child
			node = node->left; // its left child (if any) is attached to its parent;
		else if (node->left == nullptr) // node has no left child
			node = node->right; // its right child is attached to its parent;
		else { // be ready for merging subtrees;
			tmp = node->left; // 1. move left
			while (tmp->right != nullptr)// 2. and then right as far as possible
				tmp = tmp->right;
			// 3. establish the link between the rightmost node of the left subtree and the right subtree;
			tmp->right = node->right;
			tmp = node;//4.
			node = node->left;//5.
		}
		delete tmp; // 6.
	}
}

template<class T>
void BST<T>::findAndDeleteByMerging(const T& el) {
	BSTNode<T> *node = root, *prev = nullptr;
	while (node != nullptr) {
		if (node->el == el)
			break;
		prev = node;
		if (el < node->el)
			node = node->left;
		else node = node->right;
	}
	if (node != nullptr && node->el == el)
		if (node == root)
			deleteByMerging(root);
		else if (prev->left == node)
			deleteByMerging(prev->left);
		else deleteByMerging(prev->right);
	else if (root != nullptr)
		cout << "element" << el << "is not in the tree\n";
	else cout << "the tree is empty\n";
}

template<class T>
void BST<T>::deleteByCopying(BSTNode<T>*& node) {

	BSTNode<T> *previous, *tmp = node;
	if (node->right == nullptr)
		node = node->left;
	else if (node->left == nullptr)
		node = node->right;
	else {
		tmp = node->left;
		previous = node;
		while (tmp->right != nullptr) {
			previous = tmp;
			tmp = tmp->right;
		}
		node->el = tmp->el;
		if (previous == node)
			previous ->left  = tmp->left;
		else previous ->right = tmp->left;
	}
	delete tmp;
}

template<class T>
void BST<T>::balance(T data[], int first, int last) {
	if (first <= last) {
		int middle = (first + last)/2;
		insert(data[middle]);
		balance (data,first,middle-1);
		balance (data,middle+1,last);
	} }

#endif
