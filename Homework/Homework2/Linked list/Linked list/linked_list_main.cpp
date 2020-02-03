#include "Catch2.h"
#include "linked_list.h"

#include <iostream>
#include <list>
#include <memory>
#include <algorithm>

void printAnimal(const Animal& val)
{
	std::cout << "ID: " << val.id << std::endl;
	std::cout << "Age: < " << val.age << std::endl;
	std::cout << "Number of individuals: " << val.amount << std::endl;
	std::cout << "Location of zoo: " << val.zoo << std::endl;
	std::cout << "Food eaten: " << val.food << std::endl;
	std::cout << "Health condition: " << val.health << std::endl;
}

void printanimal_list(std::list<Animal>& animal_list)
{
	auto iter = animal_list.begin();
	while (iter != animal_list.end())
	{
		printAnimal(*iter);
		++iter;
	}
}



int main(int argc, char** argv)
{
	std::list<Animal> animal_list;

	Animal val{ 0, 10, 2, 3, 5, 100 };
	Animal val1{ 1, 9, 1, 3, 5, 100 };
	Animal val2{ 2, 12, 2, 2, 3, 80 };
	Animal val3{ 3, 2, 4, 7, 1, 50 };

	return 0;
}