// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 3 - Problem 3

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{   
    char size;
    int toppings;
    double total;
    cout << "What size pizza would you like to order?" << endl; // prompt user for pizza size input 
    cin >> size;
    
    if (size != 'S' && size != 'M' && size != 'L') // if input for size is not valid
    {
        cout << "Please enter a valid input." << endl;
        return 0;
    }
    else 
    {
        cout << "How many toppings do you want?" << endl; // prompt user for toppings input 
        cin >> toppings;

        if (toppings < 0)
        {
            cout << "Please enter a valid input." << endl; // if toppings input is not valid
            return 0;
        }
        else if (size == 'S') // price calculator for Small sized pizzas
        {
            double topping_cost = toppings * .75; // price per topping calculation
            total = topping_cost + 4.99;
            cout << "Your total is $" << fixed<< setprecision(2) << total << endl; // formatting total output with set precision 
            return 0;
        }
        else if (size=='M') // price calculator for Medium pizza
        {
            double topping_cost = toppings * 1.50;
            total = topping_cost + 5.99;
            cout << "Your total is $" << fixed<< setprecision(2) << total << endl;
        }
        else  // catch all else statement for Large pizzas 
        {
            double topping_cost = toppings * 2.25;
            total = topping_cost + 6.99;
            cout << "Your total is $" << fixed<< setprecision(2) << total << endl;
        }
    }

    return 0;
}