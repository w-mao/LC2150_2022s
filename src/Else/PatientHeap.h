/*
 * PatientHeap.h
 *
 * Final Exam (15 points)
 *
 */

#ifndef PATIENTHEAP_H_
#define PATIENTHEAP_H_

#include <iostream>

void swap ( int& a, int& b )
{
	int c = a;
	a=b;
	b=c;
}

class PatientHeap
{

public:
	PatientHeap();
	~PatientHeap();

	//Returns true if there no patient
	bool isEmpty();

	//Displays all the patient numbers based on array indices
	void display();

	// Display patients in preorder
	void preorder(int nodeIndex);

	// Display patients in postorder
	void postorder(int nodeIndex);

	// Converts a semiheap to a heap.
	void heapRebuild(int subTreeRootIndex);

	//Returns the depth of a given patient number
	int getDepth(int patientNumber);

	//Adds a new node containing the given data to this heap.
	bool add(int newPatient);

	//Removes the root node from this heap.
	int remove();

	// Returns the array index of the left child (if it exists).
	int getLeftChildIndex(int nodeIndex);

	// Returns the array index of the right child (if it exists).
	int getRightChildIndex(int nodeIndex);

	// Returns the array index of the parent node.
	int getParentIndex(int nodeIndex);

	// Tests whether this node is a leaf.
	bool isLeaf(int nodeIndex);

private:
	int capacity;   	// The capacity of all patients
	int patientCount; 	// The total number of all patients
	int* patients; 		// A dynamic array storing the numbers of all patients
	// Each patient has a unique number
};

PatientHeap::PatientHeap(){
	capacity = 21; // Default array size is 21
	patientCount = 0;
	patients = new int[capacity];
}

//***-------------------------------------Write your code below----------------------------------------------



/*
 * Write your code here
 * Do not modify other code.
 * Modifying existing code will lead to no points!!!
 */


bool PatientHeap::isEmpty(){
	//YZ
	if(patientCount == 0){
		return 1;
	}else{
		return 0;
	}
}

void PatientHeap::display(){
	int* tmp = patients;
	for(int i = 0; i < patientCount;i++){
		std::cout << tmp[i] << " ";
	}

}

void PatientHeap::preorder(int nodeIndex){
	int* tmp = patients;
	//while(patients);
}

void PatientHeap::postorder(int nodeIndex){
	//nodeIndex
}

void PatientHeap::heapRebuild(int subTreeRootIndex){
	if (!isLeaf(subTreeRootIndex))
	   {
		  int leftChildIndex = getLeftChildIndex(subTreeRootIndex);
		  int rightChildIndex = getRightChildIndex(subTreeRootIndex);
		  int largerChildIndex = rightChildIndex; // make assumption

		  if ( (largerChildIndex >= patientCount) || (patients[leftChildIndex] > patients[rightChildIndex]))
		  {
			 largerChildIndex = leftChildIndex;
		  }

		  if (patients[largerChildIndex] > patients[subTreeRootIndex])
		  {
			 swap(patients[largerChildIndex], patients[subTreeRootIndex]);

			 heapRebuild(largerChildIndex);
		  }
	   }

}

int PatientHeap::getDepth(int patientNumber){
	int left = getLeftChildIndex(patientNumber);
	int right = getRightChildIndex(patientNumber);
	int depL = 0;
	int depR = 0;

	while(left >0){
		left = left / 2;
		depL++;
	}
	while(right >0){
		right = right / 2;
		depR++;
	}

	if(depL < depR){
		return depL;
	}else{
		return depR;
	}
	return 0;
}



//-------------------------------------Write your code above----------------------------------------------


int PatientHeap::getLeftChildIndex(int nodeIndex)
{
	return (2 * nodeIndex) + 1;
}

int PatientHeap::getRightChildIndex(int nodeIndex)
{
	return (2 * nodeIndex) + 2;
}


int PatientHeap::getParentIndex(int nodeIndex)
{
	return (nodeIndex - 1) / 2;
}

bool PatientHeap::isLeaf(int nodeIndex)
{
	return (getLeftChildIndex(nodeIndex) >= patientCount);
}

bool PatientHeap::add(int newPatient)
{
	bool isSuccessful = false;
	if (patientCount + 1 < capacity)
	{
		patients[patientCount] = newPatient;

		bool inPlace = false;
		int newDataIndex = patientCount;
		while ((newDataIndex > 0) && !inPlace)
		{
			int parentIndex = getParentIndex(newDataIndex);
			if (patients[newDataIndex] < patients[parentIndex])
			{
				inPlace = true;
			}
			else
			{
				swap(patients[newDataIndex], patients[parentIndex]);
				newDataIndex = parentIndex;
			}  // end if
		}  // end while

		patientCount++;
		isSuccessful = true;
	}  // end if

	return isSuccessful;
}  // end add


int PatientHeap::remove()
{
	int paitentNumber = -1;
	if (!isEmpty())
	{
		paitentNumber = patients[0];
		patients[0] = patients[patientCount - 1];
		patientCount--;
		heapRebuild(0);
	}  // end if

	return paitentNumber;
}  // end remove

PatientHeap::~PatientHeap(){
	delete[] patients;
}
#endif /* PATIENTHEAP_H_ */
