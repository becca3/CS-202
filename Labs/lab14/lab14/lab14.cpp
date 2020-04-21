#include <iostream>

template <typename T> 
T twice(const T& x)
{
	return x + x;
}

std::string twice(const char* x)
{
	return twice(std::string(x));
}

int main(int argc, char** argv)
{
	std::cout << twice(2) << std::endl;
	std::cout << twice(2.3) << std::endl;
	std::cout << twice(std::string("Hello")) << std::endl;
	std::cout << twice(std::string("World")) << std::endl;

	//std::cout << twice("World") << std::endl;
	return 0;
}