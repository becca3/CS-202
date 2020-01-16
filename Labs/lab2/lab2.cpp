#include"lab2.h"

int main(int argc, char** argv)
{
	//Default and deconstructor.
	functions();

	//Copy constructor.
	functions x2(5, 50);
	functions x1 = x2;
	std::cout << "x2.x = " << x2.geta() << ", x2.y = " << x2.getb() << "\n";
	std::cout << "x1.x = " << x1.geta() << ", x1.y = " << x1.getb() << "\n";
}