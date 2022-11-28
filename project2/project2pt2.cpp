// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 2, Part 2, Question 10

#include <iostream>
#include <string>
#include <fstream>
#include "Buffchat.h"
#include "split.cpp"

using namespace std;


// functions from part one for menu options 1-5
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

int readLikes(string file_name, User users[], int num_users_stored, int users_arr_size, int max_posts)
{
    int size = max_posts + 1;
    string line, temp_arr[size], username;
    ifstream file;
    User temp_user;
    int num_posts, likes[max_posts];


    if (num_users_stored == users_arr_size)
    {
        return -2;
    }


    file.open(file_name);

    if (file.fail())
    {
        return -1;
    }
    else 
    {
        while(!file.eof() && num_users_stored < users_arr_size)
        {
            for(int i = 0; i < size; i++)
            {
                temp_arr[i] = "";
            }

            getline(file, line);

            if (line == "")
            {
                continue;
            }

            num_posts = split(line, ',', temp_arr, size);


            if (num_posts <= size)
            {

                username = temp_arr[0];


                for (int i = 0; i < num_posts - 1 ; i++)
                {
                    likes[i] = stoi(temp_arr[i+1]);
                }

                User temp_user(username, likes, num_posts - 1);


                users[num_users_stored] = temp_user;

                
                num_users_stored++;
            }
        }
    }

    file.close();

    return num_users_stored;
} 

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

    return; // return nothing
}



