// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 3, Items Header File


#include <iostream>
using namespace std;

class Items
{
    private:
        string item_name;
        int column; // vertical orientation
        int row; // horizontal orientation
        bool item_found;

    public:
        Items();
        Items(string name, int comlumn, int row, bool found);
        string getName();
        void setName(string name);
        int getColumn();
        void setColumn(int new_column);
        int getRow();
        void setRow(int new_row);
        bool getFound();
        void setFound(bool is_found);
};
