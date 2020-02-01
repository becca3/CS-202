#include <iostream>
#include <string>
#include <list>
#include <memory>
//#include <catch2/catch.hpp>	

//Struct of animals. 
struct Animal
{
	std::string genus;
	std::string zoo;
	std::string food;
	int id;
	int age;
	int amount;

	std::unique_ptr<Animal> next;
	Animal(int id) : id{ id }, next{ nullptr } {}

	~Animal();
};

//List struct to manage creation and deletion of nodes. 

int main(int argc, char** argv)
{
	auto n0{ std::make_unique<Animal>(0) };
	
	auto n1{ std::make_unique<Animal>(1) };
	n1->next = std::move(n0);
	
	auto n2{ std::make_unique<Animal>(2) };
	n2->next = std::move(n1);

	auto n3{ std::make_unique<Animal>(3) };
	n3->next = std::move(n2);

	auto n4{ std::make_unique<Animal>(4) };
	n4->next = std::move(n3);

	auto n5{ std::make_unique<Animal>(5) };
	n5->next = std::move(n4);

	for (int x = 0; x <= Animal.size())


	//Initialisation of members in struct.
	/*Animal polar_bear{ "Ursus", "Anchorage", "Seal", 1, 15, 2 };
	Animal penguin{ "Aptenodytes", "Edinburgh", "Fish", 2, 7, 10 };
	Animal ringed_seal{ "Pusa", "Aberdeen", "Fish", 3, 3, 3 };
	Animal arctic_fox{ "Vulpes", "London", "Seal", 4, 2, 2 };
	Animal albatross{ "Phoebetria", "Omaha", "Seal", 5, 4, 2 };
	Animal walrus{ "Odobenus", "Toronto", "Seal", 6, 10, 2 };	*/
	

	//std::shared_ptr<Animal> polar_bear = std::make_shared<Animal>("Ursus");
	
	//Create node n0.

	//Create node n1.

	//Link node n0 to n1. And so on..


	//Create an object of List struct.
	

	//Pushing elements to the head of the list. 
	
}

Animal::~Animal()
{
}
