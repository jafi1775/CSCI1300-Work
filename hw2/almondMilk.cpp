// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 2 - Problem 3


#include <iostream> 
#include <cmath>
#include <iomanip>

using namespace std;

int main() 
{
    double height_of_carton, length_of_carton, volume_of_carton;

    cout << "What is the side length of the base of the carton in inches? " <<endl;
    cin >> length_of_carton;
    cout << "What is the height of the carton in inches? " <<endl;
    cin >> height_of_carton;
    volume_of_carton = length_of_carton * length_of_carton * height_of_carton; // calculating the volume of the carton in cubic inches
    volume_of_carton = volume_of_carton * .55; // converting from cubic inches to ounces
    
    cout << fixed << setprecision(1) << "The carton has a volume of " << volume_of_carton << " ounces." <<endl;

    return 0;
}