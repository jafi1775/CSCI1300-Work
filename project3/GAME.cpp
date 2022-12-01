// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 3, Game driver file

#include <iostream>
#include "map.h"
#include "time.h"
#include <string>
#include "player.h"
#include "flashlight.h"
#include "story_build.h"
#include <fstream>


using namespace std;

int main()
{
    int menu_input = 1; // initial menu input
    Time game_time; // creates time object
    srand(time(0));

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
            cout << "Well I suggest you make your way out before your visit becomes ... permanent. You have 24 hours before Halloween " << endl;
            cout << "ends and you're stuck in my domain FOREVER! Good luck ... MUAHAHAHA\"" << endl << endl;

    

        break;



        case 2: 
            int time_input; // create input for desired time
            cout << "How many game time hours would you like to finish the game? (must be between 12 and 23 hours)" << endl;
            cin >> time_input;
            while(time_input < 12 || time_input > 24 ) // checking if input is valid
            {
                cout << "Please choose a valid amount" << endl;
                cin >> time_input;
            }
            game_time.setTime(24 - time_input); // sets time to input time 

            cout << "It's " << game_time.getTime() << " o'clock on Halloween (military time). You're a " << endl;
            cout << "young jokester who loooooooves Halloween. In your anticipation for the special night you went" << endl;
            cout << "exploring the abandoned neighborhoods that your parents told you never to venture." << endl << endl;

            cout << "On your adventure you stumble upon an eerie house that you've never seen before, you dare to enter." << endl;
            cout << "Upon your entry your body drops to the floor, but you're still standing! You became a GHOST! A spooky low " << endl;
            cout << "voice tells you, \"Who dares to enter MY purgatory?! Ah! A silly little mortal, what are you doing here? " << endl;
            cout << "Well I suggest you make your way out before your visit becomes ... permanent. You have " << time_input << " hours before Halloween " << endl;
            cout << "ends and you're stuck in my domain FOREVER! Good luck ... MUAHAHAHA\"" << endl << endl;


        break;


        case 3:

            game_time.randTime(); // generates a random amount of hours to start the game

            cout << "It's " << game_time.getTime() << " o'clock on Halloween (military time). You're a " << endl;
            cout << "young jokester who loooooooves Halloween. In your anticipation for the special night you went" << endl;
            cout << "exploring the abandoned neighborhoods that your parents told you never to venture." << endl << endl;

            cout << "On your adventure you stumble upon an eerie house that you've never seen before, you dare to enter." << endl;
            cout << "Upon your entry your body drops to the floor, but you're still standing! You became a GHOST! A spooky low " << endl;
            cout << "voice tells you, \"Who dares to enter MY purgatory?! Ah! A silly little mortal, what are you doing here? " << endl;
            cout << "Well I suggest you make your way out before your visit becomes ... permanent. You have " << 24 - game_time.getTime() << " hours before Halloween " << endl;
            cout << "ends and you're stuck in my domain FOREVER! Good luck ... MUAHAHAHA\"" << endl << endl;


        break;

        // case 4:

        // break;
    }

}