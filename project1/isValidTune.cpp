// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 1 - Problem 2 - isTuneValid

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
    1. Declare bool variables and string variables
    2. Create if statement to filter out any odd inputs (all inputs should be even)
    3. If the statement is even, then go into a for loop to check the notes within the tune
    4. Within the for loop call the isValidNote(string note) function to check each substring iteration of the for loop
    5. If all notes in the tune are valid, then return a true boolean value, if not return a fasle bool value
*/
bool isValidTune(string tune)
{
    bool valid_tune; // return bool variable
    
    if (tune == "") // if the string is empty then return false
    {
        valid_tune = false;
    }

    else if (tune.length() % 2 != 0) // if the string is odd return false, because the string should be even for each note has 2 characters
    {
        valid_tune = false;
    }

    else // for all valid inputs
    {
        for (int i=0; i<= (tune.length() - 2); i += 2) // the conditional checks every pairing, and not the pairings inbetween.
        {
            isValidNote(tune.substr(i,2)); // call for function from question 1
            valid_tune = true; // unless the string contains a note that is not valid, then this is the default
            if (isValidNote(tune.substr(i,2)) == true) // if the note is valid
            {
                continue;
            }
            else // if the note isn't valid
            {
                valid_tune = false;
                break;
            }

        }
    }

    return valid_tune; // return value 
}




int main()
{
    string tune;
    assert(isValidTune("A2B4C7") == true); // test cases for this function
    assert(isValidTune("M5D2E1")== false); 
    assert(isValidTune("A5D2E11") == false);
    assert(isValidTune("Hello1300") == false);
    assert(isValidTune("B1E3F7L1") == false);
    cout << "enter tune" << endl; // to test myself with any string
    cin >> tune; 
    isValidTune(tune);
    cout<< isValidTune(tune) << endl;
    return 0;
}