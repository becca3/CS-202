/*
Program: Homework 3
Author: Rebecca Morgan
Date: 7th Feburary 2020
Description: Command line tokeniser.
*/

#include "tokeniser.h"

void print_token(const token& t);
void print_tokens(const std::vector<token>& tokens);
void line_to_tokens(std::vector<token>& tokens, const std::string& line, const size_t& row);
bool does_file_exist(const char* file);
std::vector<std::string> file_to_lines(const char* file);
std::vector<std::string> get_input();

int main(int argc, char** argv)
{
	std::vector<std::string> lines;
	std::vector<token> tokens;
	bool iostream = true;

	for (int x = 0; x < argc; ++x)
	{
		if (strstr(argv[x], ".txt") != nullptr)
		{
			if (does_file_exist(argv[x]))
			{
				iostream = false;
				lines = file_to_lines(argv[x]);

				for (size_t i = 0; i < lines.size(); ++i)
				{
					line_to_tokens(tokens, lines[i], i + 1);
				}

				print_tokens(tokens);
				return 0;
			}
		}
	}

}