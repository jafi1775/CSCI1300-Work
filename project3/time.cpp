// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 3, Time implementation

#include <iostream>
#include "time.h"

using namespace std;


Time :: Time()
{
    timetime = 12;
    time_counter = 0;
}

Time :: Time(int new_time)
{
    timetime = new_time;
    time_counter = 0;
}

int Time :: getTime()
{
    return timetime;
}

void Time :: setTime(int new_time)
{
    timetime = new_time;
}

int Time :: getTimeCount()
{
    return time_counter;
}

void Time :: setTimeCount()
{
    time_counter++;
}

void Time :: randTime()
{

    timetime = 24 - (rand() % (10) + 12);
}

void Time :: addTime()
{
    timetime ++;
}
