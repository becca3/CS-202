/*
Program: Homework 1 - Time It
Author: Rebecca Morgan
Date: 24th January 2020
Description: Making a stopwatch. 
*/

#include "TimeIt1.h"

std::random_device r;
std::default_random_engine engine(r());
std::uniform_int_distribution<int> randomDist(INT32_MIN, INT32_MAX);

std::vector<int> target = { randomDist(engine) };
std::vector<int> nums;

int main(int argc, char** argv)
{
	StopWatch watch = StopWatch();

	for (int x = 0; x < 1000000000; x++)
	{
		nums.push_back(x);
	}

	watch.Start();
	std::search(nums.begin(), nums.end(), target.begin(), target.end());
	std::cout << watch.Stop() << " seconds for a linear search." << std::endl;

	watch.Start();
	std::binary_search(nums.begin(), nums.end(), target[0]);
	std::cout << watch.Stop() << " seconds for a binary search." << std::endl;

	return 0;
}