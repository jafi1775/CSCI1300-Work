// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 2, Part 1, Question 1


#include <iostream>
using namespace std;

class Post 
{
    private :
    string body_;
    string post_author_;
    int num_likes_;
    string date_;

    public:
    Post();
    Post(string input_body, string input_author, int input_likes, string input_date);
    string getPostBody();
    void setPostBody(string post_body);
    string getPostAuthor();
    void setPostAuthor(string input_author);
    int getPostLikes();
    void setPostLikes(int likes);
    string getPostDate();
    void setPostDate(string input_date);

};