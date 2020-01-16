#ifndef LAB_2_H	
#define LAB_2_H

#include<iostream>
#include<string>

class functions
{
private:
	int a, b;
	
public:
	//Default constructor. A constructor that can be called without parameters.
	functions()
	{
		std::cout << "Default constructor called \n";
	}

	//Deconstructor.
	~functions()
	{
		std::cout << "Deconstructor called\n";
	}

	//Copy constructor. A member function which initializes an object using another object of the same class.
	functions(int a1, int b1)
	{
		a = a1; b = b1; 
	}

	functions(const functions& x1) { a = x1.a; b = x1.b; }
	int geta() { return a; }
	int getb() { return b; }

	//Move constructor. 
		
};
#endif