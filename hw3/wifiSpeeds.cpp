// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 3 - Problem 4

#include <iostream>
using namespace std;

int main()
{
    double wifispeed_1, wifispeed_2, wifispeed_3; // declaring each day's wifi speed

    cout << "Enter wifi speeds over the last 3 classes:" << endl; // prompting input for wifi speeds 
    cin >> wifispeed_1 >> wifispeed_2 >> wifispeed_3;

    if ((wifispeed_1 < 0) || (wifispeed_2 < 0) || (wifispeed_3 < 0)) // check for invalid inputs 
    {
        cout << "Please enter a valid input." << endl; 
    }
    else 
    {
        if (wifispeed_1 < wifispeed_2 && wifispeed_2 < wifispeed_3) // for when wifispeeds are getting faster 
        {
            cout << "The wifi is getting faster!" << endl;
        }
        else if (wifispeed_1 > wifispeed_2 && wifispeed_2 > wifispeed_3) // for when wifi speeds are getting slower
        {
            cout << "The wifi is getting slower!" << endl;
        }
        else // for when wifi speeds are unsorted or it two of more speeds ar ethe same 
        {
            cout << "The wifi speed is changing unpredictably." << endl;
        }
    }
    return 0;

}