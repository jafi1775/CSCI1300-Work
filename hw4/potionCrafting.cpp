// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 4 - Problem 3

#include <iostream>
using namespace std;

int main()
{
    int potionType, honeycomb, dandelions, coal, toadstools, health=0, mana=0;
    cout << "Select a potion crafting priority:\n" << "1. Minor Mana\n" << "2. Minor Healing" << endl;
    cin >> potionType;

    while (potionType != 1 && potionType != 2) // checking for invalid input for priority potion
    {
        cout << "Invalid input.\n" << "Select a potion crafting priority:\n" << "1. Minor Mana\n" << "2. Minor Healing" << endl;
        cin >> potionType;
    }
    if (potionType== 1 || potionType == 2) // double checking for valid input 
    {
        cout << "How many Honeycombs do you have?" << endl;
        cin >> honeycomb;
        while (honeycomb<0) // checking for valid honeycomb input
        {
            cout << "Invalid input. How many Honeycombs do you have?" << endl;
            cin >> honeycomb;
        }
        cout << "How many Dandelions do you have?" << endl;
        cin >> dandelions;
        while (dandelions<0) // checking for valid dandelion input
        {
            cout << "Invalid input. How many Dandelions do you have?" << endl;
            cin >> dandelions;
        }
        cout << "How many Coal do you have?" << endl;
        cin >> coal;
        while (coal<0) // checking for valid coal input 
        {
            cout << "Invalid input. How many Coal do you have?" << endl;
            cin >> coal;
        }
        cout << "How many Toadstools do you have?" << endl;
        cin >> toadstools;
        while (toadstools<0) // checking for valid toadstool input 
        {
            cout << "Invalid input. How many Toadstools do you have?" << endl;
            cin >> toadstools;
        }

        if (potionType==1) // for if mana potions are priority
        {
            while(honeycomb>=5 && dandelions>=3 && coal>=1) // mana potion counter
            {
                honeycomb -= 5;
                dandelions -=3;
                coal -= 1;
                mana++;
            }
            while (honeycomb>=5 && toadstools>=3 && coal>=2) // health potion counter 
            {
                honeycomb -= 5;
                toadstools -=3;
                coal -= 2;
                health++; 
            }
            cout << "You can make " << mana << " Mana potion(s) and " << health << " Healing potion(s)." << endl; // output for amount of each potions when mana potions are priority
        }
        else // for if health potions are priority input 
        {   
            while (honeycomb>=5 && toadstools>=3 && coal>=2) // health potion counter
            {
                honeycomb -= 5;
                toadstools -=3;
                coal -= 2;
                health++; 
            }
            while(honeycomb>=5 && dandelions>=3 && coal>=1) // mana potion counter
            {
                honeycomb -= 5;
                dandelions -=3;
                coal -= 1;
                mana++;
            }
            cout << "You can make " << health << " Healing potion(s) and " << mana << " Mana potion(s)." << endl; // output for amount of each potions when health potions are priority
        }
    }
    
    return 0;
}