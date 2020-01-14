/*
Program: Lab 1 - Flow of control
Author: Rebecca Morgan
Date: 14th January 2020
Description: Review of flow of control structures
*/

#include <iostream>
#include <string>

//Functions.

//if/else loop.
void struc1() 
{
	std::cout << "if/else loop \n";
	if (100 / 50 == 2)
	{
		std::cout << "Even. \n";
	}
	else
	{
		std::cout << "Uneven. \n";
	}
}

//switch statement.
void struc2()
{
	std::cout << "switch statement \n";
	int n = 3;
	switch (n)
	{
		case 1: std::cout << "First place \n";
			break;
		case 2: std::cout << "Second place \n";
			break;
		case 3: std::cout << "Third place \n";
			break;
		default: std::cout << "Didn't place. \n";
			break;
	}
}

//while loop.
void struc3()
{
	std::cout << "while loop \n";
	int n = 5;
	while (n < 10)
	{
		std::cout << n << "\n";
		n++;
	}
}

//do/while loop.
void struc4()
{
	std::cout << "do/while loop \n";
	int ans = 0;
	int sum = 0;

	do
	{
		std::cout << "Enter 0 to see the total. \n";
		std::cout << "Enter an integer: \n";
		std::cin >> ans;
		sum += ans;
	} 
	while (ans != 0);
	
	std::cout << "Total = " << sum;
	std::cout << "\n";
	
}

//for loop.
void struc5()
{
	std::cout << "for loop \n";
	for (int n = 0; n <= 5; n++)
		std::cout << n << "\n";
	std::cout << "\n";
}

//range based for loop.
void struc6()
{
	std::cout << "range based for loop \n";
	for (int n : {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
		std::cout << n << "\n";
}

//Main.
int main(int argc, char** argv)
{
	struc1(); //Function call.
	std::cout << "\n";
	struc2();
	std::cout << "\n";
	struc3();
	std::cout << "\n";
	struc4();
	std::cout << "\n";
	struc5();
	std::cout << "\n";
	struc6();
	std::cout << "\n";
	return 0;
}