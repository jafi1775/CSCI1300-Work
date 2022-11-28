// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 3, Ghost Header File


#include <iostream>
using namespace std;

class Flashlight
{

    private:
        int front_space[2];
        int left_space[2];
        int right_space[2];
        int back_space[2];
        int front_right_space[2];
        int front_left_space[2];
        int back_right_space[2];
        int back_left_space[2];

    public:
        
        int getFrontSpaceRow();
        int getFrontSpaceColumn();

        int getLeftSpaceRow();
        int getLeftSpaceColumn();
        
        int getRightSpaceRow();
        int getRightSpaceColumn();

        int getBackSpaceRow();
        int getBackSpaceColumn();

        int getFRspaceRow();
        int getFRspaceColumn();

        int getFLspacRow();
        int getFLspaceColumn();

        int getBRspaceRow();
        int getBRspaceColumn();

        int getBLspaceRow();
        int getBLspaceColumn();

        void setSpaces(int row, int column);

        


};