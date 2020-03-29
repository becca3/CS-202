#include <iostream>

int acker(int m, int n)
{
	if (m == 0 && n > 0)
	{
		return n + 1;
	}

	if (m > 0 && n == 0)
	{
		return acker(m - 1, 1);
	}

	if (m > 0 && n > 0)
	{
		return acker(m - 1, acker(m, n - 1));
	}

	return -1;
}

int main()
{
	std::cout << "Ackerman: \n";
	std::cout << acker(3, 1) << std::endl;
	std::cout << acker(3, 4) << std::endl;
	std::cout << acker(-1, -1) << std::endl;
	//Below is the highest I can do. I end up with a stack overflow if I go higher. 
	std::cout << acker(2, 1000) << std::endl;

	return 0;
}