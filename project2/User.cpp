// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 2, Part 1, Question 4

#include "User.h"

User :: User() // default constructor
{
    username = "";
    
    for (int i = 0; i < size; i++)
    {
        likes[i] = -1;
    }

    num_posts = 0;

}

User :: User(string input_username, int input_likes[], int input_num_posts) // constructor with perameters
{
    username = input_username;
    num_posts = input_num_posts;

    for(int i=0; i < size; i++)
    {
        likes[i] = -1;
    }
    for(int j=0; j < num_posts; j++)
    {
        likes[j] = input_likes[j];
    }

}

string User :: getUsername() // returns the username
{
    return username;
}

void User :: setUsername(string input_username) // sets the username 
{
    username = input_username;
}

int User :: getLikesAt(int post_id) // reutrns the likes at a certain index
{
    int x = likes[post_id];

    if (post_id >= size || post_id < 0)
    {
        return -2;
    }
    else
    {
        return x;
    }
}

bool User :: setLikesAt(int post_id, int num_likes) // set the likes at a certain index
{
    if (post_id < num_posts && post_id >= 0 && num_likes >= -1 && num_likes <= 10)
    {
        likes[post_id] = num_likes; 
        return true;
    }
    else 
    {
        return false;
    }
}

int User :: getNumPosts() // retunrs the number of posts 
{
    return num_posts;
}

void User :: setNumPosts(int input_posts) // sets the number of posts 
{
    if(input_posts <= size && input_posts >= 0)
    {
        num_posts = input_posts;
    }
}

int User :: getSize() // returns the size of the likes array
{
    return size;
}
