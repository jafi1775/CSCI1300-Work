// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 3, Game driver file


#include <iostream>
#include "time.cpp"
//#include "map.cpp"

using namespace std;

int main()
{
    int menu_input = 1; // initial menu input

    do // checks if input for menu is valid 
    {
        if (menu_input < 1 || menu_input > 3)
        {
            cout << "Please make a valid selection." << endl; // if the initial selection isn't valid
        }

        cout << "Welcome to GHOST ESCAPE! Please choose an option to start:" << endl;
        cout << "1 - Start Game" << endl;
        cout << "2 - Customized Start" << endl;
        cout << "3 - Random Start" << endl;
        cout << "4 - Quit" << endl;
        cin >> menu_input;

    } while (menu_input < 1 || menu_input > 3);

    switch (menu_input)
    {
        case 1: 
            //Time time1;
            cout << endl << "The clock strikes midnight in a small suburban town, it is officially Halloween. You're a " << endl;
            cout << "young jokester who loooooooves Halloween. In your anticipation for the special night you went" << endl;
            cout << "exploring the abandoned neighborhoods that your parents told you never to venture." << endl << endl;

            cout << "On your adventure you stumble upon an eerie house that you've never seen before, you dare to enter." << endl;
            cout << "Upon your entry your body drops to the floor, but you're still standing! You became a GHOST! A spooky low " << endl;
            cout << "voice tells you, \"Who dares to enter MY purgatory?! Ah! A silly little mortal, what are you doing here? " << endl;
            cout << "Well I suggest you make your way out before your visit becomes ... permanent. MUAHAHAHA\"" << endl;

        break;



        case 2: 

        break;


        case 3:

        break;

        case 4:

        break;
    }

}