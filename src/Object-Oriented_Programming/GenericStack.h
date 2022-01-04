/*
 * GenericStack.h
 *
 *  Created on: Dec 29, 2021
 *      Author: mao
 */



#ifndef STACK_H
#define STACK_H


/*
 *
 * StackOfInteger class, used to create a stack for int values.
 *
 */

class StackOfIntegers
{
public:
	StackOfIntegers();
	bool empty() const;
	int peek() const;
	void push(int value);
	int pop();
	int getSize() const;

private:
	int elements[100];
	int size;
};

StackOfIntegers::StackOfIntegers()
{
	size = 0;
}

bool StackOfIntegers::empty() const
{
	return size == 0;
}

int StackOfIntegers::peek() const
{
	return elements[size - 1];
}

void StackOfIntegers::push(int value)
{
	elements[size++] = value;
}

int StackOfIntegers::pop()
{
	return elements[--size];
}



/*
 *
 * Defining generic types for a "stack" class
 *
 */

template<typename T>
class Stack
{
public:
	Stack();
	bool empty() const;
	T peek() const;
	void push(T value);
	T pop();
	int getSize() const;

private:
	T elements[100];
	int size;
};

template<typename T>
Stack<T>::Stack()
{
	size = 0;
}

template<typename T>
bool Stack<T>::empty() const
{
	return size == 0;
}

template<typename T>
T Stack<T>::peek() const
{
	return elements[size - 1];
}

template<typename T>
void Stack<T>::push(T value)
{
	elements[size++] = value;
}

template<typename T>
T Stack<T>::pop()
{
	return elements[--size];
}

template<typename T>
int Stack<T>::getSize() const
{
	return size;
}

#endif

