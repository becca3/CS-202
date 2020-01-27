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

char* str_dup(const char* cstr)
{
	//Creates a C-string on the heap.
	char* newcstr = new char[string_size(cstr)];

	//Loops and copies each character of cstr to newcstr.
	for (unsigned int i = 0; i < string_size(newcstr) - 1; ++i)
		newcstr[i] = cstr[i];

	return newcstr;
}

int find_a(const char* cstr, const char* a)
{
	int cstr_size = string_size(cstr);
	int a_size = string_size(a);

	return -1;
}