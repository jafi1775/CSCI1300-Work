// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 2, Part 1, Question 4


#include <iostream>
using namespace std;

class User
{
    private:
    string username;
    static const int size = 50; // ?
    int likes[size];
    int num_posts;
    

    public:
    User();
    User(string input_username, int input_likes[], int input_num_posts);
    string getUsername();
    void setUsername(string input_username);
    int getLikesAt(int post_id);
    bool setLikesAt(int post_id, int num_likes);
    int getNumPosts();
    void setNumPosts(int input_posts);
    int getSize();

};