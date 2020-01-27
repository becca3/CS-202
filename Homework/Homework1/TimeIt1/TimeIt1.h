/*
Program: Homework 1 - Time It
Author: Rebecca Morgan
Date: 24th January 2020
Description: Making a stopwatch.
*/

#ifndef TIMEIT1_INCLUDE
#define TIMEIT1_INCLUDE

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <chrono>

class Stopwatch {
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point endTime;
    bool running;

public:
    Stopwatch();

    void start();
    void stop();

    double Seconds();
    double Milli();
};

#endif
