#include "lab7.h"

Animals::Animals()
{
	/*setAnimal("Bear");
	setName("Default");*/
}

std::ostream& operator<<(std::ostream& os, const Animals& animal)
{
	os << "Name:   " << animal.x_name() << "\n";
	os << "Animal: " << animal.animal() << "\n";
	return os; 
}

//Animals::Animals(std::string animal_)
//{
//	setAnimal(animal_);
//	setName("Default");
//}
//Animals::Animals(const Animals& type)
//{
//	setAnimal(type.x_name_);
//	setName(type.animal_);
//}
//void Animals::getName(std::string& name)
//{
//	name = animal_;
//}
//void Animals::setName(std::string name)
//{
//	animal_ = name;
//}
//void Animals::setAnimal(std::string animal_)
//{
//	x_name_ = animal_;
//}

//Animals::~Animals()
//{
//
//}

//std::unique_ptr<Animals> Animals::animalMake(const std::string name, const std::string animal_)
//{
//	Animals x = Animals();
//	x.setAnimal(animal_);
//	x.setName(name);
//	return std::unique_ptr<Animals>(&x);
//}