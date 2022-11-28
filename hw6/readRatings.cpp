// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 6, Question 4a

#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

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
            if(arr_size < temp + 1)
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

/*  Algorithm for readRestaurantData function-
    1. Take in defined parameters.
    2. Within function, declare variables for the input stream, the number of restaurants, a string to hold each getline, and a temporary array
    3. Open the file.
    4. Check if the file is open.
    5. If it isn't, return -1.
    6. If it is open, then run the following code.
    7. Create a while loop that runs as long as there is information in the input stream.
    8. Call getline to get one line at a time from the file.
    9. Clear the values previously in the temporary array.
    10. Use the split function on the iterations line, and populate a temporary array.
    11. Check to see if the array trying to be filled is too small, if it is then break the code.
    12. If the split returns -1, then continue to the next iteration of the while loop.
    13. If the split returns 4, the expected return value, then continue running the program and populate the arrays.
    14. Make the element of restaurant name array at the iterations num_line value set to the first element of the temperary array.
    15. Then populate the 2d array with the following 3 elements in the temporary array by usin gthe stoi function to make them integars.
    16. Then increment number of lines by 1 after every loop.
    17. Outside of the while loop, close the file.
    18. Return the num lines variable.
*/
int readRestaurantData(string filename, string restaurant[], int ratings[][3], int arrSize)
{
    ifstream res; // input stream variable
    int num_lines = 0; // variable for the number of restaurants 
    string line, temp_arr[4]; // line variable for the get line function, and the temperary array for each get line

    res.open(filename); // open the file

    if (res.fail()) // check if the file opened
    {
        return -1;
    }
    else
    {
        while(!res.eof()) // while there is information to read in the file
        {
            getline(res, line); // get each line one at a time 

            temp_arr[0] = ""; // reset each array element 
            temp_arr[1] = "";
            temp_arr[2] = "";
            temp_arr[3] = "";

            int x = split(line, '~', temp_arr, 4); // call the split function

            if(num_lines == arrSize) // if the array is too small, break the code that way it doesn't have a segmentation error
            {
                break;
            }

            if (x == -1) // if the split returns -1, skip to the next iteration
            {
                continue;
            }
            else if (x == 4) // if the split function has a valid reutrn value, run the code
            {

                restaurant[num_lines] = temp_arr[0]; // populate the resturaunt name arrays with the first element from the temporary array 

                string temp = temp_arr[3]; // use a temporary variale for the third rating number

                temp = temp[0]; // only take the number from string, the second character will be a new line character

                ratings[num_lines][0] = stoi(temp_arr[1]); // populate the 2d array with the first rating number 

                ratings[num_lines][1] = stoi(temp_arr[2]); // populate the 2d array with the second rating number 

                ratings[num_lines][2] = stoi(temp); // populate the 2d array with the third rating number 

                num_lines++; // increment the number of lines by 1
            }
        }
        res.close(); // close the file
    }

    return num_lines; // return the number of restaurants
}

int main()
{
    string filename = "restaurant_samples.txt";
    string restaurant[3];
    int ratings[3][3];
    int arrSize = 3;
    
    assert(readRestaurantData(filename, restaurant, ratings, arrSize) == 3);
    assert(readRestaurantData("file_doesn't_exist.txt", restaurant, ratings, arrSize) == -1);

    assert(readRestaurantData("res_sample2.txt", restaurant, ratings, arrSize) == 2);

    string restaurant2[7];
    int ratings2[7][3];
    int arrSize2 = 7;
    
    assert(readRestaurantData("res_sample3.txt", restaurant2, ratings2, arrSize2) == 5);


    return 0;
}