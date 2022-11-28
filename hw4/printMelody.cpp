// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 4 - Problem 6

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double frequency;
    int octave;
    string note;
    cout << "What is your frequency?" << endl;
    cin >> frequency;
    if (frequency < 32.7 || frequency > 4186)
    {
        cout << "Your note is not on a piano." << endl;
        return 0;
    }
    frequency = 12 * log2(frequency/32.7);
    
    frequency= round(frequency); // have to do a rounding code note just change variable 

    if (frequency > 12)
    {
        frequency -=12;
        octave++;
    }
    else
    {
        switch (int frequency = frequency)
        {
            case 1: note = "C"; break;
            case 2: note = "Db"; break;
            case 3: note = "D"; break;
            case 4: note = "Eb"; break;
            case 5: note = "E"; break;
            case 6: note = "F"; break;
            case 7: note = "Gb"; break;
            case 8: note = "G"; break;
            case 9: note = "Ab"; break;
            case 10: note = "A"; break;
            case 11: note = "Bb"; break;
            case 12: note = "B"; break;
            break;
        }
    }
   
    cout<< "Your note is " << note << octave << endl;
    return 0;
}