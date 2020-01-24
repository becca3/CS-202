/*
Program: Homework 1 - Time It
Author: Rebecca Morgan
Date: 24th January 2020
Description: Making a stopwatch.
*/

#ifndef TIME_IT_1_H
#define TIME_IT_1_H

#include<iostream>
#include<chrono>
#include<ctime>

class StopWatch
{
public:

	//Member functions.

	//Function to start the stopwatch.
	void Start();

	//Function to restart the stopwatch.
	void Restart();

	//Function to stop the stopwatch.
	void Stop();
};

#endif
