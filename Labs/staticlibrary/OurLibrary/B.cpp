#include "pch.h"
#include "B.h"
#include <iostream>

B::B()
{
	value_ = 4;
}

void B::PrintFoo()
{
	std::cout << value_ << "\n";
}