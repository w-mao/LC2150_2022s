/*
 * 	Assignment #0, CPSC 2150
 *
 *	Author: Mao
 *  Comments: DerivedTriangle.h
 *
 */


#ifndef ASSIGN0
#define ASSIGN0

#include "../Object-Oriented_Programming/GeometricObject.h"

class Triangle: public GeometricObject
{
public:
	Triangle();
	Triangle(double, double, double);
	double getSide1() const;
	void setSide1(double);
	double getSide2() const;
	void setSide2(double);
	double getSide3() const;
	void setSide3(double);
	double getArea() const;
	double getPerimeter() const;
	bool isValid() const;
	string toString() const;

private:
	double side1;
	double side2;
	double side3;
}; // Must place semicolon here



#endif /* ASSIGN0*/
