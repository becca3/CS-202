#ifndef LAB_2_H	
#define LAB_2_H

#include<iostream>
#include<string>

class functions
{	
public:

	int a, b;
	int z = 10;

	//Default constructor. A constructor that can be called without parameters.
	functions();

	//Deconstructor.
	~functions();
	void show() { functions();  this->functions::~functions(); }

	//Copy constructor. A member function which initializes an object using another object of the same class.
	functions(int a1, int b1);

	functions(const functions& x1) { a = x1.a; b = x1.b; }
	int geta() { return a; }
	int getb() { return b; }

	//Pass by reference.
	functions(int& x);
	

	//Move constructor. 
};
#endif