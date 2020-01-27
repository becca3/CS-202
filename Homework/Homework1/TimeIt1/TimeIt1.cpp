/*
Program: Homework 1 - Time It
Author: Rebecca Morgan
Date: 24th January 2020
Description: Making a stopwatch.
*/

#include "TimeIt1.h"

using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::steady_clock;

Stopwatch::Stopwatch() 
{
    this->startTime = steady_clock::now();
    this->running = true;
}

void Stopwatch::start() 
{
    this->startTime = steady_clock::now();
    this->running = true;
}

void Stopwatch::stop() 
{
    if (this->running) 
    {
        this->endTime = steady_clock::now();
        this->running = false;
    }
}

double Stopwatch::Seconds() 
{
    if (this->running)
    {
        duration<double, std::ratio<1, 1>> time_span = duration_cast<duration
            <double>>(steady_clock::now() - this->startTime);
        return time_span.count();
    }
    else 
    {
        duration<double, std::ratio<1, 1>> time_span = duration_cast<duration
            <double>>(this->endTime - this->startTime);
        return time_span.count();
    }
}

double Stopwatch::Milli() 
{
    if (this->running)
    {
        duration<double, std::ratio<1, 1000>> time_span = duration_cast
            <duration<double>>(steady_clock::now() - this->startTime);
        return time_span.count();
    }
    else {
        duration<double, std::ratio<1, 1000>> time_span = duration_cast
            <duration<double>>(this->endTime - this->startTime);
        return time_span.count();
    }
}