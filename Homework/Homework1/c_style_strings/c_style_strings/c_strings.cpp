/*
Program: Homework 1 - c_style_strings
Author: Rebecca Morgan
Date: 27th January 2020
Description: C style strings program.
*/

#include <iostream>

//Returns length of C-string.
unsigned int string_size(const char* cstr)
{
	unsigned int size = 0;

	while (cstr[size] != '\0')
		++size;

	//The '\0' counts as a character.
	return size + 1;
}