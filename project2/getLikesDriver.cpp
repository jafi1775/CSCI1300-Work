// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 2, Part 1, Question 5

#include "User.h"
#include "Post.h"
#include <iostream>


int getLikes(string post_author, Post posts[], int num_posts_stored, string username, User users[], int num_users_stored)
{
    int value; // the return value for the function
    string author, user; // the temporary variables to holed the return values from the get functions

    if (num_users_stored <= 0 || num_posts_stored <= 0 ) // if the number of users or number of posts is 0 or less than 0
    {
        return -2;
    }

    for (int i = 0; i < num_posts_stored; i++) // to iterate through the posts array 
    {
        author = posts[i].getPostAuthor(); // finds the author for every post element

        if (author == post_author) // if the author of the post in this iteration is the author trying to be found
        {
            for (int j=0; j < num_users_stored; j++) // to iterate through the users array
            {
                user = users[j].getUsername(); // finds the username of the user for this iteration of j

                if (user == username) // if the user trying to be found is the same as this iterations username
                {
                    value = users[j].getLikesAt(i); // find the likes value trying to be found
                    return value; // return the likes
                }
            }
        }

    }
    return -3; // if the user or the post author cant be found
}

int main()
{
    return 0;
}