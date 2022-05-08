
///*
// * PatientHeap.h
// *
// * Final Exam (15 points)
// *
// */
//
//#ifndef PATIENTHEAP_H_
//#define PATIENTHEAP_H_
//
//#include <iostream>
//
//void swap ( int& a, int& b )
//{
//	int c = a;
//	a=b;
//	b=c;
//}
//
//class PatientHeap
//{
//
//public:
//	PatientHeap();
//	~PatientHeap();
//
//	//Returns true if there no patient
//	bool isEmpty();
//
//	//Displays all the patient numbers based on array indices
//	void display();
//
//	// Display patients in preorder
//	void preorder(int nodeIndex);
//
//	// Display patients in postorder
//	void postorder(int nodeIndex);
//
//	// Converts a semiheap to a heap.
//	void heapRebuild(int subTreeRootIndex);
//
//	//Returns the depth of a given patient number
//	int getDepth(int patientNumber);
//
//	//Adds a new node containing the given data to this heap.
//	bool add(int newPatient);
//
//	//Removes the root node from this heap.
//	int remove();
//
//	// Returns the array index of the left child (if it exists).
//	int getLeftChildIndex(int nodeIndex);
//
//	// Returns the array index of the right child (if it exists).
//	int getRightChildIndex(int nodeIndex);
//
//	// Returns the array index of the parent node.
//	int getParentIndex(int nodeIndex);
//
//	// Tests whether this node is a leaf.
//	bool isLeaf(int nodeIndex);
//
//private:
//	int capacity;   	// The capacity of all patients
//	int patientCount; 	// The total number of all patients
//	int* patients; 		// A dynamic array storing the numbers of all patients
//	// Each patient has a unique number
//};
//
//PatientHeap::PatientHeap(){
//	capacity = 21; // Default array size is 21
//	patientCount = 0;
//	patients = new int[capacity];
//}
//
////*-------------------------------------Write your code below----------------------------------------------
//
//
//
///*
// * Write your code here
// * Do not modify other code.
// * Modifying existing code will lead to no point!!!
// */
//
//
//
//
//
////-------------------------------------Write your code above----------------------------------------------
//
//bool PatientHeap::isEmpty()
//{
//	return patientCount == 0;
//}
//
//void PatientHeap::display()
//{
//	for(int i = 0; i < patientCount; i++)
//		std::cout << patients[i] << " ";
//	std::cout << std::endl;
//}
//
//int PatientHeap::getDepth(int patientNumber){
//	int index = -1;
//	int depth = 0;
//	for(int i = 0; i < patientCount; i++){
//		if (patients[i] == patientNumber)
//			index = i;
//	}
//
//	if (index == -1)
//		return -1;
//
//	while (index > 0){
//		index = getParentIndex(index);
//		depth++;
//	}
//
//	return depth;
//}
//
//void PatientHeap::preorder(int nodeIndex)
//{
//	int leftChildIndex = getLeftChildIndex(nodeIndex);
//	int rightChildIndex = getRightChildIndex(nodeIndex);
//
//	std::cout<< patients[nodeIndex] << " ";
//
//	if(leftChildIndex < patientCount)
//		preorder(leftChildIndex);
//	if(rightChildIndex < patientCount)
//		preorder(rightChildIndex);
//
//
//}
//
//void PatientHeap::postorder(int nodeIndex)
//{
//	int leftChildIndex = getLeftChildIndex(nodeIndex);
//	int rightChildIndex = getRightChildIndex(nodeIndex);
//
//	if(leftChildIndex < patientCount)
//		postorder(leftChildIndex);
//	if(rightChildIndex < patientCount)
//		postorder(rightChildIndex);
//
//	std::cout<< patients[nodeIndex] << " ";
//}
//
//int PatientHeap::getLeftChildIndex(int nodeIndex)
//{
//	return (2 * nodeIndex) + 1;
//}
//
//int PatientHeap::getRightChildIndex(int nodeIndex)
//{
//	return (2 * nodeIndex) + 2;
//}
//
//
//int PatientHeap::getParentIndex(int nodeIndex)
//{
//	return (nodeIndex - 1) / 2;
//}
//
//bool PatientHeap::isLeaf(int nodeIndex)
//{
//	return (getLeftChildIndex(nodeIndex) >= patientCount);
//}
//
//void PatientHeap::heapRebuild(int subTreeNodeIndex)
//{
//	if (!isLeaf(subTreeNodeIndex))
//	{
//		// Find larger child
//		int leftChildIndex = getLeftChildIndex(subTreeNodeIndex);
//		int rightChildIndex = getRightChildIndex(subTreeNodeIndex);
//		int largerChildIndex = rightChildIndex; // make assumption
//
//		// Check to see if has rightChild and then check if left is larger
//		if ( (largerChildIndex >= patientCount) || (patients[leftChildIndex] > patients[rightChildIndex]))
//		{
//			largerChildIndex = leftChildIndex; // Asssumption was wrong
//		}  // end if
//
//		// Swap with larger child if node value is smaller
//		if (patients[largerChildIndex] > patients[subTreeNodeIndex])
//		{
//			swap(patients[largerChildIndex], patients[subTreeNodeIndex]);
//
//			// Continue with the recursion at that child
//			heapRebuild(largerChildIndex);
//		}  // end if
//	}  // end if
//}  // end heapRebuild
//
//bool PatientHeap::add(int newPatient)
//{
//	bool isSuccessful = false;
//	if (patientCount + 1 < capacity)
//	{
//		patients[patientCount] = newPatient;
//
//		bool inPlace = false;
//		int newDataIndex = patientCount;
//		while ((newDataIndex > 0) && !inPlace)
//		{
//			int parentIndex = getParentIndex(newDataIndex);
//			if (patients[newDataIndex] < patients[parentIndex])
//			{
//				inPlace = true;
//			}
//			else
//			{
//				swap(patients[newDataIndex], patients[parentIndex]);
//				newDataIndex = parentIndex;
//			}  // end if
//		}  // end while
//
//		patientCount++;
//		isSuccessful = true;
//	}  // end if
//
//	return isSuccessful;
//}  // end add
//
//
//int PatientHeap::remove()
//{
//	int paitentNumber = -1;
//	if (!isEmpty())
//	{
//		paitentNumber = patients[0];
//		patients[0] = patients[patientCount - 1];
//		patientCount--;
//		heapRebuild(0);
//	}  // end if
//
//	return paitentNumber;
//}  // end remove
//
//PatientHeap::~PatientHeap(){
//	delete[] patients;
//}
//#endif /* PATIENTHEAP_H_ */
