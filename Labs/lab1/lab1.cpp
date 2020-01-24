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
	int S = 1;
	int M = 2;
	int L = 3;
	int size = 1;
	std::cout << "if/else loop \n";

	if (size = 1)
	{
		std::cout << "Small \n";
	}
	else
	{
		std::cout << "Not the size you want. \n";
	}
}

//switch statement.
void struc2()
{
	std::cout << "switch statement \n";
	int a = 1;
	int b = 2;
	int c = 3;

	int jumpsuit = 3;
	switch (jumpsuit)
	{
		case 1: std::cout << "Red \n";
			break;
		case 2: std::cout << "Blue \n";
			break;
		case 3: std::cout << "Green \n";
			break;
		default: std::cout << "We don't have that colour. \n";
			break;
	}
}

//while loop.
void struc3()
{
	std::cout << "while loop \n";
	std::string colour = " red";

	int jumpsuit = 5;
	while (jumpsuit < 10)
	{
		std::cout << jumpsuit << colour << " jumpsuits."<< "\n";
		jumpsuit++;
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
	
	std::cout << "Total no. of jumpsuits = " << sum;
	std::cout << "\n";
	
}

//for loop.
void struc5()
{
	std::cout << "for loop \n";
	for (int n = 0; n <= 5; n++)
		std::cout << n << " Jumpsuits in cart" << "\n";
	std::cout << "\n";
}

//range based for loop.
void struc6()
{
	std::cout << "range based for loop \n";
	for (int n : {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
		std::cout << "Number of green jumpsuits in cart is: " << n << "\n";
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