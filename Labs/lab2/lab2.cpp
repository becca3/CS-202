#include"lab2.h"

//Constructor.
functions::functions()
{
	//std::cout << "Default constructor called \n";
}

//Deconstructor.
functions::~functions()
{
	//std::cout << "Deconstructor called\n";
}

//Copy constructor.
functions::functions(int a1, int b1)
{
	a = a1; b = b1;
}

//Pass by ref.
functions::functions(int& x)
{
	std::cout << "Number is: " << x << "\n";
}

//Vector of objects.

