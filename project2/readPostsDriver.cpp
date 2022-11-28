// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 2, Part 1, Question 2


#include <iostream>
#include <fstream>
#include "Post.h"
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


/* Algorithm for readPosts function:
    1. Take in specified perameters.
    2. Define an input stream variable, a number of likes variable to use stoi function, a temporary variable to call split function, a temporary array for the split function, and a temporary string for the getline function.
    3. Open the input stream file.
    4. Check if the number of posts stored is equal to the array size, if it is then return -2.
    5. Check if the file opened/failed, if it failed then return -1.
    6. If the file opens, then enter a while loop that runs as long as there is information in the file and the number of posts stored in the array is less than the array size.
    7. In the while loop, call the getline function.
    8. If the line is empty, continue.
    9. Clear the temporary array.
    10. Call the split function to fill the temporary, and define the temporary variable as the split function.
    11. If the split returns any value but 4, then continue to next loop.
    12. Else, just continue to the rest of the code.
    13. Define variable num_likes as the temporary array at index 2 with the stoi conversion.
    14. Fill the post array for this loops iteration as all the information from the temporary array.
    15. Increase the number of posts stored by 1.
    16. Exit the while loop.
    17. Close the file.
    18. Return the number of posts stored.
*/
int readPosts(string file_name, Post posts[], int num_posts_stored, int posts_arr_size)
{
    ifstream file; // input stream
    int num_likes, x; // temporary variables
    string temp_arr[4], line; // temporary array for the split function, and temp variable for the getline function

    file.open(file_name); // open the file

    if (num_posts_stored == posts_arr_size) // if there is no more room in the array
    {
        return -2;
    }

    if(file.fail()) // if the file failed
    {
        return -1;
    }
    else
    {
        while((posts_arr_size > num_posts_stored) && !file.eof()) // while there is still information in the stream and there is room in the array.
        {
            getline(file, line); // get one line at a time out of the file

            if (line == "") // if the line is empty
            {
                continue;
            }

            temp_arr[0] = ""; // empty all variables from the temporary array
            temp_arr[1] = "";
            temp_arr[2] = "";
            temp_arr[3] = "";

            x = split(line, ',', temp_arr, 4); // call split function

            if(x != 4) // if the line doesn't have enough information in it 
            {
                continue;
            }

            num_likes = stoi(temp_arr[2]); // convert string to integar for number of likes

            Post new_post = Post(temp_arr[0], temp_arr[1], num_likes, temp_arr[3]); // define variable for specific element of array

            posts[num_posts_stored] = new_post; // fill the array
            

           num_posts_stored++; // increment by 1
        }
        file.close(); // close the file

        return num_posts_stored; // return the number of posts stored in the file
    }
}

int main()
{
    return 0;
}