// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 1 - Problem 1 - isNoteValid

#include <iostream> 
#include <cassert>
using namespace std;

/* Algorithm for isValidNote
    1. Declare boolean variables to check string 
    2. Check if string is longer than 2 characters
    3. Check if note name is between A and G and is capital
    4. Check if octave is a number between 0 and 9
    5. Return true or false value
*/
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

int main()
{
    assert(isValidNote("C4") == true);
    assert(isValidNote("c4")== false);
    assert (isValidNote("lmk") == false);
    assert(isValidNote("Gp") == false);

    string note;
    cout << "Enter a note." << endl;
    cin >> note;
    cout << isValidNote(note) << endl;
    return 0;
}