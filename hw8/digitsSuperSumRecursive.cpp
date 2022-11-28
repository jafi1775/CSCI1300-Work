// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 8

#include <iostream> 
#include <cassert>
using namespace std;

/*  Algorithm for digitsSuperSumRecursive function-
    1. Take in an integar for the parameters.
    2. Check if the integar is already one digit, if it is return the input.
    3. If the input isn't one digit then add together each digit of the input number, continuously do this until there is one digit left.
    4. Do this by using modulo and divison to find the sum of each digit.
*/
int digitsSuperSumRecursive(int n)
{

    if (n < 10) // checks if the input is already less than ten 
    {
        return n; // if so return the input
    }
    else // if the value is multiple digits
    {
        return digitsSuperSumRecursive((n % 10) + (n / 10)); // continuously adds each digit of the input number together until there is one digit
    }

}

int main()
{
    int N;
    cin >> N;
    cout << digitsSuperSumRecursive(N);

    assert(digitsSuperSumRecursive(1234) == 1); 
    assert(digitsSuperSumRecursive(6) == 6); // if it's only one digit long
    assert(digitsSuperSumRecursive(90) == 9); // if one of the digits is 0
    assert(digitsSuperSumRecursive(999) == 9);
    
}