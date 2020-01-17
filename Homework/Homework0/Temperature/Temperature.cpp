/*
Program: Homework 0 
Author: Rebecca Morgan
Date: 17th January 2020
Description: Temperature conversion program. 
*/
///* argc = 3 */

#include <iostream>
#include <cstdlib>
#include <string>

double cpp_ftoc(const char* str);
double c_ctof(const char* str);

int main(int argc, const char** argv)
{
	if (argc >= 2 && argv[1] == std::string("--ftoc"))
	{
		cpp_ftoc(argv[2]);
	}
}

double cpp_ftoc(const char* str)
{
	std::cout << "ftoc";
	return 0;
}

double c_ctof(const char* str)
{
	std::cout << "ctof";
	return 0;
}





























