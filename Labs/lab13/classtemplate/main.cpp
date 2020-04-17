#include <iostream>
#include <string>

template <typename WrapType>
class Wrapper
{
public:
	Wrapper(const WrapType& obj) : obj_(obj)
	{

	}
private:
	WrapType obj_;

	template <typename T>
	friend std::ostream& operator<<(std::ostream& os, const Wrapper<T>& w);

};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Wrapper<T>& w)
{
	os << w.obj_;
	return os;
}

int main(int argc, char** argv)
{
	Wrapper<std::string> s{ "The time is: " };
	Wrapper<int> w{ 3 };
	
	std::cout << s << " " << w << "\n";
	return 0; 
}