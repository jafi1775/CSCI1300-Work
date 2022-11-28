// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 6, Question 4b

#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int split(string input_string, char seperator, string arr[], int arr_size)
{

    int temp = 0; // temporary variable to count how many splits happen

    if (input_string == "")  // if the string is empty
    {
        return temp;
    }
    else 
    {   
        int x = input_string.length();

        for(int i=0; i < x; i++) // iterating through the string
        {
            if(arr_size < temp + 1) // used this for readRatings.cpp
            {
                return -1;
            }
            else if (input_string[i] == seperator) // if the character is the defined deliminator
            {   
                temp++; // increment temporary variable by 1
                continue; // continue to next iteration
            }
            else // if the character is not the deliminator
            {
                arr[temp] += input_string[i]; // place character into array element until temp changes 
            }
            
        }
        if (arr_size < temp + 1) // if the number of split elements from the string become larger than the array size
        {
            temp = -1;
            return temp;
        }
        else 
        {
            temp ++; // returning the number of elements in the array. Because array indexing starts at 0, must add 1 for accurate number
            return temp;
        }

    }
}

int readRestaurantData(string filename, string restaurant[], int ratings[][3], int arrSize)
{
    ifstream res;
    int num_lines = 0;
    string line, temp_arr[4];

    res.open(filename);

    if (res.fail())
    {
        return -1;
    }
    else
    {
        while(!res.eof())
        {
            getline(res, line);

            temp_arr[0] = "";
            temp_arr[1] = "";
            temp_arr[2] = "";
            temp_arr[3] = "";

            //cout<< "before" << endl;

            int x = split(line, '~', temp_arr, 4);

            //cout << "after" << endl;

            if(num_lines == arrSize) // if the array is too small and the 
            {
                break;
            }

            if (x == -1)
            {
                continue;
            }
            else if (x == 4)
            {
                // cout << num_lines << endl;
                restaurant[num_lines] = temp_arr[0];
                
                // cout << temp_arr[0] << endl;
                // cout << temp_arr[1] << endl;
                // cout << temp_arr[2] << endl;
                // cout << temp_arr[3] << endl;
                
                string temp = temp_arr[3];
                temp = temp[0];

                // cout << temp << endl;

                // if (num_lines == arrSize)
                // {
                //     break;
                // }

                ratings[num_lines][0] = stoi(temp_arr[1]);
                //cout << ratings[num_lines][0] << endl;

                ratings[num_lines][1] = stoi(temp_arr[2]);
                //cout << ratings[num_lines][1] << endl;

                ratings[num_lines][2] = stoi(temp);
                //cout << ratings[num_lines][2] << endl;

                // for (int i=0; i< 3; i++)
                // {
                //     ratings[num_lines][i] = stoi(temp[i+1]);
                // }
                
                num_lines++;
            }
        }
        res.close();
    }

    return num_lines;
}

/*  Algorithm- 
    1. Take in a string array for the restaurant names, an int 2d array for the ratings for the restaurants, and an integar for the number of restaurants as parameters.
    2. In the function declare a variable that will represent the score.
    3. Create a for loop that iterates through the ratings array.
    4. In the for loop, define score as the equation given in the github with each ratings element in the i row.
    5. Print out the restaurant name at the iteration of i, and the score for that restaurant at a fixed set precision of 1.
    6. Return nothing.
*/

void calcOverallScore(string restaurants[], int ratings[][3], int num_restaurants)
{
    double score; // variable for score

    for (int i=0; i < num_restaurants; i++) 
    {
        score = (6.3 * ratings[i][0]) + (4.3 * ratings[i][1]) + (3.4 * (5 - ratings[i][2])); // equation equal to score, with the each element in the iteration of i's row.
        cout << restaurants[i] << " overall score: " << fixed << setprecision(1) << score << endl; // print out the statement with the score.
    }

    return; // return nothing
}


int main()
{
    return 0;
}