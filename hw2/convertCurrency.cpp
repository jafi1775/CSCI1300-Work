// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 2 - Problem 5

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int Bolts, Gold, Gems; 
    cout << "Enter the number of Bolts: " << endl;
    cin >> Bolts;

    if (Bolts < 23) // seperating Bolt quantities to make it easier for the arithmetic equations 
    {
        cout << "0 Gem(s) 0 GoldCoin(s) " << Bolts << " Bolt(s)" <<endl;
    }
    else if (Bolts < 299)
    {
        Gold = Bolts / 23;
        Bolts = Bolts % 23;
        cout << "0 Gem(s) " << Gold << " GoldCoin(s) " << Bolts << " Bolt(s)" <<endl;

    }
    else
    {
        Gems = Bolts / 299;
        Gold = (Bolts / 23) % 13;
        Bolts = Bolts % 23;
        cout << Gems << " Gem(s) " << Gold << " GoldCoin(s) " << Bolts << " Bolt(s)" <<endl;

    }


    return 0;
}