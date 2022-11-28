// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 3, Items Implementation


#include <iostream>
#include "Items.h"
using namespace std;


Items :: Items()
{     
    column = 0; // vertical orientation
    row = 0; // horizontal orientation
    item_found = false;
}

Items :: Items(string name, int column_input, int row_input, bool found_input)
{
    item_name = name;
    column = column_input; // vertical orientation
    row = row_input; // horizontal orientation
    item_found = found_input;
}

string Items :: getName()
{
    return item_name;
}

void Items :: setName(string name)
{
    item_name = name;
}

int Items :: getColumn()
{
    return column; 
}

void Items :: setColumn(int new_column)
{
    column = new_column;
}

int Items :: getRow()
{
    return row;
}

void Items :: setRow(int new_row)
{
    row = new_row;
}

bool Items :: getFound()
{
    return item_found;
}

void Items :: setFound(bool is_found)
{
    item_found = is_found;
}