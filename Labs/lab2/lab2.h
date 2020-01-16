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

	//Move constructor. 
		
};
#endif