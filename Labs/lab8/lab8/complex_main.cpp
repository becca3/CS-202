#include "complex.h"
#include <iostream>


int main(int argc, char** argv)
{
	std::cout << std::fixed;

	std::cout << Complex() << "\n";
	std::cout << Complex(2, 5) + Complex(2, 3) << "\n";
	std::cout << 1.0 + Complex(2, 5) << "\n";
	return 0;
}