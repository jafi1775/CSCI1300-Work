// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 4 - Problem 4

#include <iostream>
using namespace std;

int main()
{
    string DNA, dnaSequence;
    int occurences = 0;
    cout << "Enter the DNA Sequence:" << endl; // prompts the user for inout of a DNA sequence
    cin >> DNA;
    for(int i=0; i<DNA.length(); i++) // need to check if input has lowercase letters or letter besides A, C, G, T
    {
        if (DNA[i]!= 'A' && DNA[i]!= 'C' &&  DNA[i]!= 'G' && DNA[i]!= 'T') // checks for invalid input
        {
            cout << "This is not a valid DNA sequence." << endl;
            return 0;
        }
    
    }
    cout << "Enter the DNA fragment to be searched:" << endl; // prompts the user for a fragment to search for.
    cin >> dnaSequence; 
    for(int i=0; i<dnaSequence.length(); i++) // need to check if input has lowercase letters or letter besides A, C, G, T
    {
        if (dnaSequence[i]!= 'A' && dnaSequence[i]!= 'C' &&  dnaSequence[i]!= 'G' && dnaSequence[i]!= 'T')
        {
            cout << "This is not a valid DNA sequence" << endl;
            return 0;
        }
    
    }

    // number of occurences algorithm 
    for (int i=0;i<=(DNA.length()-dnaSequence.length()) + 1; i++ ) // checks if the substring of DNA is the same as the fragment.
    {
        if (DNA.substr(i,dnaSequence.length())== dnaSequence) // if there is a match
        {
            occurences++; // increments the occurrences by one, every time there is a match.
        }
    }

    cout << "Number of occurrences: " << occurences << endl; // prints out the number of occurrences
    return 0;
}