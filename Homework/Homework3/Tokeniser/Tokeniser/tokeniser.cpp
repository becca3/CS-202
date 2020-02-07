/*
Program: Homework 3 
Author: Rebecca Morgan
Date: 7th Feburary 2020
Description: Command line tokeniser.
*/

#include <iostream>
#include <string>
#include <vector>

bool LineToTokens(const std::string& line, 
	std::vector<std::string>& tokens); 

bool ReadLine(std::istream& is, 
	std::vector<std::string>& tokens, 
	std::vector<std::pair<int, int>>& linecols);

void PrintTokens(std::ostream& os, 
	const std::vector<std::string>& tokens, 
	const std::vector<std::pair<int, int>>& linecols);

int main(int argc, char** argv)
{
	return 0;
}