
// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 2, Part 2, Question 0

#include <iostream>
#include <fstream>
#include <string>
#include "Buffchat.h"
using namespace std;


Buffchat :: Buffchat() // defualt constructor 
{
    num_posts = 0;
    num_users = 0;
}

int Buffchat :: getPostSize() // returns the size of the posts array
{
    return posts_size;
}

int Buffchat :: getUserSize() // returns the size of the users array
{
    return users_size;
}

int Buffchat :: getNumPosts() // returns the size of the variable num_posts
{
    return num_posts;
}

int Buffchat :: getNumUsers() // returns the number of users variable
{
    return num_users;
}


/* Algorithm for readposts function:
    1. Define an input stream variable, an integar for the number of likes in a posy and the return value of the split function. Also define a string array, and string variable to hold the line from the getline function.
    2. Open the file given.
    3. Check if there is room for the array to be filled, if there isn't return -2.
    4. Check if the file fails, if it does return -1.
    5. If the file doesn't enter either if statment then continue throuhg code.
    6. Create a while loop that runs while there is still info to read from the file and that the posts arraqy size is larger than the number of posts.
    7. In the while loop, call the getline function on file. 
    7. If the line for this iterations getline is empty, skip to next iteration.
    8. Clear the temperary array used for the split function.
    9. Call the split function and set it equal to a variable.
    10. If the split function doesn't return 4 (the correct amount of information to be split), then continue to next line.
    11. Then convert the number of likes from a string to an integar.
    12. Fill a temperary Post variable with the information found.
    13. Add temporary post varibale to post array at the index of the number of posts in the array.
    14. Increase the number of posts variable by one after post is added.
    15. Outside of while loop, close the file and return the number of posts.
*/
int Buffchat :: readPosts(string file_name)
{
    ifstream file; // input stream
    int num_likes, x; // temporary variables
    string temp_arr[4], line; // temporary array for the split function, and temp variable for the getline function


    file.open(file_name); // open the file

    if (num_posts == posts_size) // if there is no more room in the array
    {
        return -2;
    }

    if(file.fail()) // if the file failed
    {
        return -1;
    }
    else
    {
        while((posts_size > num_posts) && !file.eof()) // while there is still information in the stream and there is room in the array.
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

            posts[num_posts] = new_post; // fill the array
            

           num_posts++; // increment by 1
        }
        file.close(); // close the file

        return num_posts; // return the number of posts stored in the file
    }
}



/*  Algorithm for print posts by year function:
    1. Initialize variables for a counter, and temporary variables for the date of the post and the year of the post.
    2. Check if the number of posts is less than or equal to 0, if it is then print out statement saying there are no posts stored.
    3. Else, enter a for loop to iterate through the elements of the posts array.
    4. In the for loop, call the get post date function on this iterations element index, and find the substring corresponding to the year of the date string.
    5. If the year of this iterations post matches the year called in the perameters of the function, then enter if statement.
    6. If the number of matches is found, then print out the opening statement.
    7. Then, print out the body of the post with the matching year.
    8. Then increment the counter of matches variable by 1.
    9. After the for loop, if the counter variable is still 0, then print out that there were no posts stored for that year.
*/
void Buffchat :: printPostsByYear(string year)
{
    int matches=0; // for the number of posts with the year being searched for
    string date, year_of_post; // for finding the date of the post


    if (num_posts <= 0) // if there are no posts stored, then print thi statement
    {
        cout << "No posts are stored" << endl;
    }
    else
    {
        for(int i=0; i < num_posts; i++) // iterate through specified number of elements in posts array
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
    return;
}


/*  Algorithm for read likes function:
    1. Initialize variables for the max posts (50), the size of a temporary array made from the split function, stringg variable for the getline function, a string array for the split function, and a temporary string variable for the username.
    2. Also initialize variables for an input stream, a temporary user variable, a variable for the return value of the split function, and a likes array for the temporary user variable.
    3. Check if the number of users in the array is the same as the size, if so return -2.
    4. Open the file given.
    5. Check if the file failed, if it did return -2.
    6. Create a while loop that runs as long as there is information in the file and while the number of users in the array is less than the size of the array.
    7. Within the while loop, clear the temporary array from the spli function.
    8. Call the getline function.
    9. If the line from the getline function is empty, skip to the next iteration of the while loop.
    10. Call the split function.
    11. If the return value of the split is less than or equal to the size of the temporary array (51), then enter if statement
    12. Set the username variable to the first element of the temporary array.
    13. Convert the rest of the elements to integars.
    14. Declare the temporary user variable as the information just found.
    15. Fill the users array with the temporary user variable at the number of users index.
    16. Increase the number of users by one after adding a user to the array.
    17. Outside of the while loop, close the file and return the number of users now in the array.
*/
int Buffchat :: readLikes(string file_name)
{
    const static int max_posts = 50;
    int size = max_posts + 1; // for the size of the temperary array, max posts plus 1 for the username
    string line, temp_arr[size], username; // variables for the get line function, the temporary array for the split function, and the username.
    ifstream file; // input stream from file
    User temp_user; // temporary user to fill users array
    int num_posts, likes[max_posts]; // variable for return value of split function, and likes array.


    if (num_users == users_size) // if the number of users stored is equal to the users array size
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
        while(!file.eof() && num_users < users_size) // read information from the file as long as there is information in the file and the number of users stored is smaller than the users array size
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


                for (int i = 0; i < num_posts - 1; i++) // fill the likes array with integars 
                {
                    likes[i] = stoi(temp_arr[i+1]);
                }

                User temp_user(username, likes, num_posts - 1); // fill the temporary user variable with the information


                users[num_users] = temp_user; // fill the users array 

                
                num_users++; // increment number of users stored
            }
        }
    }

    file.close(); // close the file

    return num_users; // return the number of users stored
} 


