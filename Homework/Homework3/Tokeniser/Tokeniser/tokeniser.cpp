/*
Program: Homework 3 
Author: Rebecca Morgan
Date: 7th Feburary 2020
Description: Command line tokeniser.
*/

#include "tokeniser.h"

token::token(const std::string& str, const std::size_t& c, const std::size_t& r)
{
	val = str;
	col = c;
	row = r;
}

void print_token(const token& t)
{
	std::cout << "Row " << t.row;
	std::cout << ", Column " << t.col;
	std::cout << ": \"" << t.val;
	std::cout << "\"" << std::endl;
}

void print_tokens(const std::vector<token>& tokens)
{
	for (const token& t : tokens)
		print_token(t);
}

void line_to_tokens(std::vector<token>& tokens, const std::string& line, const size_t& row)
{
	size_t col;
	std::string str;
	std::istringstream iline(line);

	if (!line.empty())
	{
		while (!iline.eof())
		{
			iline >> str;

			col = line.find(str) + 1;
			token t(str, col, row);
			tokens.push_back(t);
		}
	}
	else //line.empty()
	{
		token t("Empty Line", 1, row);
		tokens.push_back(t);
	}
}

bool does_file_exist(const char* file)
{
	std::ifstream ifile(file);
	return ifile.good();
}

std::vector<std::string> file_to_lines(const char* file)
{
	std::string line;
	std::ifstream ifile(file);
	std::vector<std::string> lines;

	while (!ifile.eof())
	{
		getline(ifile, line);

		if (!ifile.eof())
		{
			lines.push_back(line);
		}
	}

	return lines;
}