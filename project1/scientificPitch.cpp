// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 1 - Problem 7 - putting it all together!

#include <iostream>
#include <iomanip>
using namespace std;

bool isValidNote(string note) // function from question 1
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

bool isValidTune(string tune) // function from question 2
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

int numValidNotes(string tune) // function from question 3
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

double tuneSimilarity (string tune1, string tune2) // function from question 4
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

double bestSimilarity(string input_tune, string target_tune) // function from question 5
{  
    double best_Similarity; // declare return value variable
    
    if (input_tune.length() < target_tune.length()) // check if lengths of strings are valid
    {
        best_Similarity = 0; // if they are invalid lengths, return value as 0
    }
    else 
    {
        for( int i=0; i <= input_tune.length() - target_tune.length(); i+=2) // to iterate through each possible substring
        {
            tuneSimilarity(input_tune.substr(i,target_tune.length()), target_tune); // calling function from question 4
            
            if (i==0) // to put the first iterations similarity into the best_Similarity value, that way there is a value to compare to for the next iterations
            {
                best_Similarity = tuneSimilarity(input_tune.substr(i,target_tune.length()), target_tune);
            }

            if (best_Similarity < tuneSimilarity(input_tune.substr(i,target_tune.length()), target_tune) && tuneSimilarity(input_tune.substr(i,target_tune.length()), target_tune) != 0) // to compare the similarity values, and make the greatest value the best_Similarity value. The second condition is to ensure 0  cannot be the greatest value
            {
                best_Similarity = tuneSimilarity(input_tune.substr(i,target_tune.length()), target_tune);
            }
            
        }
    }


    return best_Similarity; // the return value 
}

void printTuneRankings(string tune1, string tune2, string tune3, string target_Tune) // function from question 6
{
    double sim1 = bestSimilarity(tune1, target_Tune); // initializing each variable for the tunes bestSimilarity score
    double sim2 = bestSimilarity(tune2, target_Tune);
    double sim3 = bestSimilarity(tune3, target_Tune);

    if (sim1 == sim2 && sim2 == sim3) // what to print if all the scores are the same
    {
        cout << "1) Tune 1, 2) Tune 2, 3) Tune 3" << endl;
    }
    else if (sim1 > sim2 && sim1 > sim3) // if tune1 has the largest similarity score
    {
        if (sim2 > sim3) // what to print if tune2 has a larger score than tune3 
        {
            cout << "1) Tune 1, 2) Tune 2, 3) Tune 3" << endl;
        }
        else if (sim3 > sim2) // what to print if tune3 has a larger similarity score 
        {
            cout << "1) Tune 1, 2) Tune 3, 3) Tune 2" << endl;
        }
        else // what to print if tune2 and tune3 have the same similarity score 
        {
            cout << "1) Tune 1, 2) Tune 2, 3) Tune 3" << endl;
        }
    }
    else if (sim2 > sim1 && sim2 > sim3) // if tune2 has the largest similarity score
    {
        if (sim1 > sim3) // what to print if tune1 has a larger score than tune3
        {
            cout << "1) Tune 2, 2) Tune 1, 3) Tune 3" << endl;
        }
        else if (sim3 > sim1) // what to print if tune3 has a larger score than tune1
        {
            cout << "1) Tune 2, 2) Tune 3, 3) Tune 1" << endl;
        }
        else // what to print if tune1 and tune3 have the same score
        {
            cout << "1) Tune 2, 2) Tune 1, 3) Tune 3" << endl;
        }
    }
    else if (sim3 > sim1 && sim3 > sim2) // if tune3 has the largest similarity score
    {
        if (sim1 > sim2) // what to print if tune1 has a larger score than tune2 
        {
            cout << "1) Tune 3, 2) Tune 1, 3) Tune 2" << endl;
        }
        else if (sim2 > sim1) // what to print if tune2 has a larger score than tune1
        {
            cout << "1) Tune 3, 2) Tune 2, 3) Tune 1" << endl;
        }
        else // if tune1 and tune2 have the same score
        {
            cout << "1) Tune 3, 2) Tune 1, 3) Tune 2" << endl;
        }
    }
    else // if 2 tunes are tied for largest similarity score
    {
        if (sim1 == sim2) // if tune1 and tune2 tied for largest score
        {
            cout << "1) Tune 1, 2) Tune 2, 3) Tune 3" << endl;
        }
        else if (sim1 == sim3) // if tune1 and tune3 tied for largest score
        {
            cout << "1) Tune 1, 2) Tune 3, 3) Tune 2" << endl;
        }
        else if (sim2 == sim3) // if tune2 and tune3 tied for largest score
        {
            cout << "1) Tune 2, 2) Tune 3, 3) Tune 1" << endl;
        }
    }
    return; // return nothing
}


