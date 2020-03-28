#include "complex.h"
#include <iostream>


int main(int argc, char** argv)
{
	std::cout << std::fixed;

	std::cout << Complex() << "\n";
	std::cout << Complex(2, 5) + Complex(2, 3) << "\n";
	std::cout << 1.0 + Complex(2, 5) << "\n";

	Complex complex1(7, 8);
	Complex complex2(10, 20);

	std::cout << complex1 << "\n";
	std::cout << complex2 << "\n"; 

	complex1 += complex2;

	std::cout << complex1;
	return 0;
}