/*
Program: Homework 1 - Time It
Author: Rebecca Morgan
Date: 24th January 2020
Description: Making a stopwatch.
*/

#include "TimeIt1.h"

void StopWatch::Start()
{
	auto start = std::chrono::system_clock::now();
}

void StopWatch::Restart()
{

}

void StopWatch::Stop()
{
	auto end = std::chrono::system_clock::now();
}

void StopWatch::Milli()
{
	auto milli = std::chrono::milliseconds();
}