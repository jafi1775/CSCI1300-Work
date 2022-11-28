// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 5, Question 3a

#include <iostream>
using namespace std;

/*  Algorithm for insert after function-
    1. Take in array of strings, number of elements in string, array size, the place where you want to put the string, and the string you want to put in the array as parameters for the function
    2. Declare a temporary variable to act as a counter of iterations for the for loop in the function]
    3. Have if statements checking if the array is full and if the place where the user wants to put a string is outside the size of the array
    4. If neither of those are true, check if the place where the user wants to put the string is before or in place of an element
    5. If it is, go into the for loop which iterates backwards through the array and creates an empty element spot open for the string 
    6. Once the space has been created for the string, place the string in the element
    7. Return true if the string was placed in the array

*/

bool insertAfter(string input_strings[], int num_elements, int arr_size, int index, string string_to_insert)
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

int main()
{
    // Because this function was so specific I used the examples from the github to check my code rather than make assert statements.
    // I also used coderunner to check my code and then used these examples one at a time to check if anything I did made a difference in my code

    // int size = 5;
    // string inputStrings[5] = {"pikachu", "meowth", "snorlax"};
    // int num_elements = 3;
    // int index = 2;
    // string string_to_insert = "clefairy";
    // // result contains the value returned by insertAfter
    // bool result = insertAfter(inputStrings, num_elements, size, index, string_to_insert);
    // // print result
    // cout << "Function returned value: "<< result << endl;
    // // print array contents
    // for(int i = 0; i < size; i++)
    // {
    //     cout << inputStrings[i] << endl;
    // }

    // int size = 5;
    // string input_strings[5] = {"caterpie", "eevee"};
    // int num_elements = 2;
    // int index = 0;
    // string string_to_insert = "bulbasaur";
    // // result contains the value returned by insertAfter
    // bool result = insertAfter(input_strings, num_elements, size, index, string_to_insert);
    // // print result
    // cout << "Function returned value: "<< result << endl;
    // // print array contents
    // for(int i = 0; i < size; i++)
    // {
    //     cout << input_strings[i] << endl;
    // }

    // int size = 2;
    // string input_strings[2] = {"pichu", "ponyta"};
    // int num_elements = 2;
    // int index = 1;
    // string string_to_insert = "charizard";
    // // result contains the value returned by insertAfter
    // bool result = insertAfter(input_strings, num_elements, size, index, string_to_insert);
    // // print result
    // cout << "Function returned value: "<< result << endl;
    // // print array contents
    // for(int i = 0; i < size; i++)
    // {
    //     cout << input_strings[i] << endl;
    // }

    return 0;
}