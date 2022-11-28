// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 3, Fluff Header File


#include <iostream>
using namespace std;

class Fluff
{
    private: 
        int column; // vertical orientation
        int row; // horizontal orientation
        bool found = false;
        string message;
    

    public:
        string getMessage();
        void setMessage(string message);
        int getColumn();
        void setColumn(int new_column);
        int getRow();
        void setRow(int new_row);
        bool getFound();
        void setFound(bool is_found);
};