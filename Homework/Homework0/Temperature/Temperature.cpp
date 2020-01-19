///*
//Program: Homework 0 
//Author: Rebecca Morgan
//Date: 17th January 2020
//Description: Temperature conversion program. 


#include <string>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

//Takes C-string, str, which
//represents temperature in Celcius
//converts it to Fahrenheit using the 
//strtod method.

double c_ctof(const char* str)
{
	double return_value = 0.0;

	return_value = strtod(str, nullptr);

	//Modifies double from celcius
	//to fahrenheit.
	return_value *= 9.0 / 5.0;
	return_value += 32;

	return return_value;
}

//Takes C-string, str, which
//represents temperature in Fahrenheit
//and converts it to Celcius.

double cpp_ftoc(const char* cstr)
{
	double return_value = 0.0;

	std::string str(cstr);
	return_value = std::stod(str);

	//Modifies the double from fahrenheit
	//to celcius.
	return_value -= 32;
	return_value *= 5.0 / 9.0;

	return return_value;
}

int main(int argc, const char** argv)
{
	c_ctof;
	cpp_ftoc;
	return 0;
}



















