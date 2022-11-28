// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 1 - Problem 6 - printTuneRankings

#include <iostream>
#include <cassert>
using namespace std;

double tuneSimilarity(string tune1, string tune2)
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


/*  Algorithm- 
    1. Initialize variables for each tunes bestSimilarity score. 
    2. Create a series of if statements to print out the list of tunes in their rankings.
    3. Return nothing.
*/

void printTuneRankings(string tune1, string tune2, string tune3, string target_Tune)
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
    // are there assert statments for void functions?
    return 0;
}
