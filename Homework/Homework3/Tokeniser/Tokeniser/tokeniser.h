/*
Program: Homework 3
Author: Rebecca Morgan
Date: 7th Feburary 2020
Description: Command line tokeniser.
*/

#ifndef TOKENISER_H
#define TOKENISER_H

#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>

struct token
{
	std::string val;
	std::size_t col;
	std::size_t row;

	token(const std::string& str, const std::size_t& c, const std::size_t& r);
};

#endif //TOKENISER_H