// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 7, Problem 1

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/*  Algorithm for sumElements function:
    1. Initialize a variable for the sum of all numbers as 0.
    2. Check if the start index is larger than the end index, making it not valid input (return -1).
    3. Check if the start index or end index are less than/equal to zero or larger than the vector size, making them outside the scope of the vector (return -2).
    4. Else, iterate through the vector using a for loop and add each element to the sum variable.
    5. Return the sum.
*/

int sumElements(vector<int> vec, int start_index, int end_index)
{
    int sum = 0; // return value of function

    if(start_index > end_index) // if the inputs for the start index and end index are not valid
    {
        return -1;
    }   
    else if (start_index < 0 || start_index > vec.size() || end_index < 0 || end_index >= vec.size()) // if the start index or end index are out of the scope of the vector
    {
        return -2;
    }
    else 
    {
        for (int i = start_index ; i <= end_index; i++) // iterate through the vector
        {
            sum += vec.at(i); // add together each value in the vector
        }
    }

    return sum; // return the sum of all elements

}




int main ()
{

    vector<int> vect1{10, 20, 30, 40, 50};
    int start_index = 1, end_index = 3;
    assert(sumElements(vect1, start_index, end_index) == 90); // if the values are valid

    vector<int> vect2{1, 2, 3, 4, 5, 6, 7, 8, 9};
    start_index = 5, end_index = 3;
    assert(sumElements(vect2, start_index, end_index) == -1); // if start index is larger than end index

    vector<int> vect3{2, 4, 6, 8, 10, 12, 14, 16, 18};
    start_index = 3, end_index = 15;
    assert(sumElements(vect3, start_index, end_index) == -2); // if one of the indexes is out of the scope of the vector



    return 0;
}