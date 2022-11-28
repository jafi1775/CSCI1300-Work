// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 5, Question 6

#include <iostream>
#include <cassert>
using namespace std;

int zeroesToFives(int arr[], int arr_size)
{
	int count = 0;
	//loops through input array
	for(int i = 0; i < arr_size; i++) 
	{ 
		if(arr[i] == 0) //if an element is zero, set it to five
		{ 
    			arr[i] = 5;
			count++;
		}
	}
	return count;
}

int main()
{
    int array1[10]= {0, -1, 99, 300, 32, -90, 2, 10, 44, -1000}; // if the first value is 0
    assert(zeroesToFives(array1, 10) == 1); 
    int array2[0]; 
    assert(zeroesToFives(array2,0) == 0); // edge case
    int array3[3] = { 5, 5, 5};
    assert(zeroesToFives(array3,3) == 0); // if all values are already 5 
    int array4[1] = {0};
    assert(zeroesToFives(array4, 1) == 1); // if there is only one element and it is 0
    int array5[7] = {-1,-2,-3,-4,-5,-6,-7};
    assert(zeroesToFives(array5, 7) == 0); // if all the values are negative
    int array6[2] = {1,0};
    assert(zeroesToFives(array6, 2) == 1);
    int array7[5] = {5, 5, 5, 5, 5};
    assert(zeroesToFives(array7, 5) == 0);
    int array8[6];
    assert(zeroesToFives(array8, 6) == 6); // if the values of the array aren't explicitly defined
    int array9[10] = { 0, 1, 0 , 1, 0 , 1 , -1, -5, 0 , 0};
    assert(zeroesToFives(array9, 10) == 5);
    int array10[4] = {3, 0, 0, 5};
    assert(zeroesToFives(array10, 4)== 2); // if the array size isn't accurate (not sure if this counts)
    return 0;
}