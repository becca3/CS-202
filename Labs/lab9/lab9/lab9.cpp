#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

//Global static.
static int ani_count = 0;	

class Animal_stat
{
public:
	Animal_stat() : animalNum_(ani_count)
	{
		std::cout << __FUNCTION__ << " " << animalNum_ << " initialised. \n";
		ani_count++;

		std::ostringstream ostr;
		ostr << "Animal_stat" << animalNum_;
		polarBear_ = ostr.str();
	}

	~Animal_stat()
	{
		std::cout << __FUNCTION__ << " " << animalNum_ << " destroyed.\n";
	}

	void printpolarBear()
	{
		std::cout << polarBear_ << "\n";
	}

private:
	int animalNum_;
	//Static member variable.
	static std::string polarBear_;
};

std::string Animal_stat::polarBear_{ "roar" };

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

	bear.printpolarBear();
}

int main(int argc, char** argv)
{
	std::cout << "Starting main\n";

	bear1.printpolarBear();
	bear2.printpolarBear();

	ani_static();
	ani_static();
	ani_static();

	bear1.printpolarBear();
	std::cout << "Leaving main\n";
	return 0;
}