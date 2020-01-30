#include "lab3.h"

int main(int argc, char** argv)
{
	Animals* aniPtr = new Animals();
	std::cout << "Made string ptr pointing to an animal: " << aniPtr << std::endl;

	std::unique_ptr<Animals> bear = std::make_unique<Animals>();
	std::cout << "Made unique_ptr<Animals> bear pointing to a name for the bear: " << bear << std::endl;

	std::unique_ptr<Animals> newName = std::move(bear);
	std::cout << "Made unique_ptr<Animals> newName which moved bear: " << newName << std::endl;

	std::shared_ptr<int> ani1(new int(3));
	std::shared_ptr<int>::element_type val = *ani1;
	std::cout << "Making a shared_ptr to an object. " << "*ani1 == " << val << std::endl;

	delete aniPtr;
	std::cout << "Delete pointer." << std::endl;	 
}

