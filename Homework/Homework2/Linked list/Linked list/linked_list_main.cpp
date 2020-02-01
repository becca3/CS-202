#include <iostream>
#include <string>
#include <list>
#include <memory>
#include "Catch2.h"	

//Struct of animal data. 
struct Animal
{
	int id = 0;
	int age = 0;
	int amount = 0;
	int zoo = 0;
	int food = 0;
	int health = 0;

	std::unique_ptr<Animal> next;
};

void printAnimal(const Animal& val)
{
	std::cout << "ID: " << val.id << std::endl;
	std::cout << "Age: < " << val.age << std::endl;
	std::cout << "Number of individuals: " << val.amount << std::endl;
	std::cout << "Location of zoo: " << val.zoo << std::endl;
	std::cout << "Food eaten: " << val.food << std::endl;
	std::cout << "Health condition: " << val.health << std::endl;
}

//Animal hitbox_listFIFO(const list<Animal>& hitbox_list)
//{
//
//}

//Animal hitbox_listLIFO(const list<Animal>& hitbox_list)
//{
//
//}

//int hitbox_listInsertAndFind(const list<Animal>& hitbox_list, const int& hb_ID, const shared_ptr<Animal>& hb_ptr)
//{
//
//}

int main(int argc, char** argv)
{
	
	
}
