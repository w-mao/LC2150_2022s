//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.

/** Array-based implementation of the ADT heap.
 Listing 17-2.
 @file ArrayMaxHeap.h */ 

#ifndef ARRAY_MAX_HEAP_
#define ARRAY_MAX_HEAP_

#include <memory>
#include <cmath>
#include <iostream>
#include "HeapInterface.h"
//#include "PrecondViolatedExcep.h"

template<class ItemType>
class ArrayMaxHeap : public HeapInterface<ItemType>
{
private:
	static const int ROOT_INDEX = 0;        // Helps with readability
	static const int DEFAULT_CAPACITY = 21; // Small capacity to test for a full heap
	std::unique_ptr<ItemType []> items;                        // Array of heap items
	// If std::unique_ptr cannot be resolved, Click
	// Project->Properties->C/C++ Build->Settings->Dialect and choose ISO C++14 from the drop-down.

	int itemCount;                          // Current count of heap items
	int maxItems;                           // Maximum capacity of the heap

	// ---------------------------------------------------------------------
	// Most of the private utility methods use an array index as a parameter
	// and in calculations. This should be safe, even though the array is an
	// implementation detail, since the methods are private.
	// ---------------------------------------------------------------------

	// Returns the array index of the left child (if it exists).
	int getLeftChildIndex(const int nodeIndex) const;

	// Returns the array index of the right child (if it exists).
	int getRightChildIndex(int nodeIndex) const;

	// Returns the array index of the parent node.
	int getParentIndex(int nodeIndex) const;

	// Tests whether this node is a leaf.
	bool isLeaf(int nodeIndex) const;

	// Converts a semiheap to a heap.
	void heapRebuild(int subTreeRootIndex);

	// Creates a heap from an unordered array.
	void heapCreate();

public:
	ArrayMaxHeap();
	ArrayMaxHeap(const ItemType someArray[], const int arraySize);
	virtual ~ArrayMaxHeap();

	// HeapInterface Public Methods:
	bool isEmpty() const;
	int getNumberOfNodes() const;
	int getHeight() const;
	ItemType peekTop() const;
	bool add(const ItemType& newData);
	bool remove();
	void clear();
}; // end ArrayMaxHeap

template<class ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
   return (2 * nodeIndex) + 1;
}  // end getLeftChildIndex

template<class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(const int nodeIndex) const
{
   return (2 * nodeIndex) + 2;
}  // end getRightChildIndex

template<class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(const int nodeIndex) const
{
   return (nodeIndex - 1) / 2;
}  // end getParentIndex

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(const int nodeIndex) const
{
   return (getLeftChildIndex(nodeIndex) >= itemCount);
}  // end isLeaf

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(const int subTreeNodeIndex)
{
   if (!isLeaf(subTreeNodeIndex))
   {
      // Find larger child
      int leftChildIndex = getLeftChildIndex(subTreeNodeIndex);
      int rightChildIndex = getRightChildIndex(subTreeNodeIndex);
      int largerChildIndex = rightChildIndex; // make assumption

      // Check to see if has rightChild and then check if left is larger
      if ( (largerChildIndex >= itemCount) || (items[leftChildIndex] > items[rightChildIndex]))
      {
         largerChildIndex = leftChildIndex; // Asssumption was wrong
      }  // end if

      // Swap with larger child if node value is smaller
      if (items[largerChildIndex] > items[subTreeNodeIndex])
      {
         swap(items[largerChildIndex], items[subTreeNodeIndex]);

         // Continue with the recursion at that child
         heapRebuild(largerChildIndex);
      }  // end if
   }  // end if
}  // end heapRebuild


template<class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate()
{
   for (int index = itemCount / 2; index >= 0; index--)
   {
      heapRebuild(index);
   }  // end for
}  // end heapCreate

//******************************************************************
//
// Public methods start here
//
//******************************************************************

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
   items = std::make_unique<ItemType[]>(DEFAULT_CAPACITY);
//	If the above cannot be resolved:
//  Project->Properties->C/C++ Build->Settings->Dialect and choose ISO c++14 from the drop-down.

}  // end default constructor

template<class ItemType>
ArrayMaxHeap<ItemType>::
ArrayMaxHeap(const ItemType someArray[], const int arraySize):
             itemCount(arraySize), maxItems(2 * arraySize)
{
   // Allocate the array
   items = std::make_unique<ItemType[]>(2 * arraySize);


   // Copy given values into the array
   for (int i = 0; i < itemCount; i++)
      items[i] = someArray[i];

   // Reorganize the array into a heap
   heapCreate();
} // end constructor

template<class ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap()
{
   items.reset();
}  // end destructor

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const
{
   return ceil(log2(itemCount + 1));
}  // end getHeight

template<class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const
{
   return itemCount;
}  // end getNumberOfNodes

template<class ItemType>
void ArrayMaxHeap<ItemType>::clear()
{
   itemCount = 0;
}  // end clear

template<class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const
{
   if (isEmpty()){
      std::cout << "Attempted peek into an empty heap." << std::endl;
      exit(1);
   }

   return items[0];
} // end peekTop

template<class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& newData)
{
   bool isSuccessful = false;
   if (itemCount < maxItems)
   {
      items[itemCount] = newData;

      bool inPlace = false;
      int newDataIndex = itemCount;
      while ((newDataIndex > 0) && !inPlace)
      {
         int parentIndex = getParentIndex(newDataIndex);
         if (items[newDataIndex] < items[parentIndex])
         {
            inPlace = true;
         }
         else
         {
            swap(items[newDataIndex], items[parentIndex]);
            newDataIndex = parentIndex;
         }  // end if
      }  // end while

      itemCount++;
      isSuccessful = true;
   }  // end if

   return isSuccessful;
}  // end add

template<class ItemType>
bool ArrayMaxHeap<ItemType>::remove()
{
   bool isSuccessful = false;
   if (!isEmpty())
   {
      items[ROOT_INDEX] = items[itemCount - 1];
      itemCount--;
      heapRebuild(ROOT_INDEX);
      isSuccessful = true;
   }  // end if

   return isSuccessful;
}  // end remove

#endif
