#include <iostream>
#include <iomanip>
#include <string>

//Global static.
static int ani_count = 0;	

class Animal_stat
{
public:
	Animal_stat() : animalNum_(ani_count)
	{
		std::cout << __FUNCTION__ << " " << animalNum_ << " initialised. \n";
		ani_count++;
	}

	~Animal_stat()
	{
		std::cout << __FUNCTION__ << " " << animalNum_ << " destroyed.\n";
	}

private:
	int animalNum_;
};

//Also global static.
namespace
{
	Animal_stat bear1;
	Animal_stat bear2;
}

void ani_static()
{
	//Static local variable. 
	static int count = 0;
	static Animal_stat bear; 
	
	if (!count)
	{
		std::cout << __FUNCTION__ << " is not initialised.\n";
		count = 1;
	}
	else
	{
		std::cout << __FUNCTION__ << " called " << count << " times. \n";
		count++;
	}
}

int main(int argc, char** argv)
{
	std::cout << "Starting main\n";
	ani_static();
	ani_static();
	ani_static();
	std::cout << "Leaving main\n";
	return 0;
}