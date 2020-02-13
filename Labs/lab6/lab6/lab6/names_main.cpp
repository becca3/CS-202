#include "names.h"

//27th is test day 

namespace fun2
{
	void foo()
	{
		std::cout << "This is another foo function! \n";
	}
}

void foo()
{
	std::cout << "Causes a conflict?! \n";
}

int main(int argc, char** argv)
{
	foo();

	using fun::foo; 
	foo();

	fun2::foo();
	return 0;
}