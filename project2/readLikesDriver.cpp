// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 2, Part 1, Question 5

#include "User.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include <sstream>
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



int readLikes(string file_name, User users[], int num_users_stored, int users_arr_size, int max_posts)
{
    int size = max_posts + 1; // for the size of the temperary array, max posts plus 1 for the username
    string line, temp_arr[size], username; // variables for the get line function, the temporary array for the split function, and the username.
    ifstream file; // input stream from file
    User temp_user; // temporary user to fill users array
    int num_posts, likes[max_posts]; // variable for return value of split function, and likes array.


    if (num_users_stored == users_arr_size) // if the number of users stored is equal to the users array size
    {
        return -2;
    }


    file.open(file_name); // open the file

    if (file.fail()) // if the file fails
    {
        return -1;
    }
    else 
    {
        while(!file.eof() && num_users_stored < users_arr_size) // read information from the file as long as there is information in the file and the number of users stored is smaller than the users array size
        {
            for(int i = 0; i < size; i++) // empty the temporary array
            {
                temp_arr[i] = "";
            }

            getline(file, line); // getline from the file

            if (line == "") // if the line is empty, skip the line
            {
                continue;
            }

            num_posts = split(line, ',', temp_arr, size); // call the split function on the line


            if (num_posts <= size) // if the number of posts is a valid amount
            {

                username = temp_arr[0]; // set the username to the first element of the first array


                for (int i = 0; i < max_posts; i++) // fill the likes array with integars 
                {
                    likes[i] = stoi(temp_arr[i+1]);
                }

                User temp_user(username, likes, num_posts - 1); // fill the temporary user variable with the information


                users[num_users_stored] = temp_user; // fill the users array 

                
                num_users_stored++; // increment number of users stored
            }
        }
    }

    file.close(); // close the file

    return num_users_stored; // return the number of users stored
} 

int main()
{
    return 0;
}