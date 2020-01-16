#include<iostream>
#include<string>

//Variables.
std::string ans;
const char* str;

//Functions. 
double cpp_ftoc(const char* str);
double c_ctof(const char* str);

//Main.
int main(int argc, char** argv)
{
	std::cout << "1 - Celsius to fahrenheit or \n";
	std::cout << "2 - Fahrenheit to celcius? \n";
	std::cin >> ans;

	if (ans == "1")
	{
		c_ctof(str);
	}
	else if (ans == "2")
	{
		cpp_ftoc(str);
	}
	else
	{
		std::cout << "invalid input \n";
	}
	return 0;
}

//C++ 
double cpp_ftoc(const char* str)
{

}

//C
double c_ctof(const char* str)
{

}