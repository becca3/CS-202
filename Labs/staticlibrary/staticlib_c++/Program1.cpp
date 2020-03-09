#include <iostream>
#include <A.h>
#include <B.h>

#ifdef _WIN32

#pragma comment(lib, "OurLibrary.lib")

int main(int argc, char** argv)
{
	functionfromA();

	B b;
	b.PrintFoo();

	std::cout << "Hello World! \n";
	return 0;
}

#endif 