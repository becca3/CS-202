#include <iostream>
#include <string>

template <typename WrapType>
class Wrapper
{
public:
	Wrapper(const WrapType& obj) : obj_(obj)
	{

	}
//private:
	WrapType obj_;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Wrapper<T>& w)
{
	os << w.obj_;
	return os;
}

int main(int argc, char** argv)
{
	Wrapper<int> w{ 2 };
	Wrapper<std::string> s{ "Hello world" };

	std::cout << w << " " << s << "\n";
	return 0; 
}