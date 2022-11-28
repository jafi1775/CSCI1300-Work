// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 5, Question 1

#include <iostream>
using namespace std;

int main()
{
    int length = 0; // for the sequence array
    int upper_case = 65; // for upper case letters of the letters array
    int lower_case = 97; // for lower case letters of the letters array

    int distance[10]; // defining the distance array
    for (int i=0; i < 10; i++) 
    {
        distance[i] = 5+i; // starting at 5 and increasing by 1
        cout << distance[i] << endl;
    }

    string cities[5] = {"Boulder", "NYC", "LA", "Chicago", "Houston"};
    for (int i=0; i<5; i++) // prints out each city 
    {
        cout << cities[i] << endl;
    }

    int sequence[100]; 
    for (int i=0; length < 100; i++ ) // length is the number of elements that should be inside the array
    {
        if (i % 6 == 0 && i != 0) // if the iteration of i is divisible by zero without any remainder (not starting from 0)
        {
            sequence[length] = i; // length represents the index of each element
            cout << sequence[length] << endl;
            length++; 
        }
        else 
        {
            continue;
        }
    }

    char letters[52]; // the length of two alphabets 
    for (int i= 0; i < 52; i++)
    {
        if ( i % 2 == 0) // if i is even print an upper case letter
        {
            letters[i] = upper_case; // upper case variable is first defined as 65 which is "A"
            upper_case++; // increase by 1 moving to the next upper case letter
        }
        else // if i is off print a lower case letter
        {
            letters[i] = lower_case; // lower case variable is first defined as 97, which is "a"
            lower_case++; // increase by 1 moving to the next lower case letter
        }
        cout << letters[i] << endl;
    }

    return 0;

}