int main()
{
    int input = 3, value; // variable for menu input and return value of any functions
    int num_posts_stored = 0, posts_arr_size = 50, num_users_stored = 0, users_arr_size = 50; // general variables called for functions
    User users[users_arr_size]; // users array for function calls
    string year, author, username, tag; // input variables for year, post author, username, and username tags
    string file, file2;
    Post posts[posts_arr_size];

    Buffchat new_buff, new_buff2, new_buff3, new_buff4;
    string body_new, author_new, date_new; // for case 6 and 9
    int num_posts2; // for case 7
    string pop_year;
    User least_active; // for case 8
    bool value_bool; // for case 6


    while (input != 10) // while they did not exit the menu
    {
        do
        {
            if (input < 1 || input > 10) // if the input is invalid
            {
                cout << "Invalid input" << endl;
            }
            cout << "======Main Menu=====" << endl;
            cout << "1. Read posts" << endl;
            cout << "2. Print Posts By Year" << endl;
            cout << "3. Read Likes" << endl;
            cout << "4. Get Likes" << endl;
            cout << "5. Find users with matching tag" << endl;
            cout << "6. Add a new post" << endl;
            cout << "7. Print popular posts for a year" << endl;
            cout << "8. Find least active user" << endl;
            cout << "9. Find unique likes for a post author" << endl;
            cout << "10. Quit" << endl;
            cin >> input;

        } while (input < 1 && input > 10); // keep running until valid input is selected


        switch (input)
        {
            case 1: // if the user selects the read posts option
                cout << "Enter a post file name:" << endl;
                cin >> file;
                value = readPosts(file, posts, num_posts_stored, posts_arr_size); // call the read posts function
                if (value == -1) // if the file doesn't open
                {
                    cout << "File failed to open. No posts saved to the database." << endl;
                }
                if (value == -2) // if the num_posts_stored is equal to posts_arr_size
                {
                    cout << "Database is already full. No posts were added." << endl;
                }
                if (value == posts_arr_size) // if the function returns equal to the array size
                {
                    cout << "Database is full. Some posts may have not been added." << endl;
                    num_posts_stored = value;

                }
                if (value < posts_arr_size && value >= 0) // if the function has a valid output with valid 
                {
                    cout << "Total posts in the database: " << value << endl;
                    num_posts_stored = value;
                }

            break;

            case 2: // if the user wants to print posts by year
                cout << "Enter the year(YY):" << endl;
                cin >> year; // takes input from user for selected year
                printPostsByYear(posts, year, num_posts_stored); // call print posts by year function

            
            break;


            case 3: // if the user wants to read likes from a file
                cout << "Enter a user file name:" << endl; 
                cin >> file2;

                value = readLikes(file2, users, num_users_stored, users_arr_size, users_arr_size); // call read likes function

                if (value == -1) // if the file cannot open
                {
                    cout << "File failed to open. No users saved to the database." << endl;
                }
                if (value == -2) // if the array is already full
                {
                    cout << "Database is already full. No users were added." << endl;
                }
                if (value == users_arr_size) // if the return value of the function is equal to the array size 
                {
                    cout << "Database is full. Some users may have not been added." << endl;
                    num_users_stored = value;
                }
                if (value < users_arr_size && value >= 0) // if the return value is smaller than users array size and if the return value is equal or greater than 0
                {
                    cout << "Total users in the database: " << value << endl;   
                    num_users_stored = value;
                }


            break;


            case 4: // if the user wantas to call get likes
                cout << "Enter a post author: " << endl; 
                cin >> author;
                cout << "Enter a user name: " << endl;
                cin >> username;

                value = getLikes(author, posts, num_posts_stored, username, users, num_users_stored); // call the get likes function

                if (value == 0) // if the user has not liked the found post
                {
                    cout << username << " has not liked the post posted by " << author << endl;
                }
                else if (value == -1) // if the user has not viewed the found post
                {
                    cout << username << " has not viewed the post posted by " << author << endl;
                }
                else if (value == -2) // if the database is empty
                {
                    cout << "Database is empty." << endl;
                }
                else if (value == -3) // if the user or author of the post doesn't exist
                {
                    cout << username << " or " << author << " does not exist." << endl;
                }
                else // if the user has liked the authors post
                {
                    cout << username << " liked the post posted by " << author <<  " " << value << " times" << endl;
                }


            break;

            case 5: // if the user wants to find the usernames with the declared tag
                cout << "Enter a tag:" << endl;
                cin >> tag; // takes input for tag
                findTagUser(tag, users, num_users_stored); // calls find Tag User function

            break;

            case 6:
                cout << "Enter a post body:" << endl; // prompt user for the posts body, author and date to add
                cin >> body_new;
                cout << "Enter a post author:" << endl;
                cin >> author_new;
                cout << "Enter a date(mm/dd/yy):" << endl;
                cin >> date_new;

                new_buff.readPosts(file); // to fill the posts array in the buffchat object

                value_bool = new_buff.addPost(body_new, author_new, date_new); // to return if the post had been added successfully

                if(value_bool == true) // if the post had been added successfully
                {
                    cout << author_new << "'s post added successfully" << endl;
                }

                else if (value_bool == false) // if the post had not been added successfully
                {
                    cout << "Database is already full. " << author_new << "'s post was not added" << endl;
                }


            break;


            case 7:

                cout << "Enter the number of posts:" << endl; // prompt the user for the number of posts and the year for the print popular posts member function
                cin >> num_posts2;
                cout << "Enter the year(YY):" << endl;
                cin >> pop_year;

                new_buff2.readPosts(file); // populate the posts array with the previously specified file

                new_buff2.printPopularPosts(num_posts2, pop_year); // print populer posts will print out the posts and correct statements

            break;


            case 8:

                new_buff3.readLikes(file2); // populate the users array 

                least_active = new_buff3.findLeastActiveUser(); // call least active user function
                
                if(new_buff3.getUserSize() == 0) // if the user size is 0, then there were no users stored
                {
                    cout << "There are no users stored" << endl;
                }

                else if (least_active.getUsername() == "") // if the user is empty 
                {
                    cout << "There are no users stored" << endl;
                }
                else 
                {
                    cout << least_active.getUsername() << " is the least active user" << endl; // otherwise print the username of the least active user
                }

            break;


            case 9:

                cout << "Enter a post author:" << endl; // prompt the user for the author of the post to be searched for
                cin >> author_new;
                
                new_buff4.readPosts(file); // populate the posts array
                new_buff4.readLikes(file2); // populate the users array

                value = new_buff4.countUniqueLikes(author_new); // call the unique likes member function

                if (value == 0) // if the post had received 0 likes
                {
                    cout << "The posts posted by " << author_new << " have received 0 likes so far." << endl;
                }
                else if (value == -1) // if the post had not been viewed by anyone
                {
                    cout << "The posts posted by " << author_new << " have not been viewed by anyone." << endl;
                }
                else if (value == -2) // if there is nothing in the posts array or the users array
                {
                    cout << "Database is empty." << endl;
                }
                else // to print out the number of likes the post recieved
                {
                    cout << "The posts posted by " << author_new << " have been liked by " << value << " unique users." << endl;
                }



            break;


            case 10: // if the user wants to exit the program
                cout << "Good bye!" << endl;
            break;


        }


    }

    return 0; 
}
