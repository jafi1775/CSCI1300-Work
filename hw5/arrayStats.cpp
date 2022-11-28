// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 5, Question 2

#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

/* Algorithm for min function-
    1. Take in an array and size of the array for perameters
    2. Create a variable for the minimum value in the array 
    3. Iterate through the array, and find the smallest value by comparing new element value to previous min value
    4. Return the minimum value variable once done iterating through the array
*/
double min(double arr[], int num) // function for calculating the minimum value in an array
{
    double min = arr[0]; // initializes the minimum value as the first value in the array

    for (int i = 0; i < num; i++) // for loop iterating through the array
    {
        if (arr[i] < min) // if the value within the array of this iteration is smaller than the value currently in min
        {
            min = arr[i]; // replace the value
        }
        else 
        {
            continue;
        }
    }

    return min;
}

/* Algorithm for sum function
    1. Take in array and size of array in perameters of function
    2. Create variable which will represent the total (the return value)
    3. Iterate through the array, and in each iteration add the value to the total variable
    4. Once done iterating, return the total value
*/
double sum(double arr[], int num) // function for sum of array values
{
    double total = 0;
    for (int i=0; i<num; i++) // iterate through the array
    {
        total += arr[i]; // total equals total plus the value of this iterations array element
    }
    return total;
}

/*  Algorithm for average function
    1. Take in an array and array size for perameters of function
    2. Declare variable that will equal the sum of the values from the array, set this equal to the sum function
    3. Declare average variable that is equal to the sum variable divided by the array size
    4. Return the average variable
*/
double average(double arr[], int num) // function for the average of array values
{
    double total = sum(arr, num); // call the function for the sum of array values
    double average = total / num; // average of values is the sum divided by the number of elements in the array
    return average;
}

int main() // to check if my values come out correct with whatever I define the array and array size as
{
    double arr[6] = {9.5,6.6,-2.0,-10,30,30.1};
    int arr_size = 6;
    cout << "Min: " << fixed << setprecision(3) << min(arr, arr_size) << endl;
    cout << "Sum: " << fixed << setprecision(3) << sum(arr, arr_size) << endl;
    cout << "Avg: " << fixed << setprecision(3) << average(arr, arr_size) << endl;
    double array[3] = {0.0, 1.0, 2.2};
    assert(min(array, 3)==0.000);
    double array2[5] = { 5, 4 , 3, 2 ,1};
    assert(min(array2,5)== 1.000);
    double array3[6] = { 9.5, 6.6, -2.0, -10, 30, 30.1};
    assert(min(array3, 6)== -10.000);
    double array4[2] = {0,0};
    assert(min(array4, 2)==0.000);

    assert(sum(array, 3)==3.200);
    assert(sum(array2,5)== 15.000);
    assert(sum(array3, 6)== 64.200);
    assert(sum(array4, 2)== 0.000);

    //assert(average(array, 3)==1.067);
    assert(average(array2,5)== 3.000);
    // assert(average(array3, 6) == 10.700);
    assert(average(array4,2)== 0.000);

    return 0;
}