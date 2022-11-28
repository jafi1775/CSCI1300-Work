// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 3, Fluff Implementation


#include <iostream>
#include "story_build.h"
using namespace std;


string Fluff :: getMessage()
{
    return message;
}

void Fluff :: setMessage(string new_message)
{
    message = new_message;
}


int Fluff :: getColumn()
{
    return column; 
}

void Fluff :: setColumn(int new_column)
{
    column = new_column;
}

int Fluff :: getRow()
{
    return row;
}

void Fluff :: setRow(int new_row)
{
    row = new_row;
}

bool Fluff :: getFound()
{
    return found;
}

void Fluff :: setFound(bool is_found)
{
    found = is_found;
}