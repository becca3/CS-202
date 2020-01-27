/*
Program: Homework 1 - Time It
Author: Rebecca Morgan
Date: 24th January 2020
Description: Making a stopwatch.
*/

#include "TimeIt1.h"

StopWatch::StopWatch()
{
	Start();
	EndTime = std::chrono::system_clock::now();
}

StopWatch::~StopWatch()
{

}

void StopWatch::Start()
{
	StartTime = std::chrono::system_clock::now();
}

//void StopWatch::Restart()
//{
//
//}

double StopWatch::Stop()
{
	EndTime = std::chrono::system_clock::now();
	return std::chrono::duration_cast<std::chrono::milliseconds>(EndTime - StartTime).count() / 100.0;
}

//void StopWatch::Milli()
//{
//	auto milli = std::chrono::milliseconds();
//}