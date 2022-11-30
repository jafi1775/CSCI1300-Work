#include <iostream>
#include "map.h"
#include "time.h"
#include <string>
#include "player.h"
#include "flashlight.h"
#include "story_build.h"

using namespace std;

/*  Algorithm for menuPrint function- 

    This function is used to print out the menu that will show after every action that the player takes.
    This is the default menu, assuming the player has not yet found the flashlight and are able to move 
    about the map in any direction.
*/
void menuPrint()
{
    cout << "w - Forward" << endl;
    cout << "a - Left" << endl;
    cout << "s - Back" << endl;
    cout << "d - Right" << endl << endl;
    //cout << "f - Use Flashlight" <<endl;

    cout << "z - Stats" << endl;

    return;
}

// this menu is the same as the previous, but with the option to use the flashlight
void menuPrintNew()
{
    cout << "w - Forward" << endl;
    cout << "a - Left" << endl;
    cout << "s - Back" << endl;
    cout << "d - Right" << endl;
    cout << "p - Use Flashlight" <<endl << endl;

    cout << "z - Stats" << endl;

    return;

}

/*  Algorithm for limitedMenuPrint function -

    This funciton is used to print outt the menu that will show after every action the player takes.
    This menu is used when a player has not found a flashlight and is right next to a wall of the map, 
    meaning they are unable to move a certain direction. 

    1. The function takes in an integar.
    2. The integar represents which wall has been hit/found and which way the character is unable to move.
    3. 1 represents forward, 2 right, 3 left, 4 back.
*/
void limitedMenuPrint(int limit)
{
    if (limit == 1) // no forward
    {
        cout << "a - Left" << endl;
        cout << "s - Back" << endl;
        cout << "d - Right" << endl << endl;

        cout << "z - Stats" << endl;
    }

    else if (limit == 2) // no right
    {
        cout << "w - Forward" << endl;
        cout << "a - Left" << endl;
        cout << "s - Back" << endl << endl;
        //cout << "f - Use Flashlight" <<endl;

        cout << "z - Stats" << endl;
    }

    else if (limit == 3) // no left
    {
        cout << "w - Forward" << endl;
        cout << "s - Back" << endl;
        cout << "d - Right" << endl << endl;
        //cout << "f - Use Flashlight" <<endl;

        cout << "z - Stats" << endl;

    }
    else if (limit == 4) // no back
    {
        cout << "w - Forward" << endl;
        cout << "a - Left" << endl;
        cout << "d - Right" << endl << endl;
        //cout << "f - Use Flashlight" <<endl;

        cout << "z - Stats" << endl;

    }
    return;
}

/* Algorithm for limitedMenuPrintNew function-

    This function prints the menu out that will be shown after every player
    action. This menu is presented if the flashlight is found and if the player is around a wall.
    
    1. The function takes an integar in the represents which wall the player is at or which way the player cannot move.
    2. 1 represents forward, 2 right, 3 left, 4 back (for which way the character cannot move).
*/
void limitedMenuPrintNew(int limit)
{
    if (limit == 1) // no forward
    {
        cout << "a - Left" << endl;
        cout << "s - Back" << endl;
        cout << "d - Right" << endl;
        cout << "p - Use Flashlight" <<endl << endl;

        cout << "z - Stats" << endl;
    }

    else if (limit == 2) // no right
    {
        cout << "w - Forward" << endl;
        cout << "a - Left" << endl;
        cout << "s - Back" << endl;
        cout << "p - Use Flashlight"  << endl << endl;

        cout << "z - Stats" << endl;
    }

    else if (limit == 3) // no left
    {
        cout << "w - Forward" << endl;
        cout << "s - Back" << endl;
        cout << "d - Right" << endl;
        cout << "p - Use Flashlight" << endl << endl;

        cout << "z - Stats" << endl;

    }
    else if (limit == 4) // no back
    {
        cout << "w - Forward" << endl;
        cout << "a - Left" << endl;
        cout << "d - Right" << endl;
        cout << "p - Use Flashlight" << endl << endl;

        cout << "z - Stats" << endl;

    }
    return;
}

/*  Algorithm for statusUpdate function- 

    This function prints out how many hours have passed in the game, how many 
    ghosts you've saved, and the items you've collected so far.
*/
void statusUpdate(Time game_time, Player player)
{

    cout << game_time.getTimeCount() << " hours have passed." << endl;
    cout << "You've saved " << player.getGhostsSaved() << " ghosts." << endl;
    cout << "You have: " ;
    if (player.getNumItems() == 0)
    {
        cout << "No Items." << endl;
    }
    else 
    {
        player.printMyItems(); 
    }
    cout << endl;
}

