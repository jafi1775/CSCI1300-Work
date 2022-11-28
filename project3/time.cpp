// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 3, Time implementation

#include <iostream>
#include "time.h"

using namespace std;


Time :: Time()
{
    time = 12;
    time_counter = 0;
}

Time :: Time(int new_time)
{
    time = new_time;
    time_counter = 0;
}

int Time :: getTime()
{
    return time;
}

void Time :: setTime(int new_time)
{
    time = new_time;
}

int Time :: getTimeCount()
{
    return time_counter;
}

void Time :: setTimeCount(int count)
{
    time_counter = count;
}

int Time :: randTime()
{
    
}
