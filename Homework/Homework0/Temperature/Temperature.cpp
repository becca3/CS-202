///*
//Program: Homework 0 
//Author: Rebecca Morgan
//Date: 17th January 2020
//Description: Temperature conversion program. 


#include <string>
#include <iostream>

using std::string;
using std::stod;

#include <cstdlib>
using std::strtod;

#include <iostream>
using std::cout;
using std::endl;

#include <stdexcept>
using std::invalid_argument;

//Takes the given C-string, cstr, which
//represents a temperature in Celcius
//and converts it to Fahrenheit using the 
//strtod method in the header cstdlib.

double c_ctof(const char* cstr)
{
	double return_value = 0.0;

	return_value = strtod(cstr, nullptr);

	//Modifies the double from celcius
	//to fahrenheit.
	return_value *= 9.0 / 5.0;
	return_value += 32;

	return return_value;
}

//Takes the given C-string, cstr, which
//represents a temperature in Fahrenheit
//and converts it to Celcius using the 
//stod method in the header string.

double cpp_ftoc(const char* cstr)
{
	double return_value = 0.0;

	//Creates a temporary C++string that
	//stod uses.
	string str(cstr);
	return_value = stod(str);

	//Modifies the double from fahrenheit
	//to celcius.
	return_value -= 32;
	return_value *= 5.0 / 9.0;

	return return_value;
}

int main(int argc, const char** argv)
{
	std::cout << "Temp \n";
	c_ctof;
	cpp_ftoc;
	return 0;
}



















