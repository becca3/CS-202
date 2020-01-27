/*
Program: Homework 1 - Time It
Author: Rebecca Morgan
Date: 24th January 2020
Description: Making a stopwatch. 
*/

//#pragma warning(disable : 4996)

#include "TimeIt1.h"

//auto start = std::chrono::system_clock::now();
//auto end = std::chrono::system_clock::now();

int main(int argc, char** argv)
{
	StopWatch watch = StopWatch();

	std::vector<int> nums;

	for (int x = 0; x < 100000; x++)
	{
		nums.push_back(x);
	}

	watch.Start();
	std::search(nums.begin(), nums.end(), 49998, 49998);
	std::cout << watch.Stop() << " seconds for a linear search." << std::endl;

	watch.Start();
	std::binary_search(nums.begin(), nums.end(), 50000);
	std::cout << watch.Stop() << " seconds for a binary search." << std::endl;
	return 0;
}