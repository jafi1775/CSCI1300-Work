// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 4 - Problem 4

#include <iostream>
using namespace std;

int main()
{
    int height; 
    char letter= 'a';
    cout << "Enter the height:" << endl; // prompts the user for height of alphabet trianle
    cin >> height;
    if (height<=0) // accounts for invalid inputs for height
    {
        cout << "Invalid input." << endl;
    }
    else 
    {
        for(int i=0; i < height; i++) // i is representative of the rows in the triangle (horizontal)
        {
            for(int j=0; j < 2*i +1; j++) // j is representative of the columns (vertical), j is dependent on the value of i
            {
            
                cout << letter; // prints out each letter
                letter++; // increments the letter in the alphabet

                if (letter == 123) // if the letter is about to exceed z
                {
                    letter = 'a'; //resets the alphabet
                }
                
                    
        

            }
            cout << endl; // acts as a return for the code to a new row
        }
        
    }


    return 0;
}