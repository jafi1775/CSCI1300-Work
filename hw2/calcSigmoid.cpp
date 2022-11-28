// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 2 - Problem 6

#include <iostream>
#include <cmath> 

using namespace std;

int main() 
{
    double x, sigmoid;
    cout << "Enter a value for x: " <<endl;
    cin >> x;
    sigmoid = 1 / (1 + exp(-x)); // calculating the sigmoid value

    cout << "The sigmoid for x=" << x << " is " << sigmoid <<endl;

    return 0;
}