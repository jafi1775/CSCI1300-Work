// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 7, Problem 3

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int my_cards = 0; // my card counter
    int input = 0; // input from user
    vector<int> your_cards; // partner card vector 


    while(input != 14) // run loop until Jack card has been found 
    {
        cout << "Please enter a number:" << endl; // propmt user for card input
        cin >> input; // store input value

        while(input <= 0 || input > 14) // while the input is not valid
        {
            cout << "The number should be an integer between 1 and 14." << endl;
            cout << "Please enter a number:" << endl;
            cin >> input;
        }
        
        if (input == 14) // if the jack has been found, exit the while loop
        {
            continue;
        }

        your_cards.push_back(input); // add input to end of vector

        if (input == 1) // if the input is 1
        {
            if(your_cards.size() == 1) // if there is only 1 element in the array

            {
                your_cards.erase(your_cards.begin()); // remove the element
                my_cards++; // increment my cards by 1
            }
            else 
            {
                your_cards.erase(your_cards.begin()); // remove the first 2 elemenets from the vector
                your_cards.erase(your_cards.begin());
                my_cards += 2; // increment my cards by 2
            }
        }

        if (input == 11 || input == 12 || input == 13) // if the input is 11 12 or 13
        {
            if(your_cards.size() == 1) // if there is only one element in the array 
            {
                your_cards.erase(your_cards.begin()); // remove the element 
                my_cards++; // increment my cards by 1
            }
            else 
            {
                your_cards.pop_back(); // remove the last 2 elements from the array 
                your_cards.pop_back(); 
                my_cards += 2; // increment my cards by 2
            }
        }

    }

    cout << "Your remaining cards are: " ; 

    for (int i = 0; i < your_cards.size(); i++) // print out all the elements in the vector
    {
        cout << your_cards.at(i) << " " ;
    }

    cout << endl << "I have " << my_cards << " card(s)." << endl; // print the counter value

    if (my_cards > your_cards.size()) // if my cards is larger than the size of the vector
    {
        cout << "I win!" << endl;
    }
    else if (my_cards < your_cards.size()) // if the size of the vector is larger than the counter
    {
        cout << "You win!" << endl;
    }
    else // if they are equal
    {
        cout << "Tie!" << endl;
    }

    return 0;
}