/*
 * TestAVLTree.cpp
 *
 *  Created on: Feb 25, 2022
 *      Author: mao
 */
#include <iostream>
#include "AVLTree.h"

int testAVLTree()
{
	AVLtree<int> t;

	std::cout << "Inserting integer values 1 to 10" << std::endl;
	for (int i = 1; i <= 10; ++i){
		t.insert(i);
	}
	std::cout << "Printing balance: ";
	t.printBalance();

	return 0;
}

