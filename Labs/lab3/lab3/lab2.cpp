#include"lab2.h"

//Constructor.
functions::functions()
{
	setAnimal("bear");
	setName("Default");
	//std::cout << "Default constructor called \n";
}

//Deconstructor.	
//functions::~functions()
//{
//	//std::cout << "Deconstructor called\n";
//}

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

functions::functions(const functions& type)
{
	setAnimal(type.x_color);
	setName(type.owner);
}

functions::functions(int color)
{
	setAnimal(color);
	setName("Default");
}

void functions::getAnimal(std::string& name)
{
	name = owner;
}

void functions::setAnimal(std::string name)
{
	Animal = name;
}
void functions::setName(int color)
{
	x_color = color;
}

functions::~functions()
{

}

std::unique_ptr<functions> functions::animal(const std::string name, const int color)
{
	functions x = functions();
	x.setName(color);
	x.setAnimal(name);
	return std::unique_ptr<functions>(&x);
}


