/*
 * TestLinkedBinaryTree.cpp
 *
 *  Created on: Feb 25, 2022
 *      Author: mao
 */

#include <iostream>
#include "LinkedBinaryTree.h"

int testLinkedBinaryTree()
{
	LinkedBinaryTree<int>* pLBTree = new LinkedBinaryTree<int>;
	LinkedBinaryTree<int>::Position parent(nullptr);
	LinkedBinaryTree<int>::Position root = pLBTree->root();
	int data;

	cout << endl;
	for (int i=0; i<10; i++) {
		data = rand() % 100;
		//data = i;
		cout << "Adding " << data << " into LinkedBinaryTree" << endl;

		pLBTree->addElementInOrder(root, parent, data);
	}

	cout << "\n Elements in LinkedBinaryTree, in order: " << endl;
	pLBTree->printTreeInOrder(pLBTree->root());
	cout << endl;
	pLBTree->printTreeByLevel(pLBTree->root(), 0); // start from level 0
	cout << endl;

	cout << "The height of the tree is: " << pLBTree->getHeight(root) << endl;

	delete pLBTree;

	return 0;
}

