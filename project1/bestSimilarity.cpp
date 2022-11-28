// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 1 - Problem 5 - bestSimilarity

#include <iostream>
#include <cassert>
using namespace std;

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

/*  Algorithm-
    1. Declare return variable and other variables necessary for loops.
    2. Create an if statement to check if target tune is longer than input tune.
    3. In an else statement, create a for loop to iterate through the strings.
    4. Within the for loop, add an if statement for the first iteration of i, so that the variable best_similarity has a value to compare to in the next if statement.
    5. In another if statement, compare the current best_similarity to the newest iterations similarity value (in the conditions add a condition that ensures best similarity cannot equal 0 unless the lengths of the strings are invalid).
    6. At the end of the function, return the best_Similarity value.
*/

double bestSimilarity(string input_tune, string target_tune)
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



int main()
{
    string input_tune, target_tune;
    cout<< "enter input tune" << endl;
    cin >> input_tune;
    cout << "enter target tune" << endl;
    cin >> target_tune;
    cout << bestSimilarity(input_tune,target_tune) << endl;
    // assert((bestSimilarity("E4D5B7G2E2", "D6G5G2") == 0.666667)); //error popping up when I use the doubles_equal() function. So I used assert statment without this.
    return 0;
}