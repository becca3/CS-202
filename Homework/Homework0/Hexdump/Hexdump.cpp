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
    char file_name[50];
    int x;
    bool VERBOSE = true;

    if (VERBOSE)
    {
        std::cout << "HEXDUMP:\n";
        std::cout << "Produce a hexadecimal dump of a file.\n";
    }

    if (argc <= 1)
    {
        std::cout << "Enter the name of the file you want to analyse: \n";
        std::cin.getline(file_name, sizeof(file_name));
        handle(file_name);
    }
    else
    {
        for (x = 1; x < argc; ++x)
        {
            handle(argv[x]);
        }
    }

    if (VERBOSE)
    {
        std::cout << "End input.\n";
    }
    return 0;
}

//Function to handle input. 
void handle(char file_name[])
{
    long int addr;
    unsigned char buffer[20];
    long int cnt;
    long int cnt2;
    std::ifstream file_in;
    long n;

    //Open file.
    file_in.open(file_name);

    //Checks if file can be opened. 
    if (!file_in)
    {
        std::cout << "\n";
        std::cout << "Error!\n";
        std::cout << "Cannot open" << file_name << "\n";
        return;
    }

    std::cout << "Hexdump of: " << file_name << "\n";