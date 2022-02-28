/*
 * AVLTree.h
 *
 *  Created on: Feb 25, 2022
 *      Author: mao
 */
#ifndef AVLTREE_H
#define AVLTREE_H

#include <algorithm>
#include <iostream>

/*
 * AVL node
 */
template <class T>
class AVLNode {
public:
	T key;
	int balance;
	AVLNode *left;
	AVLNode *right;
	AVLNode *parent;

	AVLNode(T k) : key(k), balance(0), left(nullptr), right(nullptr), parent(nullptr) {}
	AVLNode(T k, AVLNode *p): key(k), balance(0), left(nullptr), right(nullptr), parent(p){}

	~AVLNode() {
		delete left;
		delete right;
	}
};

/*
 *  AVL tree
 */

template <class T>
class AVLtree {
public:
	AVLtree(void);
	~AVLtree(void);
	bool insert(T key);
	void deleteKey(const T key);
	void printBalance();

private:
	AVLNode<T> *root;
	AVLNode<T>* rotateLeft( AVLNode<T> *a );
	AVLNode<T>* rotateRight( AVLNode<T> *a );
	AVLNode<T>* rotateLeftThenRight( AVLNode<T> *n );
	AVLNode<T>* rotateRightThenLeft( AVLNode<T> *n );

	void rebalance( AVLNode<T> *n );
	int height( AVLNode<T> *n );
	void setBalance( AVLNode<T> *n );
	void printBalance( AVLNode<T> *n );
	void clearNode( AVLNode<T> *n );
};

/* AVL class definition */
template <class T>
void AVLtree<T>::rebalance(AVLNode<T> *n) {
	setBalance(n);

	if (n->balance == -2) {
		if (height(n->left->left) >= height(n->left->right))
			n = rotateRight(n);
		else
			n = rotateLeftThenRight(n);
	}
	else if (n->balance == 2) {
		if (height(n->right->right) >= height(n->right->left))
			n = rotateLeft(n);
		else
			n = rotateRightThenLeft(n);
	}

	if (n->parent != nullptr) {
		rebalance(n->parent);
	}
	else {
		root = n;
	}
}

template <class T>
AVLNode<T>* AVLtree<T>::rotateLeft(AVLNode<T> *a) {
	AVLNode<T> *b = a->right;
	b->parent = a->parent;
	a->right = b->left;

	if (a->right != nullptr)
		a->right->parent = a;

	b->left = a;
	a->parent = b;

	if (b->parent != nullptr) {
		if (b->parent->right == a) {
			b->parent->right = b;
		}
		else {
			b->parent->left = b;
		}
	}

	setBalance(a);
	setBalance(b);
	return b;
}

template <class T>
AVLNode<T>* AVLtree<T>::rotateRight(AVLNode<T> *a) {
	AVLNode<T> *b = a->left;
	b->parent = a->parent;
	a->left = b->right;

	if (a->left != nullptr)
		a->left->parent = a;

	b->right = a;
	a->parent = b;

	if (b->parent != nullptr) {
		if (b->parent->right == a) {
			b->parent->right = b;
		}
		else {
			b->parent->left = b;
		}
	}

	setBalance(a);
	setBalance(b);
	return b;
}

template <class T>
AVLNode<T>* AVLtree<T>::rotateLeftThenRight(AVLNode<T> *n) {
	n->left = rotateLeft(n->left);
	return rotateRight(n);
}

template <class T>
AVLNode<T>* AVLtree<T>::rotateRightThenLeft(AVLNode<T> *n) {
	n->right = rotateRight(n->right);
	return rotateLeft(n);
}

template <class T>
int AVLtree<T>::height(AVLNode<T> *n) {
	if (n == nullptr)
		return -1;
	return 1 + std::max(height(n->left), height(n->right));
}

template <class T>
void AVLtree<T>::setBalance(AVLNode<T> *n) {
	n->balance = height(n->right) - height(n->left);
}

template <class T>
void AVLtree<T>::printBalance(AVLNode<T> *n) {
	if (n != nullptr) {
		printBalance(n->left);
		std::cout << n->balance << " ";
		printBalance(n->right);
	}
}

template <class T>
AVLtree<T>::AVLtree(void) : root(nullptr) {}

template <class T>
AVLtree<T>::~AVLtree(void) {
	delete root;
}

template <class T>
bool AVLtree<T>::insert(T key) {
	if (root == nullptr) {
		root = new AVLNode<T>(key, nullptr);
	}
	else {
		AVLNode<T> *n = root;
		AVLNode<T> *parent;

		while (true) {
			if (n->key == key)
				return false;

			parent = n;

			bool goLeft = n->key > key;
			n = goLeft ? n->left : n->right;

			if (n == nullptr) {
				if (goLeft) {
					parent->left = new AVLNode<T>(key, parent);
				}
				else {
					parent->right = new AVLNode<T>(key, parent);
				}

				rebalance(parent);
				break;
			}
		}
	}

	return true;
}

template <class T>
void AVLtree<T>::deleteKey(const T delKey) {
	if (root == nullptr)
		return;

	AVLNode<T> *n = root;
	AVLNode<T> *parent  = root;
	AVLNode<T> *delNode = nullptr;
	AVLNode<T> *child   = root;

	while (child != nullptr) {
		parent = n;
		n = child;
		child = delKey >= n->key ? n->right : n->left;
		if (delKey == n->key)
			delNode = n;
	}

	if (delNode != nullptr) {
		delNode->key = n->key;

		child = n->left != nullptr ? n->left : n->right;

		if (root->key == delKey) {
			root = child;
		}
		else {
			if (parent->left == n) {
				parent->left = child;
			}
			else {
				parent->right = child;
			}

			rebalance(parent);
		}
	}
}

template <class T>
void AVLtree<T>::printBalance() {
	printBalance(root);
	std::cout << std::endl;
}

#endif

