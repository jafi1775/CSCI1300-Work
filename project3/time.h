// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 3, time header

#include <iostream>
using namespace std;

class Time
{
    private: 
        int time;
        int time_counter;

    public:
        Time();
        Time(int new_time);
        int randTime();
        int getTime();
        void setTime(int new_time);
        int getTimeCount();
        void setTimeCount(int count);
};
