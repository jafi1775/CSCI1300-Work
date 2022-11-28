// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 5, Question 3b

#include <iostream>
#include <cassert>
using namespace std;

bool insertAfter(string input_strings[], int num_elements, int arr_size, int index, string string_to_insert) // function from 3a
{
    int it = 0; // it is a variable for the number of iterations through the for loop

    if (num_elements == arr_size) // to return false if the array is full
    {
        return false;
    }
    else if (index >= arr_size - 1) // to return false if the user is trying to go outside the scope of the array
    {
        return false;
    }
    else // if we are able to create a new array with a replacement string
    {   
        if (index+1 < num_elements) // if you want to put the replacement string before other strings
        {
            for (int i = num_elements - index; it <= num_elements - (index + 1); i--) // i is iterating backwords that way it replaces strings without using previous replacements 
            {
               input_strings[index + i] = input_strings[index + (i-1)]; // moves strings over one
               it++; // increases counter by 1
            }
            
        }
        input_strings[index + 1] = string_to_insert; // finally replaces string with new string
        return true;
    }
}

/*  Algorithm for secondPlace function-
    1. Take in array of string, the string to insert, the string to find, the number of elements, the array size, and the number of elements being added to the array as perameters to the function
    2. Check if the array would be able to take the additional elements being added, if not return the elements already present in the array.
    3. If the array has room for the additional elements, then enter a for loop that iterates through the array
    4. Once in the for loop check if the element in this iteration of the for loop is the string trying to be found
    5. If it is, call the function from 3a and increment the number of elements in the array
    6. If it isn't then continue to the next iteration
    7. Once out of the for loop, return the number of elements in the array
*/
int secondPlace(string input_strings[], string string_to_insert, string string_to_find, int num_elements, int arr_size, int count)
{
    if (arr_size < num_elements + count) // if the number of elements plus the number of elements being added exceeds the arrays size
    {
        return num_elements; // return orignal value
    }
    else
    {
        for (int i=0; i <= num_elements; i++) // iterate through array, as long as the number of elements is equal to or less than the number of iterations
        {
            if (input_strings[i] == string_to_find) // if the element is the string trying to be found
            {
                insertAfter(input_strings, num_elements, arr_size, i, string_to_insert); // call function from 3a
                num_elements++; // add to number of elements
            }
            else 
            {
                continue; // if the element is not the string tyring to be found, move to the next iteration
            }
        }
        
        return num_elements; //  return number of elements
    }
}

int main()
{   
    int size = 5;
    string input_strings[5] = {"clefairy", "meowth", "snorlax"};
    int num_elements = 3;
    int count = 1;
    string string_to_insert = "charizard";
    string string_to_find = "meowth";

    assert(secondPlace(input_strings, string_to_insert, string_to_find, num_elements, size, count) == 4);
   
    int size2 = 5;
    string inputStrings2[5] = {"caterpie", "meowth", "pichu", "caterpie", "caterpie"};
    int numElements2 = 5;
    string stringToInsert2 = "gyarados";
    string stringToFind2 = "caterpie";
    int count2 = 3;
    
    assert(secondPlace(inputStrings2, stringToInsert2, stringToFind2, numElements2, size, count2) == 5);

    int size3 = 9;
    string inputStrings3[9] ={"clefairy", "raichu", "raichu","raichu", "ponyta", "charizard"};
    int numElements3 = 6;
    string stringToInsert3 = "eevee";
    string stringToFind3 = "raichu";
    int count3 = 4;

    assert(secondPlace(inputStrings3, stringToInsert3, stringToFind3, numElements3, size3, count3) == 6);

    int size4 = 12;
    string inputStrings4[12] ={"charmeleon", "pichu", "pikachu","charmeleon", "charmeleon", "bulbasaur", "charmeleon"};
    int numElements4 = 7;
    string stringToInsert4 = "crobat";
    string stringToFind4 = "charmeleon";
    int count4 = 4;

    assert(secondPlace(inputStrings4, stringToInsert4, stringToFind4, numElements4, size4, count4) == 11);

    return 0;
}