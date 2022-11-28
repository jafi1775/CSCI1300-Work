// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 7, Problem 2

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;



/*  Algorithm for dnaRead function:
    1. Initialize the return string variable, and the boolean to check if the start codon has been found.
    2. Create a for loop that iterates through the vector.
    3. Iterate through each element of the vector to make sure the codons are of valid input (exactly 3 in length, capital letters, and either ACG or T).
    4. Check if the start codon has been found, if it has not check if the current element is the start codon; If it isn't continue to next iteration.
    5. Check if the current codon is the end codon, if it is return the return string.
    6. Then add the current element to the return string.
    7. Outside the for loop check if the start codon has been found. If the variable is false/ not found then return an empty string.
*/
string dnaRead(vector<string> vec)
{
    string return_string; // the return string
    bool start_found = false; // to see if the start has been found

    for (int i = 0; i < vec.size(); i++) // iterate through the vector given
    {
        
        string codon = vec.at(i); // assign the elements string to a variable

        for (int j = 0; j < 3; j++) // iterate through the letters of the element
        {
            int length = codon.length(); // assign the length of the element to a variable

            if (length != 3) // if the dna sequence is too long or short
            {
                return_string = "Invalid sequence.";
                return return_string;
            }

            string dna = codon.substr(j, 1); // each dna letter in the sequence

            if (dna != "A" && dna != "C" && dna != "G" && dna != "T") // if the letter is not valid input
            {
                return_string = "Invalid sequence.";
                return return_string;
            }

        }

        if(start_found == false) // if the start codon has not been found
        {
            if (vec.at(i) == "ATG") // checking if the current element is the start codon
            {
                start_found = true; // change the boolean to true
                continue; 
            }
            else 
            {
                continue; // continue to next iteration until start is found
            }
        }
    

        if (vec.at(i) == "TAA" || vec.at(i) == "TAG" || vec.at(i) == "TGA") // if the current element is the end codon
        {
            return return_string; 
            
        }

        return_string += vec.at(i); // add the current element into the string

    }

    if (start_found == false) // if the start codon was never found
    {
        return_string = "";
        return return_string;
    }
    return return_string;
}

int main()
{
    vector<string> dna1{"TCC", "ACG", "ATG", "ACC", "TGC", "TAG", "ACC"}; // if the first element isn't the start codon
    assert(dnaRead(dna1) == "ACCTCG");

    vector<string> dna2{"ATG", "TCA", "TAA"}; // only 1 codon to print
    assert(dnaRead(dna2) == "TCA");

    vector<string> dna3{"ATG", "CAT", "ACT", "GAC", "TAA", "ACT", "TAC"};
    assert(dnaRead(dna3) == "CATACTGAC");

    vector<string> dna4{"CAT", "ACT", "GAC", "TAA", "ACT", "TAC"}; // no start codon
    assert(dnaRead(dna4) == "");

    vector<string> dna5{"CAT", "AT", "GAC", "TAA", "ACT", "TAC"}; // no start codon and an invalid sequence
    assert(dnaRead(dna5) == "Invalid Sequence");

    return 0;
}