// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 2 - Problem 4

#include <iostream>
using namespace std;

int main()
{
    int bSnowRate = 5; // bSnowRate is the variable name for Breckenridge Snowfall rate minus the Breckenridge Melt Rate  
    int vSnowRate = 12;
    int cmSnowRate = 2;
    int X; // Days in the future of the prediction


    cout << "How many days in the future would you like a prediction for? " <<endl;
    cin >> X;
    int bSnow = bSnowRate * X +25; // new snow fallen + snow already there for each resort
    int vSnow = vSnowRate * X + 28;
    int cmSnow = cmSnowRate * X + 40;

    cout << "Breckenridge will have " << bSnow << " inches, Vail will have " << vSnow << " inches, and Copper Mountain will have " << cmSnow << " inches." <<endl;

    return 0;

}