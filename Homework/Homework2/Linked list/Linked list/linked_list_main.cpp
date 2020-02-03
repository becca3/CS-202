#include "Catch2.h"
#include "linked_list.h"

#include <iostream>
#include <list>
#include <memory>
#include <algorithm>

//Prints list of data for animals. 
void printAnimal(const Animal& val)
{
	std::cout << "ID: " << val.id << std::endl;
	std::cout << "Age: < " << val.age << std::endl;
	std::cout << "Number of individuals: " << val.amount << std::endl;
	std::cout << "Location of zoo: " << val.zoo << std::endl;
	std::cout << "Food eaten: " << val.food << std::endl;
	std::cout << "Health condition: " << val.health << std::endl;
}

//Prints the animals in the list. 
void printanimal_list(std::list<Animal>& animal_list)
{
	auto iter = animal_list.begin();
	while (iter != animal_list.end())
	{
		printAnimal(*iter);
		++iter;
	}
}

//Copies value 1 to value 2. 
void copyAnimal(Animal& val1, Animal& val2)
{
	val2.id = val1.id;
	val2.age = val1.age;
	val2.amount = val1.amount;
	val2.zoo = val1.zoo;
	val2.food = val1.food;
	val2.health = val1.health;
}

//Checks to see if any values in the struct are equal. 
bool operator == (const Animal& val1, const Animal& val2)
{
	if ((val1.id == val2.id) && (val1.age == val2.age) &&
		(val1.amount == val2.amount) && (val1.zoo == val2.zoo) &&
		(val1.food == val2.food) && (val1.health == val2.health))
	{
		return true;
	}
	else
	{
		return false;
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