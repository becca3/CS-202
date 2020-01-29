#include "lab2.h"

int main(int argc, char** argv)
{
	//Create a pointer to the object. 
	

	//int ptr2fun2 = { nullptr };

	//Unique pointer of an object. 
	std::cout << "Creating a unique ptr to an object.\n";
	functions* ptr2fun2;

//	std::cout << ptr2fun2;


	//Default and deconstructor.
	functions();
	functions d;
	d.show();

	//Copy constructor.
	functions x2(5, 50);
	functions x1 = x2; //Passes object by value.
	std::cout << "x2.a = " << x2.geta() << ", x2.b = " << x2.getb() << "\n";
	std::cout << "x1.a = " << x1.geta() << ", x1.b = " << x1.getb() << "\n";

	//Pass by ref.
	functions(y);
	std::cout;

	//Vector of objects.
	std::vector<functions> nums;
	for (int i = 0; i < 5; i++)
	{
		nums.push_back(functions());
	}
	return 0;

}