/*
Program: Homework 1 - Time It
Author: Rebecca Morgan
Date: 24th January 2020
Description: Making a stopwatch.
*/

#ifndef TIMEIT1_H
#define TIMEIT1_H

#include<iostream>
#include<chrono>
#include<ctime>
#include<vector>
#include<algorithm>

class StopWatch
{
public:

	//Member functions.

	//Function to start the stopwatch.
	StopWatch();
	
	void Start();

	//Function to stop the stopwatch.
	double Stop();

	//Deconstructor.
	~StopWatch();

	//Function to restart the stopwatch.
	//void Restart();

	//Function to report time elapsed in milliseconds. 
	//void Milli();

private:
	std::chrono::system_clock::time_point StartTime;
	std::chrono::system_clock::time_point EndTime;
};

#endif
