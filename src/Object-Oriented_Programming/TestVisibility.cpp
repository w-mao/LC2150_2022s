/*
 * TestVisibility.cpp
 *
 *  Created on: Jan. 11, 2022
 *      Author: mao
 */


#include <iostream>
using namespace std;

class A
{

public: int i;
protected: int j;
private: int k;

};

class B: private A
{
public:
	void display() const
	{
		cout << i << endl; // Fine, can access it
		cout << j << endl; // Fine, can access it
		//cout << k << endl; // Wrong, cannot access it
	}
};

class C: public B
{
public:
	void display() const
	{
		//cout << i << endl; // Wrong, cannot access it
		//cout << j << endl; // Wrong, cannot access it
		//cout << k << endl; // Wrong, cannot access it
	}
};

class D: public A
{
public:
	void display() const
	{
		cout << i << endl; // Fine, can access it
		cout << j << endl; // Fine, can access it
		//cout << k << endl; // Wrong, cannot access it
	}
};

int testVisibility()
{
	B b;
	//cout << b.i << endl; // Wrong, cannot access it
	//cout << b.j << endl; // Wrong, cannot access it
	//cout << b.k << endl; // Wrong, cannot access it

	D d;
	cout << d.i << endl; // Fine, can access it
	//cout << d.j << endl; // Wrong, cannot access it
	//cout << b.k << endl; // Wrong, cannot access it
	return 0;
}


