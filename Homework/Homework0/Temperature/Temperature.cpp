///*
//Program: Homework 0 
//Author: Rebecca Morgan
//Date: 19th January 2020
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
	double return_val = 0.0;
	return_val = strtod(str, nullptr);

	//Modifies double from celcius to fahrenheit.
	return_val *= 9.0 / 5.0;
	return_val += 32;

	return return_val;
}

//Takes C-string, str, which
//represents temperature in Fahrenheit
//and converts it to Celcius.
double cpp_ftoc(const char* cstr)
{
	double return_val = 0.0;
	std::string str(cstr);
	return_val = std::stod(str);

	//Modifies the double from fahrenheit to celcius.
	return_val -= 32;
	return_val *= 5.0 / 9.0;

	return return_val;
}

int main(int argc, const char** argv)
{
	c_ctof;
	cpp_ftoc;
	return 0;
}



















