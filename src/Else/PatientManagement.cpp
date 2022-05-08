/*
 * PatientManagement.cpp
 *
 * CPSC 2150 Final exam
 * Author: Mao
 *
 */

#include <iostream>
#include "PatientHeap.h"
using namespace std;

int patientManagement()
{

	PatientHeap pm;

	/*
	 * Testing isEmpty() method 2 points
	 */
	cout << "Testing isEmpty() method: " << (pm.isEmpty()?"True":"False") << endl;
	pm.add(11);
	cout << "Testing isEmpty() method again: " << (pm.isEmpty()?"True":"False") << endl;
	pm.add(10);
	pm.add(36);
	pm.add(34);
	pm.add(6);
	pm.add(3);
	pm.add(25);
	pm.add(56);

	/*
	 * Testing display() method 2 points
	 */
	cout << "Testing display() method:" << endl;
	pm.display();

	/*
	 * Testing preorder() method 2 points
	 */
	cout << "Testing preorder():" << endl;
	pm.preorder(0); // pass root index to the method
	cout << endl;

	/*
	 * Testing postorder() method 2 points
	 */
	cout << "Testing postorder():" << endl;
	pm.postorder(0); // pass root index to the method
	cout << endl;


	/*
	 * Testing heapRebuild() method 4 points
	 */
	pm.remove();
	cout << "After removing the fist patient:" << endl;
	pm.display();


	/*
	 * Testing getDepth() method 3 points
	 */
	pm.add(1);
	cout << "The depth value for patient 36 is: " << pm.getDepth(36) << endl;
	cout << "The depth value for patient 34 is: " << pm.getDepth(34) << endl;
	cout << "The depth value for patient 25 is: " << pm.getDepth(25) << endl;
	cout << "The depth value for patient 10 is: " << pm.getDepth(10) << endl;
	cout << "The depth value for patient 6 is: " << pm.getDepth(6) << endl;
	cout << "The depth value for patient 3 is: " << pm.getDepth(3) << endl;
	cout << "The depth value for patient 11 is: " << pm.getDepth(11) << endl;
	cout << "The depth value for patient 1 is: " << pm.getDepth(1) << endl;

	cout << "The depth value for patient 25 is: " << pm.getDepth(100) << endl;
	return 0;
}