/*  Algorithm for the get likes function-
    1. Define variables for the return value of the function, and temporary variables for the author and user.
    2. Check if the number of users and number of posts in the array is less than or equal to 0, if either is then return -2.
    3. If it isn't enter a for loop that iterates through the posts array.
    4. In the for loop, set the variable author to the getPostAuthor functions return value for the element of the iterations index.
    5. If the author of this iteration is the same as the author being searched for enter another for loop that iterates through the users array.
    6. Call the getUsername function on the inner for loops iteration index.
    7. If the user from the inner for loops iteration is the same as the username being searched for, set the return value of the function to the get likes at functions return value with the i and j of the for loops.
    8. If nothing is found, return -3.
*/
int Buffchat :: getLikes(string post_author, string username)
{
    int value; // the return value for the function
    string author, user; // the temporary variables to holed the return values from the get functions

    if (num_users <= 0 || num_posts <= 0 ) // if the number of users or number of posts is 0 or less than 0
    {
        return -2;
    }

    for (int i = 0; i < num_posts; i++) // to iterate through the posts array 
    {
        author = posts[i].getPostAuthor(); // finds the author for every post element

        if (author == post_author) // if the author of the post in this iteration is the author trying to be found
        {
            for (int j=0; j < num_users; j++) // to iterate through the users array
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


/*  Algorithm for find tag user function:
    1. Initialize variables for a counter of matches, and temporary variables for the tag and username.
    2. Check if the number of users in the users array is less than or equal to 0, if it is print out that there are no users stored in the database and return.
    3. Create a for loop that iterates through the users array.
    4. Define the username variable as the return value of the get Username function for the iterations index. 
    5. Then, create a for loop that iterates through the username to check for the tag.
    6. Define the tag_search variable as the substring for this iteration.
    7. If the tag_search variable matches that of the tag that is being searched for, then enter if statement.
    8. Increment the matches variable by 1
    9. If the matches variable is at 1, then print out opening statement.
    10. Then print out the username with the matching tag.
    11. Once outside the for loops, if the matches varibale is still at 0, print out that there were no matches.
*/
void Buffchat ::findTagUser(string username_tag)
{
    int matches = 0; // keeps track of the number of usernames with the username tag in it
    string username, tag_search; // temporary variables for the for loops

    if (num_users <= 0) // if the number of users stored is equal to or less than 0
    {
        cout << "No users are stored in the database" << endl;
        return;
    }

    for(int i = 0; i < num_users; i++) // to iterate through the users array
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

/*  Algorithm for add post function:
    1. Check if the number of posts is equal to the posts size, if it is return false.
    2. Else, use set functions to set the body, author, likes, and date to the posts array.
    3. Also set values of likes and num posts for users array.
    4. Then increment num posts by 1 and return true.
*/
bool Buffchat :: addPost(string post_body, string post_author, string date)
{
    if(num_posts == posts_size) // if there is no more room in the array
    {
        return false; // post wasn't added
    }
    
    else 
    {
        posts[num_posts].setPostBody(post_body); // set all the values for the post
        posts[num_posts].setPostAuthor(post_author);
        posts[num_posts].setPostLikes(0);
        posts[num_posts].setPostDate(date);

        users[num_posts].setLikesAt(num_posts, -1); // set values for user
        users[num_posts].setNumPosts(num_posts + 1);

        num_posts++; // increment number of posts after a post is added

        return true; // post was added
    }

}


/*  Algorithm for print popular posts function:
    1. Declare variables for a posts array, and a counter for number of posts found.
    2. Check if the number of posts in the array is less than or equal to 0, if it is than print out that no posts are stored and return out of function.
    3. Create a for loop that iterates through the posts array
    4. In the loop, initalize a stirng variable that will hold the date of the post in the loop
    5. If the year from the date of the post matches the year being searched for, then enter an if statement
    6. In the if statement, place this post found into a Posts array and increment posts found by 1.
    7. Once out of the for loop, if the number of posts found remains 0, then print out that no posts were stored for the year being searched for.
    8. Then, if the number of posts found with the year being searched for is less than the amount wanting to be printed, then print out all the posts to the screen.
    9. Create a while loop that runs as long as the number of posts found is less than the count of posts being searched for.
    10. In the while loop, declare a variable that will be the smallest amount of likes for a post, and a variable that will be the index of the post with the smallest amount of likes.
    11. Then, enter a for loop that will iterate through the temporary array of posts with the specified year.
    12. In the for loop use the get likes at function to find the likes of the post at the i index of the array.
    13. Then, if the likes at the specified iteration is less than the current amount stored in the variable, enter the for loop
    14. In the for loop, set the variables for the smallest amount of likes and the index for the smallest amount of likes to the values of the current post.
    15. After that for loop, enter another for loop that will once again iterate through the temporary array to remove (or write over) the post with the least amount of likes.
    16. Then, within that for loop, decrease posts found by 1.
    17. At the end, print the remaining posts to the screen.
*/
void Buffchat :: printPopularPosts(int count, string year)
{
    Post posts_year[posts_size]; // temporary array to hold posts with matching year

    int posts_found = 0; // counter for the number of posts found

    if (num_posts < 0) // if there are no posts to look through
    {
        cout << "No posts are stored" << endl;
        return;
    }

    for(int i = 0; i < num_posts; i++) // iterates through the post array
    {
        string input_year = posts[i].getPostDate(); // to find the date of the iterations post

        if (year == input_year.substr(6,2)) // if the year of this post matches the year trying to be found
        {
            posts_year[posts_found].setPostBody(posts[i].getPostBody()); // add the post found to a temporary array of all the posts with the same year
            posts_year[posts_found].setPostAuthor(posts[i].getPostAuthor());
            posts_year[posts_found].setPostLikes(posts[i].getPostLikes());
            posts_year[posts_found].setPostDate(posts[i].getPostDate());

            posts_found++; // increment number of posts with the year being searched for
        }
    }   


    if (posts_found == 0) // if there were no posts with the year being searched for
    {
        cout << "No posts stored for year " << year << endl;
        return; // exit out of function
    }

    if(posts_found < count) // if the number of posts found is less than the number of posts wanting to be returned
    {
        cout << "There are fewer than " << count << " posts for year " << year << ". Top " << posts_found << " posts for year " << year << endl;

        for (int i = 0; i < posts_found; i++) // print out all posts with the year being searched for
        {
            cout << posts_year[i].getPostLikes() << " likes: " << posts_year[i].getPostBody() << endl;
        }

        return; // exit out of function

    }

    while(posts_found > count) // while the number of posts found is larger than the number of posts wanting to be printed
    {
        int smallest_likes = 10000, smallest_index; // temporary variables

        for(int i = 0; i < posts_found; i++) // to iterate through the temporary array that holds the posts found
        {
            if (posts_year[i].getPostLikes() < smallest_likes) // if the likes value is smaller than the current smallest likes value
            {
                smallest_likes = posts_year[i].getPostLikes(); //set the new number of smallest likes
                smallest_index = i; // save this index
            }
        }

        for(int j = smallest_index; j < posts_found - 1; j++) // after the smallest likes value is found
        {
            posts_year[j] = posts_year[j+1]; // move posts over that post so it is removed from the array
        }

        
        posts_found --; // decrease the number of posts found/the number of posts in the temporary array
    }

    cout << "Top " << count << " posts for year " << year << endl; 

    for(int i = 0; i < count; i++) // to iterate through the temporary array
    {
        cout << posts_year[i].getPostLikes() << " likes: " << posts_year[i].getPostBody() << endl; // print out the essential parts of every remaing post
    }

    return; // exit function


}


/*  Algorithm for find least active user:
    1. Declare variables that will act as counters, holders of values, ect.
    2. Create a for loop that will iterate through the users array
    3. Then within that foor loop have a for loop that will iterate through each users likes array
    4. Everytime a -1 is found within the likes array, increment unseen posts variable by 1.
    5. Outside the inner for loop, check if this iterations unseen posts value is greater than the current max.
    6. If the current unseen posts value is grater than the current max, than save the index of the least active user and the new maximum value.
    7. Then check if the user at this iteration is empty, if it is increment a counter variable.
    8. Outside the outer for loop, check if the whole array is empty with the counter for the number of empty users.
    9. If the whole array is empty, than return an empty User.
    10. Otherwise, return the least active user at the saved index.
*/
User Buffchat :: findLeastActiveUser()
{
    int max = 0, least_active_index = 0, empty = 0; // temporary variables



    for (int i = 0; i < num_users; i++) //iterate through the users array
    {
        int unseen_posts = 0; 
        for (int j = 0; j < 50 ; j++) // iterate through the likes of the user 
        {
            if (users[i].getLikesAt(j) == -1) // if they didn't view a post, increment unseen posts by 1
            {
                unseen_posts++;
            }
        }
        
        if(unseen_posts > max) // if this users amount of unseen posts is larger than the current value
        {
            least_active_index = i; // save the index of the least active user
            max = unseen_posts; // set the number of unseen posts to the new max
        }

        if(users[i].getUsername() == "") // if the username is empty, then increment number of empty users by 1
        {
            empty++;
        }

    }
    
    if (empty == 50) // if the whole users array is empty
    {
        User empty_user;
        return empty_user; // return an empty user
    }

    return users[least_active_index]; // return the user at the least active index

}


/*  Algorithm for count Unique Likes:
    1. Declare a boolean variable that will check if the post has been viewed, and a variable that will count the number of likes.
    2. If the number of posts and number of users are both 0, return -2.
    3. Enter a for loop that will iterate through the posts array.
    4. If the author of the current post in the for loop matches that of the post author specifed enter another for loop that will iterate through the users array.
    5. In the inner for loop, check if the likes value for the specified post is above or equal to 0.
    6. If it is equal to or above 0, check if it is above 0 (if it has been liked).
    7. If the post has been liked by this user, increment the likes by 1.
    8. Then set the boolean variable to true, to show that the post has been viewed by at least one person regardless of likes.
    9. Outside these loops, if the boolean vaiable is still false, then return -1.
    10. Otherwise, return the number of unique likes by returning the likes counter variable.
*/
int Buffchat :: countUniqueLikes(string post_author)
{
    bool post_viewed = false; // variable to check if the post has been viewed 
    int likes = 0; // variable to increment for number of likes

    if(num_posts == 0 && num_users == 0) // if the number of posts and number of users are both 0.
    {
        return -2;
    }

    for (int i = 0; i < num_posts; i++) // to iterate through the posts array
    {
        if (posts[i].getPostAuthor() == post_author) // if the author within is the same as the one at the current post
        {
            for (int j = 0; j < num_users; j++) // iterate through the users array
            {
                if (users[j].getLikesAt(i) >= 0) // if the post has been seen by the current user
                {
                    if(users[j].getLikesAt(i) > 0) // if the post has been liked
                    { 
                        likes++; // increment likes by 1
                    }

                    post_viewed = true; // the post has been viewed by at least 1 user

                }  
            }
        }
    }

    if (post_viewed == false) // if the post was never viewed
    {
        return -1; 
    }

    return likes; // return the number of likes on the post

}