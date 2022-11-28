// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 6, Question 1

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

/*
    Counts the number of given characters
    found in the given input string. 
*/
int countCharacters(string input, char c)
{
    int count = 0;
    int input_len = input.length(); // store length of string in variable
    // loop through the string to check every character
    for (int i = 0; i < input_len; i++)
    {
        if (input[i] == c) // add one to total count if it matches desired character
            count += 1;
    }

    return count;
}

/*
    Takes a given file name and reads the contents. 
    Counts the occurences of letter on each line.
    Prints the line number and the number of occurences for each line.
    At the end, prints the total number of occurences.
    Returns true if the total number of occurences was greater than 20.

*/
bool readFile(string file_name, char letter)
{
    bool result = false;  // final result to return at end
    int total_count = 0;  // counts total occurrences of letter
    int line_count = 0;   // count of occurrences of letter for a single line

    string line;    // variable for storing each line as we read it
    ifstream fin;   // file input stream

    fin.open(file_name); // Open input file
    
    if (fin.fail())
    {
        cout << "File couldn't be opened!" << endl;
        result = false;
    }
    else
    {
        // read every line of file, count number of characters on each line
        int line_number = 0;
        while (!fin.eof()) // continue looping as long as there is data to be processed in the file
        {
            line_number += 1;
            getline(fin, line);

            line_count = countCharacters(line, letter);
            total_count += line_count;

            cout << "Line: " << line_number << ", Occurences: " << line_count << endl;
        } 
    
        // print the total count to user
        cout << "Total occurences: " << total_count << endl;

        // update result of function -- is true if total count greater than 20
        result = total_count > 20;

        // close files
        fin.close();
    }

    return result;
}

int main()
{
    // write at least 6 additional test cases to test countCharacters()

    // write at least 6 additional test cases to test readFile()


    assert(countCharacters("Test Case!", '!') ==  1);
    assert(countCharacters("", 'a') ==  0);
    assert(countCharacters("09483728551", '5') ==  2);
    assert(countCharacters(" Hello Class ", ' ') ==  3);
    assert(countCharacters("TtTtTTt", 'T') ==  4);
    assert(countCharacters("HHHHHHHH", 'l') ==  0);


    string fileName = "shakespeare_sonnet.txt";

    assert(readFile("shakespeare_sonnet.txt", 'e') == true);
    assert(readFile("shakespeare_sonnet", 'a') == false);
    assert(readFile(fileName, 'T') == false);
    assert(readFile(fileName, '0') == false);
    assert(readFile("testcase.txt", 'a') == false);
    assert(readFile("testcase2.txt", 'a') == true);

    return 0;
}