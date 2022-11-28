// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 1 - Problem 3 - numValidNotes

#include <iostream> 
#include <cassert>
using namespace std;

bool isValidNote(string note)
{
    bool real_note_name, real_octave; // creating boolean variables to check first character and second character 
   
    if (note.length()>2) // checking if input is larger than 2
    {
        return false;
    }
    else
    {
        // this if and else statement checks if the note has a valid note name
        if (note[0]<65 || note[0]>71 )
        {
            real_note_name = false;
        }
        else 
        {
            real_note_name = true;
        }
        // if (octave < 48 && octave > 57) // can you compare a strings ASCII value if it's a single character in a string
        // {

        // }
        // this if and else statement checks if the octave is a valid number
        if (note[1]<48 || note[1] > 57 )
        {
            real_octave = false;
        }
        else 
        {
            real_octave = true;
        }
        //this if and else staement determines the value of the return bool value, and if the original note input is valid.
        if (real_octave && real_note_name) 
        {
        return true;
        }
        else
        {
            return false;
        }
    }
}


/* Algorithm-
    1. Declare int counter variable for number of valid notes in string
    2. Create for loop that goes through all possible substring notes within tune string
    3. Within the for loop, call function from question 1 for a substring of the tune string
    4. Create an if statment for if a valid note is found, within the if statment increase the counter variable by 1
    5. Create an else staement for if no valid note is found in this iteration of the for loop that coninues to the next iteration.
    6. Return the counter variable to see the number of valid notes within the string.
*/
int numValidNotes(string tune)
{
    int x = 0; // counter variable for number of valid notes
    
    for (int i=0; i<= tune.length(); i++) // to iterate through every substring with a possible valid note within the string
    {

        isValidNote(tune.substr(i,2)); // call for function from question 1

        if (isValidNote(tune.substr(i,2)) == true ) // if there is a valid note found
        {
            x++; // increase counter by one
        }
        else // if there is no valid note found
        {
            continue;
        }
    }

    return x; // return value of number of valid notes found within string
}

int main()
{
    string tune;
    assert(numValidNotes("Hello There!") == 0); // a few test cases
    assert(numValidNotes("C4B7E2") == 3); 
    assert(numValidNotes("CC4") == 1); 


    cout << "enter tune" << endl; // to test myself with any string
    cin >> tune; 
    numValidNotes(tune);
    cout<< numValidNotes(tune) << endl;
    return 0;
}