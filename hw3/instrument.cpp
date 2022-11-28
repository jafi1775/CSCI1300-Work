// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 3 - Problem 6

#include <iostream>
using namespace std;

int main()
{
    int category, brass=0, woodwind=0, percussion=0; // variables for each inner switch statement
    cout << "Select a category: (1)Brass (2)Woodwind (3)Percussion" << endl;
    cin >> category;

    switch (category) // outer swtich for each instrument category 
    {
        case 1: cout << "Select an instrument: (1)Trumpet (2)Trombone" << endl; cin >> brass; // for brass instruments
            switch (brass) // cost of each brass instrument
            {
                case 1: cout << "Your instrument will be $350." << endl; break;
                case 2: cout << "Your instrument will be $400." << endl; break;
                default: cout << "Please enter a valid input." << endl; break;
            }
            break;
        case 2: cout << "Select an instrument: (1)Flute (2)Saxophone" << endl; cin >> woodwind; // for woodwind instruments 
            switch (woodwind) // cost of each woodwind instrument
            {
                case 1: cout << "Your instrument will be $325." << endl; break;
                case 2: cout << "Your instrument will be $425." << endl; break;
                default: cout << "Please enter a valid input." << endl; break;
            }
            break;
        case 3: cout << "Select an instrument: (1)Snare Drum (2)Cymbals" << endl; cin >> percussion; // for percussion instruments
             switch (percussion) //cost of each percussion instrument 
            {
                case 1: cout << "Your instrument will be $275." << endl; break;
                case 2: cout << "Your instrument will be $200." << endl; break;
                default: cout << "Please enter a valid input." << endl; break;
            }
            break;
        default: cout << "Please enter a valid input." << endl; break; // for any invalivd input

            
    }
    return 0;
}
    