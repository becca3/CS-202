//Polymorphism lab 12

#include <iostream>
#include <string> 

class Mum
{
public:
	Mum()
	{
		std::cout << "Mum::Mum() constructor \n";
	}

	virtual ~Mum()
	{
		std::cout << "Mum::~Mum destructor \n";
	}

	void functionA()
	{
		std::cout << "Non-virtual Mum functionA \n";
	}

	virtual void functionB()
	{
		std::cout << "Virtual Mum functionB \n";
	}
};

class Child : public Mum
{
public:
	Child()
	{
		std::cout << "Child::Child() constructor \n";
	}
	~Child()
	{
		std::cout << "Child::~Child destructor \n";
	}

	void functionA()
	{
		std::cout << "Non-virtual Child functionA \n";
	}

	virtual void functionB() override 
	{
		std::cout << "Virtual Child functionB \n";
	}
};

void testMumclasspointer()
{
	Mum a;
	{
		Mum* pa = &a;
		pa->functionA();
		pa->functionB();
	}
	Child d;
	{
		Mum* pb = &d;
		pb-> functionA();
		pb->functionB();
	}
	{
		Child* pd = &d;
		pd->functionA();
		pd->functionB();
	}
}

void testMumref()
{
	Mum b;
	{
		Mum& bb = b;
		b.functionA();
		b.functionB();
	}
	Child d;
	{
		Mum& bb = b;
		bb.functionA();
		bb.functionB();
	}
	{
		Child& dd = d;
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
	{ Mum a; a.functionA(); a.functionB(); }
	dashes();

	testMumclasspointer();
	dashes();

	testMumref();
	dashes();
	return 0;
}