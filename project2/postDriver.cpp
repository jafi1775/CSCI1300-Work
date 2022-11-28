#include <iostream>
#include "Post.h"
using namespace std;

Post :: Post() // sets all parts of Post class to 0 or empty
{
    body_ = "";
    post_author_ = "";
    date_ = "";
    num_likes_ = 0;
}

Post :: Post(string input_body, string input_author, int input_likes, string input_date) // parameterized class call
{
    body_ = input_body;
    post_author_ = input_author;
    num_likes_ = input_likes;
    date_ = input_date;
}

string Post :: getPostBody() // returns body of post
{
    return body_;
}

void Post :: setPostBody(string input_body) // sets body of post
{
    body_ = input_body;
}

string Post :: getPostAuthor() // returns author of post
{
    return post_author_;
}

void Post :: setPostAuthor(string input_author) // sets post author
{
    post_author_ = input_author;
}

int Post :: getPostLikes() // returns the number of likes for a post
{
    return num_likes_;
}

void Post :: setPostLikes(int likes) // sets likes if the likes number is greater than or equal to 0
{
    if (likes >= 0)
    {
        num_likes_ = likes;
    }
}

string Post :: getPostDate() // returns date of post
{
    return date_;
}

void Post :: setPostDate(string input_date) // sets date of post
{
    date_ = input_date;
}





int main()
{
    return 0;
}