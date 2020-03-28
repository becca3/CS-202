#ifndef LAB7_H
#define LAB7_H 

#include <iostream>
#include <string>
//#include <vector>
//#include <sstream>
//#include <memory>
//#include <algorithm>

class Animals
{
public:
	Animals();

	const std::string& animal() const { return animal_; }
	const std::string& x_name() const { return x_name_; }


	/*Animals(std::string animal);
	Animals(const Animals& type);
	virtual ~Animals();

	void setAnimal(std::string animal);
	void setName(std::string name);
	void getName(std::string& name);

	std::unique_ptr<Animals> animalMake(const std::string name, const std::string animal);*/

private:
	std::string animal_{ "Bear" };
	std::string x_name_{ "Polar" };

};

std::ostream& operator<<(std::ostream& os, const Animals& animal);

#endif