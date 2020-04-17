//Polymorphism lab 12

#include <iostream>
#include <string> 

class Base
{
public:
	Base()
	{
		std::cout << "Base::Base() constructor \n";
	}
	~Base()
	{
		std::cout << "Base::~Base destructor \n";
	}

	void functionA()
	{
		std::cout << "Non-virtual base functionA \n";
	}

	virtual void functionB()
	{
		std::cout << "Virtual base functionB \n";
	}
};

void dashes()
{
	std::cout << "----------------\n";
}

int main(int argc, char** argv)
{
	{ Base a; a.functionA(); a.functionB(); }
	dashes();

	return 0;
}