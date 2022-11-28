// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 6, Question 3

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
            if (input_string[i] == seperator) // if the character is the defined deliminator
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


/*  Algorithm for readPosts function-
    1. Declare input stream variable, line variable for while loop, array for split function, and return integar variable.
    2. Open file.
    3. Check if file opened with fail function in an if statement.
    4. If it failed, return -1.
    5. If it didn't fail, enter else statement.
    6. Create while loop to go through file contents until stream is empty.
    7. Withing while loop, use getline function to get one post/line at a time.
    8. After getline function, use the string variable holding the line to call the split function in an if statement.
    9. If the split function returns a value of 3, meaning all components of a post are present, then increase counter.
    10. Return counter variable once out of while loop. 
*/
int readPosts(string filename)
{
    ifstream post; // stream variable 
    string line, postArr[200]; // line variable to hold each line from getline function. And array for split function
    int num_posts = 0; // counter variable


    post.open(filename); // Open file

    if (post.fail()) // if file fails to open, then return -1
    {
        return -1;
    }
    else // if file opens successfully
    {
        while (!post.eof()) // while there is still stuff in the stream
        {
            getline(post, line); // get one line of the file at a time, or one post at a time

            if (split(line, ',', postArr, 200) == 3) // if there are 3 elements to the line, seperated by the comma delimiter, then the post is valid
            {
                num_posts++; // increase post counter by 1
            }

        }
    }

    return num_posts; // return number of posts counted
}


int main()
{   
    string filename = "posts.txt";

    assert(readPosts(filename) == 4);
    assert(readPosts("text_file_doesn't_exist.txt") == -1);
    assert(readPosts("posts_2.txt") == 3);
    assert(readPosts("posts_3.txt") == 3);

    return 0;
}