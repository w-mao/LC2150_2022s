/*
 * LinkedBinaryTree.h
 *
 *  Created on: Feb 25, 2022
 *      Author: mao
 */

#ifndef TREES_LINKEDBINARYTREE_H_
#define TREES_LINKEDBINARYTREE_H_

#include<list>
#include <iostream>
#include <cmath>
using namespace std;

// base element type
template <class E>
class LinkedBinaryTree {
protected:
	struct TreeNode {					// a node of the tree
		E    elt;					// element value (key)
		TreeNode*   par;					// parent
		TreeNode*   left;					// left child
		TreeNode*   right;					// right child
		TreeNode() : elt(), par(nullptr), left(nullptr), right(nullptr) { } // constructor
		TreeNode(E e) : elt(e), par(NULL), left(NULL), right(NULL) { } // constructor
	};

public:
	class Position {					// position in the tree
	private:
		TreeNode* v;						// pointer to the node
	public:
		Position(TreeNode* _v = nullptr) : v(_v) { }		// constructor
		E& operator*()					// get element
		{ return v->elt; }
		E key() {return v->elt;};
		Position left() const				// get left child
		{ return Position(v->left); }
		Position right() const				// get right child
		{ return Position(v->right); }
		Position parent() const				// get parent
		{ return Position(v->par); }
		bool isNULL() { return (v == nullptr); } // check if position is null
		bool isRoot() const				// root of the tree?
		{ return v->par == nullptr; }
		bool isExternal() const				// an external node?
		{ return v->left == nullptr && v->right == nullptr; }
		bool isInternal() const				// an external node?
		{ return v->left != nullptr || v->right != nullptr; }
		friend class LinkedBinaryTree;			// give tree access
	};
	typedef std::list<Position> PositionList;		// list of positions

public:
	LinkedBinaryTree();					// constructor
	int size() const;					// number of nodes
	bool empty() const;					// is tree empty?
	Position root() const;				// get the root
	PositionList positions() const;  			// list of nodes
	void addRoot();					// add root to empty tree
	void expandExternal(const Position&);		// expand external node
	Position removeAboveExternal(const Position&);	// remove p and parent
	Position addElementInOrder(Position&, Position&, const E&);
	int getHeight(Position&);
	void printTreeInOrder(Position);
	void printTreeByLevel(Position, int);
	// housekeeping functions omitted...
protected: 						// local utilities
	void preorder(TreeNode* v, PositionList& pl) const;	// preorder utility
private:
	TreeNode* _root;					// pointer to the root
	int n;						// number of nodes
};

template <class E>
LinkedBinaryTree<E>::LinkedBinaryTree()			// constructor
: _root(nullptr), n(0) { }

template <class E>
int LinkedBinaryTree<E>::size() const			// number of nodes
{ return n; }

template <class E>
bool LinkedBinaryTree<E>::empty() const			// is tree empty?
{ return size() == 0; }

template <class E>
typename LinkedBinaryTree<E>::Position LinkedBinaryTree<E>::root() const // get the root
{ return Position(_root); }

template <class E>
typename LinkedBinaryTree<E>::PositionList LinkedBinaryTree<E>::positions() const {
	PositionList pl;
	preorder(_root, pl);					// preorder traversal
	return PositionList(pl);				// return resulting list
}

template <class E>
void LinkedBinaryTree<E>::addRoot()			// add root to empty tree
{ _root = new TreeNode; n = 1; }

// expand external node
template <class E>
void LinkedBinaryTree<E>::expandExternal(const Position& p) {
	TreeNode* v = p.v;					// p's node
	v->left = new TreeNode;					// add a new left child
	v->left->par = v;					// v is its parent
	v->right = new TreeNode;				// and a new right child
	v->right->par = v;					// v is its parent
	n += 2;						// two more nodes
}

template <class E>
typename LinkedBinaryTree<E>::Position				// remove p and parent
LinkedBinaryTree<E>::removeAboveExternal(const Position& p) {
	TreeNode* w = p.v;
	TreeNode* v = w->par;			// get p's node and parent
	TreeNode* sib = (w == v->left ?  v->right : v->left);
	if (v == _root) {					// child of root?
		_root = sib;					// ...make sibling root
		sib->par = nullptr;
	}
	else {
		TreeNode* gpar = v->par;				// w's grandparent
		if (v == gpar->left) gpar->left = sib; 		// replace parent by sib
		else gpar->right = sib;
		sib->par = gpar;
	}
	delete w; delete v;					// delete removed nodes
	n -= 2;						// two fewer nodes
	return Position(sib);
}

template <class E>
typename LinkedBinaryTree<E>::Position LinkedBinaryTree<E>::addElementInOrder(Position& p, Position& parent, const E& element)
{
	LinkedBinaryTree::Position newPos;
	if (p.isNULL())
	{
		p.v = new TreeNode(element);
		if (parent.v == nullptr) {
			_root = p.v;
		}
		p.v->par = parent.v;
		n++; // increment the number of elements
		//return LinkedBinaryTree::Position(p.v);
	} else if (element < *p) {
		LinkedBinaryTree::Position left = p.left();
		newPos = addElementInOrder(left, p, element);
		p.v->left = newPos.v;
	} else if (element > *p) {
		LinkedBinaryTree::Position right = p.right();
		newPos = addElementInOrder(right, p, element);
		p.v->right = newPos.v;
	} else {
		cout << "Duplicated element in addEentInOrder !!" << endl;
	}

	return LinkedBinaryTree::Position(p.v);
}

template <class E>
int LinkedBinaryTree<E>::getHeight(Position& p)
{
	if (p.isNULL())
		return -1;
	else{
		LinkedBinaryTree::Position left = p.left();
		LinkedBinaryTree::Position right = p.right();
		return 1 + max(getHeight(left), getHeight(right));
	}


}

template <class E>
void LinkedBinaryTree<E>::printTreeInOrder(Position p)
{
	if (p.isNULL())
		return;
	printTreeInOrder(p.left());
	cout << *p <<" ";
	printTreeInOrder(p.right());
}

template <class E>
void LinkedBinaryTree<E>::printTreeByLevel(Position p, int level)
{
	LinkedBinaryTree::TreeNode* pChild = NULL;
	if (p.v != nullptr)
	{
		if (level == 0)
			cout << "\n Root (data:";
		cout << *p << ")" << endl;
		pChild = (p.left()).v;
		for (int i=0; i<level; i++)
			cout << " ";
		if (pChild != NULL) {
			cout << "L (data: ";
			printTreeByLevel(pChild, level+1);
		} else {
			cout << "L (NULL)" << endl;
		}
		pChild = (p.right()).v;
		for (int i=0; i<level; i++)
			cout << " ";
		if (pChild != NULL) {
			cout << "R (data: ";
			printTreeByLevel(pChild, level+1);
		} else {
			cout << "R (NULL)" << endl;
		}
	}
}

// preorder traversal
template <class E>
void LinkedBinaryTree<E>::preorder(TreeNode* v, PositionList& pl) const {
	pl.push_back(Position(v));				// add this node
	if (v->left != nullptr)					// traverse left subtree
		preorder(v->left, pl);
	if (v->right != nullptr)					// traverse right subtree
		preorder(v->right, pl);
}

#endif /* TREES_LINKEDBINARYTREE_H_ */
