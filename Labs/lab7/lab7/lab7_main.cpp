#include "lab7.h"
#include <iostream>
#include <iomanip>

int main(int argc, char** argv)
{
	const Animals animal; 
	std::cout << animal << "\n";
	return 0;

	/*Animals* aniPtr = new Animals();
	std::cout << "Made string ptr pointing to an animal: " << aniPtr << std::endl;

	std::unique_ptr<Animals> bear = std::make_unique<Animals>();
	std::cout << "Made unique_ptr<Animals> bear pointing to a name for the bear: " << bear << std::endl;

	std::unique_ptr<Animals> newName = std::move(bear);
	std::cout << "Made unique_ptr<Animals> newName which moved bear: " << newName << std::endl;

	std::shared_ptr<Animals> goose = std::make_shared<Animals>("Bear");
	std::cout << "Made shared_ptr<Animals> goose which made a shared pointer to the first animal: "
		<< goose << std::endl;

	std::shared_ptr<Animals> duck = goose;
	std::cout << "Made shared_ptr<Animals> duck which made a shared pointer to the first animal: "
		<< duck << std::endl;

	delete aniPtr;
	std::cout << "Delete pointer." << std::endl;*/
}