int main()
{
    int menu_selection = 1; // variable for the input for selecting from the menu. Set to 1 for it doesn't enter the if statement.
    string tune1, tune2, tune3, target_tune; // variables for string inputs

    while (menu_selection != 4) // runs through the menu until the menu selection is 4 (exit)
    {
        do // runs until there is a valid menu selection
        {   
            if (menu_selection < 1 || menu_selection > 4)
            {
            cout << "Invalid Input." << endl;
            }
            cout << "--- Menu ---" << endl;
            cout << "1. Calculate similarity between two tunes." << endl;
            cout << "2. Calculate best similarity between two tunes of potentially different lengths."  << endl;
            cout << "3. Print three input tunes in order from most to least similar to the target tune." << endl;
            cout << "4. Exit." << endl;
            cout << "Please enter your choice (1 - 4):" << endl;
            cin >> menu_selection;
        } while (menu_selection < 1 && menu_selection > 4);

    
        switch (menu_selection) 
        {
            case 1: // for the first selection
                cout << "Please enter the first tune:" << endl;
                cin >> tune1;
                isValidTune(tune1); 
                while (isValidTune(tune1) == false) // checking if first tune is in valid SPN
                {
                    cout << "Invalid Input. Please enter a tune in valid SPN:" << endl;
                    cin >> tune1;
                }
                cout << "Please enter the second tune:" << endl;
                cin >> tune2;
                isValidTune(tune2); 
                while (isValidTune(tune2) == false) // checking if the second tune is in valid SPN
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> tune2;
                }
                cout << fixed << setprecision(2); // sets precision to 2
                cout << "The similarity score is " << tuneSimilarity(tune1, tune2) <<  endl; // prints out similarity score by calling a function
            
            break;

            case 2: // for the second selection
                cout << "Please enter the input tune:" << endl;
                cin >> tune1;
                isValidTune(tune1); 
                while (isValidTune(tune1) == false) // checking if first tune is in valid SPN
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> tune1;
                }
                cout << "Please enter the target tune:" << endl;
                cin >> target_tune;
                isValidTune(target_tune);
                while (isValidTune(target_tune) == false) // checking if target tune is in valid SPN
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> target_tune;
                }
                cout << fixed << setprecision(2); // sets precision to 2
                cout << "The best similarity score is: " << bestSimilarity(tune1, target_tune) << endl; // prints best similarity by calling function

            break;

            case 3: // for the third selection
                cout << "Please enter the first tune:" << endl;
                cin >> tune1;
                while (isValidTune(tune1) == false) // checks if first tune i svalid
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> tune1;
                }
                cout << "Please enter the second tune:" << endl;
                cin >> tune2;
                while (isValidTune(tune2) == false) // checks if second tune is valid
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> tune2;
                }
                cout << "Please enter the third tune:" << endl;
                cin >> tune3;
                while (isValidTune(tune3) == false) // checks if third tune is valid
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> tune3;
                }
                cout << "Please enter the target tune:" << endl;
                cin >> target_tune;
                while (isValidTune(target_tune) == false) // checks if target tune is valid
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> target_tune;
                }
                printTuneRankings(tune1, tune2, tune3, target_tune); // prints tune rankings by calling a function

            break;

            case 4: cout << "Goodbye!" << endl; break; // to exit the menu
        }

    }

    return 0;
}
