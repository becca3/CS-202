#include<iostream>

//Base class.

class Base
{
public:
	Base()
	{
		std::cout << "Constructing the default base object. Initial value is " << age_ << "\n";
	}
	
	Base(int age) :age_(age)
	{
		std::cout << "Constructing a base object with value " << age_ << "\n";
	}

	~Base()
	{
		std::cout << "Destructing a base object with value " << age_ << "\n";
	}

private:
	int age_{ 22 };
};

int main(int argc, char** argv)
{
	{ Base a; }
	std::cout << "\n";

	{ Base a{ 20 }; }
	std::cout << "\n";

	return 0;
}