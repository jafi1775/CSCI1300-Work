// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 4 - Problem 2

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int number;
    cout << "Enter  a value between 1 and 1000:" << endl; // prompting user for input
    cin >> number;

    while ( number<=1 || number>=1000) // to weed out invlaid input and require valid input before running program
    {
        cout << "Invalid input." << endl;
        cout << "Enter  a value between 1 and 1000:" << endl;
        cin >> number;
    }
    if (number > 1 && number < 1000) // somewhat unneccessary double checking of valid input 
    {
        cout << number << endl; // to print out original input

       while (number != 1) // to stop the program once the number equals 1
       {
            if (number % 2 == 0) // for even numbers
            {
                number = number/2; // tried to use the floor command but it was breaking my code and seemed unecessary
            }
            else // for odd numbers 
            {
                number = 3 * number + 1;
            }

            cout << number << endl; // to print out number after each calculation 
       }
    }

    return 0;

}