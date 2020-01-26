/*
Program: Homework 1 - Time It
Author: Rebecca Morgan
Date: 24th January 2020
Description: Making a stopwatch. 
*/

#pragma warning(disable : 4996)

#include "TimeIt1.h"

auto start = std::chrono::system_clock::now();
auto end = std::chrono::system_clock::now();

int main(int argc, char** argv)
{
	//Objects of class StopWatch.
	StopWatch begin;
	StopWatch finish;
	StopWatch mill;

	//Accessing member functions.
	begin.Start();
	//std::cout << "This is a test string. How fast can you read this?!\n";
	finish.Stop();

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	//Outputs time taken to complete a task.
	std::cout << "Finished task at: " << std::ctime(&end_time)
		<< "Elapsed time: " << elapsed_seconds.count() << "s\n";

	mill.Milli();
	std::cout << "Time in milliseconds is: " << 
		elapsed_seconds.count() << "s\n";
	return 0;
}