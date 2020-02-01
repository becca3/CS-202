#include <iostream>
#include <string>
#include <list>
#include <memory>

#include "linked_list.h"
#include "Catch2.h"	

void printAnimal(const Animal& val)
{
	std::cout << "ID: " << val.id << std::endl;
	std::cout << "Age: < " << val.age << std::endl;
	std::cout << "Number of individuals: " << val.amount << std::endl;
	std::cout << "Location of zoo: " << val.zoo << std::endl;
	std::cout << "Food eaten: " << val.food << std::endl;
	std::cout << "Health condition: " << val.health << std::endl;
}

//Animal Animal_listFIFO(const list<Animal>& Animal_list)
//{
//
//}

//Animal Animal_listLIFO(const list<Animal>& Animal_list)
//{
//
//}

//int Animal_listInsertAndFind(const list<Animal>& Animal_list, const int& val_ID, const shared_ptr<Animal>& val_ptr)
//{
//
//}

int main(int argc, char** argv)
{
	
	
}