/*  Algorithm for play function- 

    This function is what is used 
*/
void play(Time game_time)
{  
    Player player; // player class
    Flashlight flashlight;
    int start = 0; // initial value to enter if statement
    char input; // to take input from player

    player.setGhostsSaved(0); // set values for objects in player class
    player.setNumItems(0);
    player.setFoundKey(false);
    player.setEscaped(false);

    //cout << player.getGhostsSaved() << endl;

    Map map; // map class 
    //map.displayMap();

    assert(map.addGhost(0,0)); // ghosts 
    assert(map.addGhost(3,3));
    assert(map.addGhost(5,5));
    assert(map.addGhost(6,9));
    assert(map.addGhost(8,3));

    assert(map.addItem(7,0)); // flashlight

    assert(map.addItem(8,7)); // non interactive features or items
    assert(map.addItem(11,9)); 
    assert(map.addItem(0,8));
    assert(map.addItem(1,5));
    assert(map.addItem(6,2));
    assert(map.addItem(3,8));

    do
    {
        if(start == 0) // first thing that runs 
        {
            limitedMenuPrint(4); // menu that is displayed when player can't move backwards
            start ++; // so you can't enter the if statement again
            cin >> input;
            
            if (input == 'w' || input == 'a' || input == 'd') // checks if the input is a movement 
            {
                map.move(input);
                if (input == 'w') // if the player is moving forward increase the time by one hour 
                {
                    game_time.setTimeCount();
                }                
                
                map.displayMap(); // to check work
                cout << endl;
            }
            else if (input == 'z') // if the player wants to check stats
            {
                statusUpdate(game_time, player);
            }
            else // if the input is none of the offered options
            {
                while (input != 'w' && input != 's' && input != 'a' ) 
                {
                    cout << "Please make a valid selection." << endl;
                    cin >> input;
                }
            }
            
        }

        // check position of player to see if they encountered ghost, item, or non interative feature
        
        if (!player.isFlashlightFound()) // if the flashlight has not been found 
        {
            if (map.getPlayerRow() == 0) // if you can't move forward
            {
                limitedMenuPrint(1); 
            }
            
            else if (map.getPlayerRow() == 11) // if you can't move backwards
            {
                limitedMenuPrint(4);
            }

            else if (map.getPlayerCol() == 0) // if you can't move to the left
            {
                limitedMenuPrint(3);
            }

            else if (map.getPlayerCol() == 11) // if you can't move to the right 
            {
                limitedMenuPrint(2);
            }

            else // if you can move any direction
            {
                menuPrint();
            }
            
            cout << endl; // add space 

            cin >> input; // take players input from menu

            
            while (input != 'w' && input != 'd' && input != 's' && input != 'a' && input != 'z')
            {
                cout << "Please make a valid selection." << endl;
                cin >> input;
            }

            if (input == 'z')
            {
                statusUpdate(game_time, player);
            }
            else 
            {
                //map.move(input);
                if (!map.move(input))
                {
                    cout << "You are unable to move in that direction, choose another option." << endl;
                    cin >> input; 
                }
                
                if (input == 'w' || input == 's')
                {
                    game_time.setTimeCount();
                }  

                map.displayMap(); // to check and debug
                cout << endl;
            }
        }



        if (player.isFlashlightFound())
        {
            if (map.getPlayerRow() == 0)
            {
                limitedMenuPrintNew(1); 
            }
            
            if (map.getPlayerRow() == 11)
            {
                limitedMenuPrintNew(4);
            }

            if (map.getPlayerCol() == 0)
            {
                limitedMenuPrintNew(3);
            }

            if (map.getPlayerCol() == 11)
            {
                limitedMenuPrintNew(2);
            }

            else
            {
                menuPrintNew();
            }

            cout << endl; // add space 

            cin >> input; // take players input from menu

            
            while (input != 'w' && input != 'd' && input != 's' && input != 'a' && input != 'z' && input != 'p')
            {
                cout << "Please make a valid selection." << endl;
                cin >> input;
            }

            if (input == 'z')
            {
                statusUpdate(game_time, player);
            }

            // if they use the flashlight 
            else if (input == 'p')
            {
                flashlight.setSpaces(map.getPlayerRow(), map.getPlayerCol());

            }

            else 
            {
                //map.move(input);
                if (!map.move(input))
                {
                    cout << "You are unable to move in that direction, choose another option." << endl;
                    cin >> input; 
                }
                
                if (input == 'w' || input == 's')
                {
                    game_time.setTimeCount();
                }  

                map.displayMap(); // to check and debug
                cout << endl;
            }
        }

        


        

    } while (!player.isEscaped() && game_time.getTimeCount() < 24);


    if (game_time.getTimeCount() == 24) // if the time runs out and the player lost the game
    {
        cout << endl;
        cout << "You hear a clock strike 12 times. The deep ominous voice returns, " << endl;
        cout << "growling with a resonance that shakes the walls of the old rickety house." << endl;
        cout << "\"Well well well, seems like I have a new soul to torture. Didn't make it out in time" << endl;
        cout << "huh? Well better luck in your next life ... if you ever escape. \" " << endl << endl;;

        cout << "GAME OVER" << endl;
    }


    

    return;
    
}




// int main()
// {
//     Time game_time;

//     play(game_time);
    


//     return 0;
// }