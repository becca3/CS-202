#include <iostream>
#include <string>
#include <list>

struct Animal
{
	std::string animal;  
	std::unique_ptr<Animal> next;
	Animal(std::string animal) : animal{ animal }, next{ nullptr } {}
};
