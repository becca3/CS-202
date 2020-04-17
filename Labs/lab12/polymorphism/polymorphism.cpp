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

void testBaseref()
{
	Base b;
	{
		Base& bb = b;
		b.functionA();
		b.functionB();
	}
	Derived d;
	{
		Base& bb = b;
		bb.functionA();
		bb.functionB();
	}
	{
		Derived& dd = d;
		dd.functionA();
		dd.functionB();
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

	testBaseref();
	dashes();
	return 0;
}