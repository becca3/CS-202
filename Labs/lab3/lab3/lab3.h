#ifndef LAB3_H
#define LAB3_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <algorithm>
#include "Catch2.h"

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

	void setAnimal(std::string animal);
	void setName(std::string name);
	void getName(std::string& name);

	std::unique_ptr<Animals> animalMake(const std::string name, const std::string animal);
};

class Vector3f
{
public: 
		

private: 
	float x;
	float y;
	float z;

	/*bool operator == (const Vector3f& a, const Vector3f& b) { return (a.x == b.x) && (a.y == b.y) && (a.z == b.z); }
	bool operator != (const Vector3f& a, const Vector3f& b) { return (a.x != b.x) || (a.y != b.y) || (a.z != b.z); }*/
};
#endif
