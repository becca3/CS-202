/*
Program: Homework 0 - Hexdump 
Author: Rebecca Morgan
Date: 19th January 2020
Description: Program to dump contents of a file as hexadecimal characters. 
*/

# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <ctime>

void handle(char file_in_name[]);

int main(long argc, char* argv[])
{
    char file_in_name[50];
    int x;
    bool VERBOSE = true;

    if (VERBOSE)
    {
        std::cout << "HEXDUMP:\n";
        std::cout << "Produce a hexadecimal dump of a file.\n";
}