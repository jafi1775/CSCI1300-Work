// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 2, Part 2, Question 0

#include <iostream> 
#include "Post.h"
#include "User.h"

using namespace std;

int split(string input_string, char seperator, string arr[], int arr_size);


class Buffchat
{
    private: 
        const static int posts_size = 50;
        const static int users_size = 50;
        Post posts[posts_size];
        User users[users_size];
        int num_posts;
        int num_users;

    public:
        Buffchat();
        int getPostSize();
        int getUserSize();
        int getNumPosts();
        int getNumUsers();
        int readPosts(string file_name);
        void printPostsByYear(string year);
        int readLikes(string file_name);
        int getLikes(string post_author, string username);
        void findTagUser(string username_tag);
        bool addPost(string post_body, string post_author, string date);
        void printPopularPosts(int count, string year);
        User findLeastActiveUser();
        int countUniqueLikes(string post_author);
};