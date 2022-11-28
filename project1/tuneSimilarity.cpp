// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 1 - Problem 4 - tuneSimilarity

#include <iostream> 
#include <cassert>
using namespace std;

/* Algorithm-
    1. Declare similarity variable, as well as the variables for matching notes, matching notes and pitches, different notes, and total notes.
    2. Make if statement to check if lengths of strings are equal.
    3. Create a for loop within a for loop to check each note of the tune in each position
    4. Create for loop to iterate through the string to create values for the variables matching notes, different notes and pitches, and matching notes and pitches.
    5. 
     
*/
double tuneSimilarity (string tune1, string tune2)
{
    
    double similarity; // variable for similarity calculation
    double m_notes=0, m_notes_pitch=0, dif=0, total=0; // variables for the other parts of the similarity calculation

    if (tune1.length() != tune2.length()) // to check if the length of the strings are equal
    {
        similarity = 0;
    }
    else
    {
        for (int i=0; i< tune1.length(); i += 2) // to iterate through the string
        {
            if (tune1.substr(i,2) == tune2.substr(i,2)) // to check for notes with matching pitches and names
            {
                m_notes_pitch++; // to increment when a match is found
            }
            if (tune1.substr(i,1) == tune2.substr(i,1)) // to check for notes with matching names but not pitches
            {
                m_notes++; // to increment when a match is found
            }
            if (tune1.substr(i,1) != tune2.substr(i,1) && tune1.substr(i+1,1) != tune2.substr(i+1,1)) // to check if the notes are different note names and pitches
            {
                dif++; // to increment when a match is found
            }
        }
        total = tune1.length()/2; // for total number of notes 

        similarity = (m_notes / total) + m_notes_pitch - dif; // calculation of similarity between tunes
    }
    return similarity; // return value of similarity
}

int main ()
{
    string tune1, tune2;
    cout<< "enter tune 1" << endl; // to check myself with any input
    cin >> tune1;
    cout << "enter tune 2" << endl;
    cin >> tune2;
    tuneSimilarity(tune1, tune2);
    
    cout << tuneSimilarity(tune1, tune2) << endl;
    // assert(tuneSimilarity("G4E5D4", "G4F4D5") == 0.666667);
    // assert(tuneSimilarity("A0B0C0D0", "D1C1B1A1") == -4);
    // assert(tuneSimilarity("E5E5G5A6G5D5", "E5G5A6G5D5D5")== .333333);
    // assert(tuneSimilarity("D5G2", "F7D1E4G4")==0);
    return 0;
}