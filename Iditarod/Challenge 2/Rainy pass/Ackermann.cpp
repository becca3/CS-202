#include <iostream>
#include "TimeIt1.h"

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
	std::cout << "Ackermann \n";
	//This is the higest number my PC can handle!
	StopWatch timer;
	timer.start();

	std::cout << acker(3, 7) << std::endl;

	timer.stop();
	res.acker = timer.Milli();
	std::cout << timer.Seconds() << " seconds. (" << timer.Milli() << "ms)" << std::endl;

	return 0;
}