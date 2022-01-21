/*
 * 	Assignment #0, CPSC 2150
 *
 *	Author: Your Name
 *  	Comments : Describe what the code is doing in your own words.
 *	Add comments to those lines that need explanations.
 *  	[5 points]
 */

#include <iostream>
#include <cmath>
#include "DerivedTriangle.h"
using namespace std;

// Construct a default triangle object
Triangle::Triangle()
{
	side1 = side2 = side3 = 1.0;
}

// Construct a circle object with specified radius,
// color and filled values
Triangle::Triangle(double side1, double side2, double side3)
{
	setSide1(side1);
	setSide2(side2);
	setSide3(side3);
}

// Return the side1 of this triangle
double Triangle::getSide1() const
{
	return side1;

}
// Set a new the side1
void Triangle::setSide1(double side1)
{
	this->side1 = (side1 >= 0) ? side1 : 0;
}

// Return the side2 of this triangle
double Triangle::getSide2() const
{
	return side2;

}
// Set a new the side1
void Triangle::setSide2(double side2)
{
	this->side2 = (side2 >= 0) ? side2 : 0;
}

// Return the side3 of this triangle
double Triangle::getSide3() const
{
	return side3;

}
// Set a new the side3
void Triangle::setSide3(double side3)
{
	this->side3 = (side3 >= 0) ? side3 : 0;
}


// Return the area of this triangle
double Triangle::getArea() const
{
	double s = (side1 + side2 + side3) / 2;
	return isValid()? sqrt(s * (s-side1) * (s - side2) * (s - side3)):0;
}

// Return the perimeter of this triangle
double Triangle::getPerimeter() const
{
	return side1 + side2 + side3;
}

bool Triangle::isValid() const
{
	return (side1 + side2 > side3)&&(side2 + side3 > side1)
            &&(side3 + side1 > side2);
}

// Redefine the toString function
string Triangle::toString() const
{
	return "Triangle object";
}


int testDerivedTriangle()
{
	Triangle triangle(3, 4, 5);
	Triangle *pTriangle = & triangle;

	pTriangle->setColor("orange");
	/*
	 * Write your code here
	 */
	pTriangle->setFilled(true);
	cout << pTriangle->toString() << endl
			<< "color: " << pTriangle->getColor() << endl
			<< "filled: " << (pTriangle->isFilled() ? "true" : "false") << endl
			<< "side1: " << pTriangle->getSide1() << endl
			<< "side2: " << pTriangle->getSide2() << endl
			<< "side3: " << pTriangle->getSide3() << endl
			<< "area: " << pTriangle->getArea() << endl
			<< "perimeter: " << pTriangle->getPerimeter() << endl;

	return 0;
}

