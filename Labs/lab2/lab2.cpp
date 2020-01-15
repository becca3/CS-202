#include"lab2.h"

int main(int argc, char** argv)
{
	functions orig(5, 50); //Default constructor called. 
	functions item = orig; //Copy constructor called. 

	std::cout << "Default constructor: " << "item x = " << orig.getX() << ", item y = " << orig.getY() << "\n";
	std::cout << "Copy constructor: " << "item x = " << item.getX() << ", item y = " << item.getY();

}