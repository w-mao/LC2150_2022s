/*
 * TestBST.cpp
 *
 *  Created on: Feb 5, 2022
 *      Author: mao
 */

#include <iostream>
#include "GenBST.h"
using namespace std;


int testBST()
{

	BST<int> bst;
	bst.insert(3);
	bst.insert(2);
	bst.insert(1);
	bst.preorder();
	return 0;
}




