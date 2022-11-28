// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 3 - Problem 2

#include <iostream>
using namespace std;

int main()
{
    double budget;
    char transportation;
   
    cout << "What is your budget?" << endl; // prompt user for budget input 
    cin >> budget;

    if (budget < 0 ) // to make sure input is valid 
    {
        cout << "Please enter a valid input." << endl;
    }

    else 
    {
        cout << "What mode of transportation would you like to take (B, T, or A)?" << endl; //prompt user for preferred mode of transportation
        cin >> transportation;

        if (transportation != 'A' && transportation != 'B' && transportation != 'T' )
        {
            cout << "Please enter a valid input." << endl;
        }
   
        else if (budget < 175.25) // for when budget isn't enough for any vacation
        {
            cout << "Sorry, this vacation is outside your budget." << endl;
        }
        else if (175.25 <= budget && budget < 240.66) // for when budget is only enough for the Bus
        {
            if (transportation == 'B')
            {
                cout << "Yes, this vacation is within your budget!" << endl;

            }
            else 
            {
                cout << "Sorry, this vacation is outside your budget." << endl;
            }
        }
        else if (240.66 <= budget && budget < 350.93) // for when budget is enough for Bus and Train
        {
            if (transportation == 'B' || 'T') 
            {
                cout << "Yes, this vacation is within your budget!" << endl;

            }
            else 
            {
                cout << "Sorry, this vacation is outside your budget." << endl;
            }
        }
        else // for when budget is enough for any option
        {
            cout << "Yes, this vacation is within your budget!" << endl;
        }

        return 0;    
    }
}

    
  