// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 6, Question 2

#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include <sstream>
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
        for(int i=0; i < input_string.length(); i++) // iterating through the string
        {
            if (input_string[i] == seperator) // if the character is the defined deliminator
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


/*  Algorithm for printMountainStats function-
    1. Take in filename as parameter 
    2. Declare line variable for the getline function, input for the input stream, num_lines as a counter for the number of lines with information from the file, the string array for the split function and the name of the mountain, the variable for the shortest and largest mountain heights (and names), and an integar array for the heights.
    3. Definer shortest as a very large number, and largest as 0.
    4. Open the file.
    5. Check if the file opened/failed
    6. If the file failed then print an error message.
    7. If the file opened, then enter an else statement.
    8. Create a while loop that reads the file while there is still information to read from the file.
    9. Use getline for each line of the file.
    10. If the line is empty, skip to the next iteration.
    11. If the line has data, then enter else statement.
    12. In else statement, increment num_lines by 1.
    13. Empty name array.
    14. Use split function on line variable to populate the name array.
    15. Populate the number array with the first element from the name array, and convert to integar with the stoi function.
    16. Then check to see if the current mountains height is smaller than the shortest variable or larger than the tallest variable.
    17. If the current mountains height is smaller than the value in the shortest variable, then replace the variables value for the new value
    18. Repeat for the tallest mountaint variable.
    19. Also replace the name of the mountain for each tallest and shortest mountain if the variables for the heights are replaced.
    20. After the while loop, print the number of lines and the shortest and tallest mountain.
    21. Close the file.
    22. Return nothing.
*/
void printMountainStats(string file_name)
{
    string line; // variable for split 
    ifstream input; // variable for getline
    int num_lines = 0; // counter for number of lines with input 
    string arr_name[2], name, name2; // initial array taking all info, and variables for mountain names
    int arr_num[2], shortest = 300000, tallest = 0; // array taking in numbers of height, and variables comparing shortest and tallest mountain.

    input.open(file_name); // open file

    if (input.fail()) // check if file opened
    {
        cout << "Could not open file." << endl; // print if file didn't open
    }
    else 
    {   
        while(!input.eof()) // while there is information in the stream, keep looping
        {
            getline(input,line); // get one line at a time from the file

            

            if (line == "") // if the line is empty, move to the next iteration
            {
                continue;
            }
            else 
            {
                num_lines++; // increment the number of lines by 1

                arr_name[0] = ""; // reset array elements 
                arr_name[1] = "";

                split(line, '|', arr_name, 2); // use split function on each line

            
                arr_num[0] = stoi(arr_name[1]); // move heigth of mountain into integar array


                if (arr_num[0] < shortest) // if this iterations height is less than the current height
                {
                    shortest = arr_num[0]; // replace the current shortest mountain with the new value
                    name = arr_name[0]; // replace the current name with the name of the mountain from this iteration
                }
                if (tallest < arr_num[0]) // if this iteration height is more than the current height
                {
                    tallest = arr_num[0]; // replace the current tallest mountian with the new value 
                    name2 = arr_name[0]; // replace the current name with the name of the mountain from this iteration

                }
            
            

            }

        }
        input.close(); // close the file

        cout << "Number of lines read: " << num_lines << "." << endl; // print the number of lines with information in the file
        cout << "Tallest mountain: " << name2 << " at " << tallest << " feet." << endl; // print the tallest mountain 
        cout << "Shortest Mountain: " << name << " at " << shortest << " feet." << endl; // print the shortest mountain

    }

    return; // return nothing
}

int main()
{
    string filename = "mountain_data.txt";
    printMountainStats(filename);
    printMountainStats("mountain_data2.txt");
    printMountainStats("mountain.txt");
    printMountainStats("doesn't_exist");

    return 0;
}