#include<iostream>
#include<string>

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


//Derived class 

class Derived : public Base
{
public:
	Derived() : Base(50), name_{ "Andrea" }
	{
		std::cout << "Constructing derived object, name is " << name_ << "\n";
	}

	Derived(int age, const std::string& name) : Base{ age }, name_{ name }
	{
		std::cout << "Constructing a derived object with name " << name_ << "\n";
	}

	~Derived()
	{
		std::cout << "Deconstructing the derived object with name " << name_ << "\n";
	}

private:
	std::string name_;
};

int main(int argc, char** argv)
{
	{ Base a; }
	std::cout << "\n";

	{ Base a{ 20 }; }
	std::cout << "\n";

	{ Derived b; }
	std::cout << "\n";

	{ Derived b{ 80, "Matt" }; }
	std::cout << "\n";
	return 0;
}