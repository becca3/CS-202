#ifndef LAB3_H
#define LAB3_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Animals
{
private:

	std::string animal_;
	std::string x_name_;

public:
	Animals();
	Animals(std::string animal);
	Animals(const Animals& type);
	virtual ~Animals();

	void setColor(int color);
	void setOwner(std::string name);
	void getOwner(std::string& name);
	std::string properties();
	std::unique_ptr<Animals> animalMake(const std::string name, const int color);
};


#endif
