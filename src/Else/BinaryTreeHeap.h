///*
// * BinaryTreeHeap.h
// *
// *  Created on: Apr 3, 2022
// *      Author: mao
// */
//
//#ifndef BINARYTREEHEAP_H_
//#define BINARYTREEHEAP_H_
//
//class BTHNode {
//public:
//	int value;
//	BTHNode *left;
//	BTHNode *right;
//	BTHNode *parent;
//
//	BTHNode(int v) : value(v), left(nullptr), right(nullptr), parent(nullptr) {}
//	BTHNode(int v, BTHNode *p): value(v), left(nullptr), right(nullptr), parent(p){}
//
//	~BTHNode() {
//		delete left;
//		delete right;
//	}
//};
//
//class BTHeap
//{
//public:
//	BTHeap(){
//		root = nullptr;
//		last = nullptr;
//	}
//	bool isEmpty();
//
//
//	// Returns the pointer of the left child (if it exists).
//	BTHNode* getLeftChild(BTHNode*) const;
//
//	// Returns the pointer of the right child (if it exists).
//	BTHNode* getRightChild(BTHNode*) const;
//
//	// Returns the pointer of the parent node.
//	BTHNode* getParent(BTHNode*) const;
//
//	// Tests whether this node is a leaf.
//	BTHNode* isLeaf(BTHNode*) const;
//
//	// Converts a semiheap to a heap.
//	void heapRebuild(int subTreeRootIndex);
//
//	//int getNumberOfNodes() const;
//	//int getHeight() const;
//	int peekTop() const; // Test code will check isEmpty before calling this method.
//	bool add(const int& newValue);
//	bool remove();
//
//
//
//	void perculateUp(BTHNode *p, BTHNode *n);
//	BTHNode* levelDown(BTHNode *n);
//	void perculateDown(BTHNode *p);
//	void insert(BTHNode* r, BTHNode* n);
//	void retrieve();
//	BTHNode* levelDownRight(BTHNode *n);
//	void remove();
//	void HeapSort();
//
//public:
//	BTHNode * root;
//	BTHNode * last;
//};
//
//bool BTHeap::isEmpty(){
//	return root == nullptr;
//}
//
//BTHNode* BTHeap::getLeftChild(BTHNode *node)
//{
//	if(node->left != nullptr)
//		levelDown(t->left);
//	else
//		return nullptr;
//}
//
//void BTHeap::retrieve()
//{
//	if(this->empty()) //Tree is Empty Safeguard
//	{
//		cout << "Tree is Empty!" << endl;
//	}
//	else
//	{
//		cout << root->data << " " << endl;
//	}
//}
//
//Node* BTHeap::levelDownRight(Node *t)
//{
//	if(t->right != NULL)
//		levelDown(t->right);
//	else
//		return t;
//}
//
//#endif
