// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 5, Question 4

#include <iostream>
#include <cassert>
using namespace std;

/*  Algorithm for split function-
    1. Take in original string, the chosen seperator, the array being filled, and the array size
    2. Declare a temporary variable to use to count the number of splits
    3. Check for valid input, if the string is empty return 0
    4. Use a for loop to iterate through each character of the string
    5. If the character isn't the seperator then add the character to the current element of the array
    6. If the character is the sperator then increment the temporary variable by 1, move to the next index in the array, and continue to the next iteration of the for loop
    7. Outside the for loop, check if the array had been filled to it's maximum size and there were leftover parts of the string, then return -1 with all that could be filled up into the array
    8. If there weren't extra parts of the string that were unable to be put into the array, then increment the temporary value by 1 and return the temp variable
*/
int split(string input_string, char seperator, string arr[], int arr_size)
{

    int temp = 0; // temporary variable to count how many splits happen

    if (input_string == "")  // if the string is empty
    {
        return temp;
    }
    else 
    {   
        int x = input_string.length();

        for(int i=0; i < x; i++) // iterating through the string
        {
            if(arr_size < temp + 1) // used this for readRatings.cpp
            {
                return -1;
            }
            else if (input_string[i] == seperator) // if the character is the defined deliminator
            {   
                temp++; // increment temporary variable by 1
                continue; // continue to next iteration
            }
            else // if the character is not the deliminator
            {
                arr[temp] += input_string[i]; // place character into array element until temp changes 
            }
            
        }
        if (arr_size < temp + 1) // if the number of split elements from the string become larger than the array size
        {
            temp = -1;
            return temp;
        }
        else 
        {
            temp ++; // returning the number of elements in the array. Because array indexing starts at 0, must add 1 for accurate number
            return temp;
        }

    }
}

int main() // test case from github
{
    string testcase = "ABCDEFG";
    char separator = ' ';
    int arr_size = 3;
    string arr[3];
   
    int num_splits = split(testcase, separator, arr, arr_size);

    assert(split(testcase, separator, arr, arr_size) == 1);

    string testcase2 = "Gone GOne Girl";
    char separator2 = ' ';
    int arr_size2 = 3;
    string arr2[3];

    assert(split(testcase2, separator2, arr2, arr_size2) == 3);

    string testcase3 = "123,456,789,10";
    char separator3 = ',';
    int arr_size3 = 2;
    string arr3[2];

    assert(split(testcase3, separator3, arr3, arr_size3) == -1);

    string testcase4 = "";
    char separator4 = ',';
    int arr_size4 = 4;
    string arr4[4];

    assert(split(testcase4, separator4, arr4, arr_size4) == 0);


    return 0;
}