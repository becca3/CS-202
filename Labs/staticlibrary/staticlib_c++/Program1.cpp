#include <iostream>
#include <A.h>
#include <B.h>


#pragma comment(lib, OurLibrary.lib)


int main(int argc, char** argv)
{
	functionfromA();

	B b;
	b.printFoo();

	std::cout << "Hello World! \n";
	return 0;
}