#include <iostream>
#include <iomanip>
#include <string>

void ani_static()
{
	//Static local variable. 
	static int count = 0;
	
	if (!count)
	{
		std::cout << __FUNCTION__ << " is not initialised.\n";
		count = 1;
	}
	else
	{
		std::cout << __FUNCTION__ << " called " << count << " times \n";
		count++;
	}
}

int main(int argc, char** argv)
{
	ani_static();
	ani_static();
	ani_static();
	return 0;
}