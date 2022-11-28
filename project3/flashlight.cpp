// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 3, Flashlight Implementation


#include <iostream>
#include "flashlight.h"
using namespace std;


int Flashlight :: getFrontSpaceRow()
{
    return front_space[0];

}

int Flashlight :: getFrontSpaceColumn()
{
    return front_space[1];
}


int Flashlight :: getLeftSpaceRow()
{
    return left_space[0];
}

int Flashlight :: getLeftSpaceColumn()
{
    return left_space[1];
}

int Flashlight :: getRightSpaceRow()
{
    return right_space[0];
}

int Flashlight :: getRightSpaceColumn()
{
    return right_space[1];
}

int Flashlight :: getBackSpaceRow()
{
    return back_space[0];
}

int Flashlight :: getBackSpaceColumn()
{
    return back_space[1];
}

int Flashlight :: getFRspaceRow()
{
    return front_right_space[0];
}

int Flashlight :: getFRspaceColumn()
{
    return front_right_space[1];
}

int Flashlight :: getFLspacRow()
{
    return front_left_space[0];
}

int Flashlight :: getFLspaceColumn()
{
    return front_left_space[1];
}

int Flashlight :: getBRspaceRow()
{
    return back_right_space[0];
}

int Flashlight :: getBRspaceColumn()
{
    return back_right_space[1];
}

int Flashlight :: getBLspaceRow()
{
    return back_left_space[0];
}

int Flashlight :: getBLspaceColumn()
{
    return back_left_space[1];
}



void Flashlight :: setSpaces(int row, int column)
{
    front_space[0] = row + 1;
    front_space[1] = column; 

    back_space[0] = row - 1;
    back_space[1] = column;

    right_space[0] = row;
    right_space[1] = column + 1;

    left_space[0] = row;
    left_space[1] = column - 1;

    front_right_space[0] = row + 1;
    front_right_space[1] = column + 1;

    front_left_space[0] = row + 1;
    front_left_space[1] = column - 1;

    back_right_space[0] = row - 1;
    back_right_space[1] = column + 1;

    back_left_space[0] = row - 1;
    back_left_space[1] = column - 1;
    
}
