// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 2, Part 1, Question 7


#include "User.h"

void findTagUser(string username_tag, User users[], int num_users_stored)
{
    int matches = 0; // keeps track of the number of usernames with the username tag in it
    string username, tag_search; // temporary variables for the for loops

    if (num_users_stored <= 0) // if the number of users stored is equal to or less than 0
    {
        cout << "No users are stored in the database" << endl;
        return;
    }

    for(int i = 0; i < num_users_stored; i++) // to iterate through the users array
    {
        username = users[i].getUsername(); // to get the username element of this iteration

        for(int j = 0; j <= username.length() - username_tag.length(); j++) // to iterate through the username 
        {
            tag_search = username.substr(j,username_tag.length()); // this iterations sub string to see if the tag is within the username


            if (tag_search == username_tag) // if the sub string is equal to the username tag
            {
                matches++; // increment matches by 1
                if(matches == 1) // if this is the first match, print the following statement first
                {
                    cout << "Here are all the usernames that contain " << username_tag << endl;
                }

                cout << username << endl; // print the username
            }

        }
    }

    if (matches == 0) // if there are no matches
    {
        cout << "No matching user found" << endl;
    }

    return; // return
}

int main()
{
    return 0;
}