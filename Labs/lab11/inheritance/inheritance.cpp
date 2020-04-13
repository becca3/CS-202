#include<iostream>

//Base class.

class Base
{
public:
	Base()
	{
		std::cout << "Constructing the default base object. Initial value is " << age;
	}

private:
	int age{ 22 };
};

int main(int argc, char** argv)
{
	{ Base a; }
	std::cout << "\n";
	return 0;
}