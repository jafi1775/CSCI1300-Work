// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 5, Question 5

#include <iostream>
#include <cassert>
using namespace std;

/*  Algorithm for full class function-
    1. Take in a 2d array, number of rows, and number of students on the waitlist as parameters for the function
    2. Check if the array has a valid amount of rows, if the number of rows is 0, then print the original amount of sutdents on the waitlist 
    3. If the number of arrays is larger than 0, then enter a for loop that iterates through the 2d array
    4. There will be an outer for loop that iterates through the rows of the array, and an inner for loop that iterates through the columns
    5. Once in the inner for loop, check if the element in the current iterations column is a 0 and if the waitlist has already reached 0
    6. If the element is a 0 and the waitlist still has students in it, then enter the if statement.
    7. In the if statement, replace the 0 with a 1 and subtract 1 from the waitlist value. Then print out the element.
    8. If the element isn't a 0 or the waitlist has reached 0, then print out the current value in the array and continue to the next iteration
    9. Once out of the inner for loop for a column, print a return character to go to the next row.
    10. Once out of the outer for loop, print out the remaining students on the waitlist.
    11. Then return the waitlist value.

*/
int fullClass(bool classroom[][4], int rows, int waitlist)
{
    if (rows == 0) // if there is no array, print the original waitlist amount
    {
        cout<< "Remaining Students: " << waitlist << endl;
    }
    else
    {
        for(int i = 0; i< rows; i++) // iterate through the rows of the array
        {

            for(int j=0; j< 4; j++) // iterate through the columns of the array
            {
                if (classroom[i][j] == 0 && waitlist > 0) // if the element is equal to 0 and there are still students on the waitlist
                {
                    classroom[i][j] = 1; // change the element to 1
                    cout << classroom[i][j]; // print the element
                    waitlist--; // remove a student from the waitlist
                }
                else // if the element already has a student in it, or if the waitlist has been emptied
                {
                    cout << classroom[i][j]; // print the element as is
                    continue;
                }
            }
            cout << endl; // create a new line once done iterating through the columns of the row
        }
        
        cout<< "Remaining Students: " << waitlist << endl; // print the remaning students
    }

    return waitlist; // return the waitlist value
}

int main()
{
    bool classroom[4][4] = {{0, 1, 1, 1}, {0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 1}};
    int waitlist = 6;

    assert(fullClass(classroom, 4,  waitlist) == 0);

    bool classroom2[3][4] = {{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}};
    int waitlist2 = 9;

    assert(fullClass(classroom2, 3, waitlist2) == 1);
    	
    bool classroom3[5][4] = {{1,1,1,1}, {0,0,0,0}, {0,0,0,0}, {0,1,1,0}, {0,0,1,0}};
    int waitlist3 = 24;
    assert(fullClass(classroom3, 5, waitlist3) == 11);

    bool classroom4[0][4] = {};
    int waitlist4 = 6;
    assert(fullClass(classroom4, 0, waitlist4) == 6);  

    return 0;
}
