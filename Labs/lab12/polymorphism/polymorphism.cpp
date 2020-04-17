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

	virtual ~Base()
	{
		std::cout << "Base::~Base destructor \n";
	}

	void functionA()
	{
		std::cout << "Non-virtual Base functionA \n";
	}

	virtual void functionB()
	{
		std::cout << "Virtual Base functionB \n";
	}
};

class Derived : public Base
{
public:
	Derived()
	{
		std::cout << "Derived::Derived() constructor \n";
	}
	~Derived()
	{
		std::cout << "Derived::~Derived destructor \n";
	}

	void functionA()
	{
		std::cout << "Non-virtual Derived functionA \n";
	}

	virtual void functionB() override 
	{
		std::cout << "Virtual Derived functionB \n";
	}
};

void testbaseclasspointer()
{
	Base a;
	{
		Base* pa = &a;
		pa->functionA();
		pa->functionB();
	}
	Derived d;
	{
		Base* pb = &d;
		pb-> functionA();
		pb->functionB();
	}
	{
		Derived* pd = &d;
		pd->functionA();
		pd->functionB();
	}
}

void dashes()
{
	std::cout << "----------------\n";
}

int main(int argc, char** argv)
{
	{ Base a; a.functionA(); a.functionB(); }
	dashes();

	testbaseclasspointer();
	dashes();
	return 0;
}