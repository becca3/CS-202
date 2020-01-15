#ifndef LAB_2_H	
#define LAB_2_H

#include<iostream>
#include<string>

class functions
{
private:
	int x, y;
	int a;

public:
	//Default constructor. A constructor that can be called without parameters.
	functions(int x1_, int y1_) { x = x1_; y = y1_; }

	//Copy constructor. A member function which initializes an object using another object of the same class.
	functions(const functions& item) { x = item.x; y = item.y; }

	int getX() { return x; }
	int getY() { return y; }

	//Move constructor. 
};
#endif