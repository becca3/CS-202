/*
Program: Homework 3
Author: Rebecca Morgan
Date: 7th Feburary 2020
Description: Command line tokeniser.
*/

#ifndef TOKENISER_H
#define TOKENISER_H


#include <iostream>
#include <string>
#include <vector>
#include <utility>

//Functions.

bool LineToTokens(const std::string& line, 
	std::vector<std::string>& tokens);

bool ReadLine(std::istream& is, 
	std::vector<std::string>& tokens,
	std::vector<std::pair<int, int>>& linecols);

void PrintTokens(std::ostream& os, 
	const std::vector<std::string>& tokens,
	const std::vector<std::pair<int, int>>& linecols);

#endif
