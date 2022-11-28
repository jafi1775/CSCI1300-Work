// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 2, Part 1, Question 3

#include <iostream>
#include <fstream>
#include "Post.h"
using namespace std;

/*  Algorithm for printPostsByYear-
    1. Take in specified perameters.
    2. Define variable int matches, string date, and string year_of_posts.
    3. Check if num_posts_stored is less than or equal to 0, if it is print that no posts are stored.
    4. Elsem enter a for loop that iterates through each post element of the post array.
    5. In the for loop, define date as the post element at this iterations index, with the getter for the date of the post.
    6. Then, define year_of_post as a substring of year that only takes the year of the string.
    7. Check if the year of the post is the same as the year being searched for.
    8. If it is, check if this is the first match of year to be found, if it is print out the preliminary statement to the list.
    9. Else, print out this iterations post body with the getter for the post body.
    10. Then, increment the number of matched by 1 in the if statement.
    11. After the for loop, if their were no matches then print out that there were no posts stored for that year.
    12. Return nothing.
*/
void printPostsByYear(Post posts[], string year, int num_posts_stored)
{
    int matches=0; // for the number of posts with the year being searched for
    string date, year_of_post; // for finding the date of the post


    if (num_posts_stored <= 0) // if there are no posts stored, then print thi statement
    {
        cout << "No posts are stored" << endl;
    }
    else
    {
        for(int i=0; i < num_posts_stored; i++) // iterate through specified number of elements in posts array
        {
            date = posts[i].getPostDate(); // get the date from the post
            year_of_post = date.substr(6,2); // get the year from the string using the substring function.

            if (year_of_post == year) // if the year of the post matches the year being seacrhed for
            {
                if (matches == 0) // if this is the first match, print following statement
                {
                    cout << "Here is a list of posts for year " << year << endl;
                }
                cout << posts[i].getPostBody() << endl; // print the body of the post with matching year
                matches++; // increment matches by 1
            }
        }
        if (matches == 0) // if there were no matches, then print this statement
        {
            cout << "No posts stored for year " << year << endl;
        }
    }

    return; // return nothing
}

int main()
{
    return 0;
}