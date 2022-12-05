#include <iostream>
#include "map.h"
#include "time.h"
#include <string>
#include "player.h"
#include "flashlight.h"
#include "story_build.h"
#include <fstream>

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

    else if (limit == 5) // no forward or right
    {
        cout << "a - Left" << endl;
        cout << "s - Back" << endl << endl;
        //cout << "f - Use Flashlight" <<endl;

        cout << "z - Stats" << endl;
    }

    else if (limit == 6) // no forward or left
    {
        cout << "s - Back" << endl;
        cout << "d - Right" << endl << endl;
        //cout << "f - Use Flashlight" <<endl;

        cout << "z - Stats" << endl;
    }

    else if (limit == 7) // no back or right
    {
        cout << "w - Forward" << endl;
        cout << "a - Left" << endl;
        //cout << "f - Use Flashlight" <<endl;

        cout << "z - Stats" << endl;

    }

    else if (limit == 8) // no back or left 
    {
        cout << "w - Forward" << endl;
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

    else if (limit == 5) // no forward or right
    {
        cout << "a - Left" << endl;
        cout << "s - Back" << endl << endl;
        cout << "f - Use Flashlight" <<endl;

        cout << "z - Stats" << endl;
    }

    else if (limit == 6) // no forward or left
    {
        cout << "s - Back" << endl;
        cout << "d - Right" << endl << endl;
        cout << "f - Use Flashlight" <<endl;

        cout << "z - Stats" << endl;
    }

    else if (limit == 7) // no back or right
    {
        cout << "w - Forward" << endl;
        cout << "a - Left" << endl;
        cout << "f - Use Flashlight" <<endl;

        cout << "z - Stats" << endl;

    }

    else if (limit == 8) // no back or left 
    {
        cout << "w - Forward" << endl;
        cout << "d - Right" << endl << endl;
        cout << "f - Use Flashlight" <<endl;

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
    cout << "You've gathered " << player.getRemnants() << " ghost remnants." << endl;
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


bool keyGhost(int rem) // has key to escape, talks to you differently depending on how many ghost remnants the player has
{
    if (rem < 3)
    {
        cout << "\"AHHHHHHHHHHHHHHHH\" piercing screams come from above you." <<endl <<endl;

        cout << "\"Oh my GOODNESS. \" A chilling figure lowers from the ceiling and " << endl;
        cout << "looks upon you. It says, \"You scared me nearly to life! What is a " <<endl;
        cout << "lively soul like you doing around here? Surely you are newly dead. Or perhaps" << endl;
        cout << "not dead at all. You seem to be a living spirit stuck here in this cursed home.\"" << endl <<endl;

        cout << "While talking to this ghost you notice an old rusty key dangling from it's " <<endl;
        cout << "neck and the ghost notices you staring at the key. \"Oh you like my necklace? I've had" <<endl;
        cout << "this for as long as I've been stuck in this house. I couldn't bare to part with it." <<endl; 
        cout << "Perhaps if someone offered a fair trade for it... 3 ghost remnants would be sufficient.\"" <<endl;

        cout << "\"Oh well excuse me for blabering ooon and ooon, I must get back to my duties. Good luck" << endl;
        cout << "on your travls young one.\" You then see the ghost start to rise back up to the ceiling " <<endl;
        cout << "until it is out of sight." <<endl;

        return false;

    }

    else
    {
        cout << "\"Oh my oh my\" A chilling figure lowers from the ceiling and looks " << endl;
        cout << "upon you. \"Well hello there! I couldn't help but notice you have a few ghost " <<endl;
        cout << "remnants on you, I've been looking EVERY where for a few of those. Of course " << endl;
        cout << "by everywhere I mean every where in my little nook here  ... Perhaps you'd care " <<endl;
        cout << " to trade? I have a necklace that would suit you quiet nicely. Oh you will! How" <<endl;
        cout << "wonderful! Here, let me just tie the necklace onto you now. Thanks for the trade " <<endl; 
        cout << "travler! I hope to see you again soon!\" The ghost rises back up to the ceiling slowly." <<endl <<endl;

        cout << "You got a key!" <<endl;

        return true;

    }

}

// if returns true, remove one candy from characters inventory and give 2 ghost remnants
bool hungryGhost(int item)
{

    cout << "\"BlAaaaAaAaaAAAAaAAaH\"" <<endl;
    cout << "A rabid looking figure appears out of the darkness. You take a " << endl;
    cout << "step closer to it to see it is a wolf-like looking ghost scavenging the " <<endl;
    cout << "small corner it seems to guard. " << endl <<endl;

    if (item > 0)
    {
        cout << "It doesn't seem like the creature has found anything to eat. Maybe you " << endl;
        cout << "could give it something to snack on." <<endl << endl;

        cout << "y - Give the Ghost some candy." << endl;
        cout << "n - Walk away slowly. Hopefully it doesn't bite." <<endl;

        char choice;
        cin >> choice;
        cout << endl;
        while (choice != 'y' && choice != 'n')
        {
            cout << "Please make a valid selection" <<endl;
            cin >> choice;
        }

        if (choice == 'y')
        {
            cout << "You reach out your hand holding some of the candy you had found on the floor" <<endl;
            cout << "earlier. The creature darts it's eyes towards you and steps closer to inspect your offering." <<endl <<endl;

            cout << "It sniffs your hand and gently takes the candy out of your hand, slowly chewing." <<endl;
            cout << "The creatures fearful and tense nature disappears almost instantly and begins wagging it's tail." <<endl;
            cout << "It starts trotting around you excitedly and rubs against your leg in gratitude. After a moment" <<endl;
            cout << "of thanks the dog-ghost trots off into the dark and returns a moment later with 2 ghost remnants" <<endl; 
            cout << "it likely tried to eat earlier becuase it was covered in ghost dog slobber." <<endl <<endl;

            cout << "You got 2 ghost remnants!" <<endl <<endl;
            return true;
        }

        if (choice == 'n')
        {
            cout << "You back away from the rabid ghost. It gives you no attention as it " <<endl;
            cout << "continues searching for a meal." <<endl <<endl;
            return false;
        }

    
    }

    if (item == 0)
    {
        cout << "The creature seems hungry. It would proably appreciate some food." <<endl <<endl;

        return false;
    }
    return false;

}


void candyFound(bool found)
{
    if (!found)
    {
        cout << "You step on something and it crunches under your foot. You look down" <<endl;
        cout << "and see a slightly mushed candy bar. You pick it up and see it's an expired" <<endl;
        cout << "chocolate from the 80s\'. Score! " << endl <<endl;

        cout << "You got some candy!" <<endl; 
    }
    if (found)
    {
        return;
    }
}


bool exit(bool key)
{
    cout << "As you step you see a glimmer of light reflect off of something metallic. You step closer and " <<endl;
    cout << "see an old rusty door knob attached to a small rickety wooden door. Theres a small peep hole that " << endl;
    cout << "you look through to see a small unkept backyard." << endl <<endl;

    cout << "i - Investigate door" << endl;
    cout << "b - Brake down door" <<endl;
    cout << "m - Do nothing" << endl;

    char choice;
    cin >> choice;

    while (choice != 'i' && choice != 'b' && choice != 'm')
    {
        cout << "Please make valid selection." <<endl;
        cin >> choice;
    }

    if (choice == 'i')
    {
        cout << "You step towards the door and try fiddling with the handle. Locked. You try harder to open the" <<endl;
        cout << "door but it doesn't budge. You look closer at the handle of the door and see a large keyhole." <<endl;

        if (key)
        {
            cout << "It looks similar to the one that you traded for earlier, could be worth a shot!" <<endl <<endl;

            cout << "t - Use the key on the door " <<endl;
            cout << "m - Do nothing" <<endl <<endl;

            cin >> choice;

            if(choice == 't')
            {
                return true;
            }

        }
        else if (!key)
        {
            cout << "There's likely a key around here somewhere to open the door. But where?" <<endl <<endl;
        }
    }

    else if (choice == 'b')
    {
        cout << "You back up a bit to get a running start at the door. You run at full speed and careen your"  << endl;
        cout << "self onto the door. On impact the door erupts with blue light propelling your soul backwards " <<endl;
        cout << "and onto the ground with a thud. That would've hurt if you had any nerve endings! " <<endl <<endl;
        
        return false;
    }

    if (choice == 'm')
    {
        cout << "You back away from the door and move on with your search for a way out." <<endl <<endl;
    }

    return false;

}


int guessGame()
{
    cout << "A small ghost sits on the ground fidgetting with a rubix cude, a sudoku book, and a game of chess." <<endl;
    cout << "The ghost looks up from its puzzles and sees you approaching. It looks you up and down distastfully. " <<endl <<endl;

    cout << "\"Great, another dumb little mortal to distract me from my puzzles. I suppose you want some remnants" <<endl;
    cout << "from me huh? Yeah that's what I thought. Well look I'm not just gonna hand some over for you to waste " <<endl;
    cout << "on your \'precious\' life. You got yourself in this mess, and I am certainly not responsible for that.\" " <<endl <<endl;

    cout << "p - Try to persuade the ghost" <<endl;
    cout << "i - Insult the ghost" <<endl;
    cout << "m - Do nothing" << endl <<endl;

    char choice;

    while (choice != 'p' && choice != 'i' && choice != 'm') // to check if the player made a valid selection
    {
        cout << "Please make valid selection." <<endl;
        cin >> choice;
    }

    if (choice == 'p')
    {
        cout << "You then propose a game to the ghost in exchange for remnants. The ghost looks at you for a moment " <<endl;
        cout << "before saying, \"A game you say, well that could be interesting. But there's certainly no game where" <<endl;
        cout << "you would be capable of out smarting me. Simply impossible! ... Unless ... A game of chance! That " <<endl;
        cout << "could be sufficient. So! Here's the rules: I choose a number between 0 and 9. You try and guess what " <<endl;
        cout << "number I'm thinking of. Pretty simple. But you only get ONE guess, and I will only play once. Sound fair?" <<endl <<endl;

        cout << "I've chosen my number, now it's your turn. What's your guess?" << endl <<endl;

        int guess;
        cin >> guess;
        int number = rand() % (10);

        if(guess == number)
        {
            cout << "My goodness you got it!!! I suppose luck is on your side today. Seems as though I owe you these..." <<endl <<endl;
            
            cout << "You got 4 ghost remnants!" <<endl;
             
            return 1;
        }

        if (guess != number && guess < 10 && guess > -1)
        {
            cout << "Unfortunatly, that is not the correct guess... Well that was fun for a moment! Now leave me to " <<endl;
            cout << "my puzzles, I must finish this sudoku page before I can finish my chess game. Now scram!" <<endl << endl;
            return 0;
        }

        else 
        {
            cout << "Well that was just a waste of a guess. If you're not going to take this game seriously I will not" <<endl;
            cout << "be playing! Go waste somebody elses time." <<endl <<endl;

            return 0;
        }



    }

    if (choice == 'i') 
    {
        cout << "\"... Well that was just rude. Did you think that was going to help your chance of getting something" <<endl;
        cout << "from me?? You can forget about that now bud! Go bother someone else!\"" << endl <<endl;

        return 0;
    }

    if (choice == 'm')
    {
        return 0;
    }

    
    return 0;

}



/*  Algorithm for play function- 

    This function is what is used 
*/
void play(Time game_time)
{  
    Player player; // player class
    Flashlight flashlight;

    bool found_candy1 = false; // each boolean is for something interactive on the map that should not show again after use
    bool found_candy2 = false;
    bool guess_game = false;
    bool cat_toy = false;

    bool lights_on = false;

    int start = 0; // initial value to enter if statement
    char input; // to take input from player

    player.setRemnants(0); // set values for objects in player class
    player.setNumItems(0);
    player.setFoundKey(false);
    player.setEscaped(false);
    player.setFlashlightFound(false);
    player.setNumCandy(0);

    //cout << player.getGhostsSaved() << endl;

    Map map; // map class 
    //map.displayMap();

    assert(map.addGhost(0,0)); // ghosts 
    assert(map.addGhost(2,3)); 
    assert(map.addGhost(6,9));
    assert(map.addGhost(8,3)); // cat

    assert(map.addItem(7,0)); // flashlight

    assert(map.addItem(8,7)); // type writer
    assert(map.addItem(11,9)); // candy
    assert(map.addItem(0,8)); // flashlight
    assert(map.addItem(11,1)); // cat toy
    assert(map.addItem(6,2)); // candy
    assert(map.addItem(3,8)); // clock

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
                
            }
            else if (input == 'z') // if the player wants to check stats
            {
                statusUpdate(game_time, player);
            }
            else // if the input is none of the offered options
            {
                while (input != 'w' && input != 's' && input != 'a' ) // if the user didn't make a valid selection
                {
                    cout << "Please make a valid selection." << endl;
                    cin >> input;
                }
            }
            
        }

        
        if (map.getPlayerRow() == 2 && map.getPlayerCol() == 3) // if the player has landed on the space of the ghost that holds the key
        {
            if (input != 'z')
            {
                if (keyGhost(player.getRemnants())) // if the function returns then the player made a trade for the key
                {
                    player.subRemnants(); // take remnents from player
                    player.subRemnants();
                    player.setFoundKey(true); // set key to found
                    player.addMyItem("Key");
                    player.addItem();
                }
            }
        }

        if (map.getPlayerRow() == 6 && map.getPlayerCol() == 9) // if the player had landed on the space of the ghost that you can give candy
        {
            if (input != 'z')
            {
                if (hungryGhost(player.getCandy())) // if it returns true than the player gave candy to the ghost
                {
                    player.subCandy(); // take away candy
                    player.addRemnants(); // add remnents to players inventory
                    player.addRemnants();
                    player.removeItem(player.findItem("Candy Bar"));
                    player.subItem();
                    
                }
            }

        }
        if (map.getPlayerRow() == 11 && map.getPlayerCol() == 9) // if the player has found candy 
        {
            candyFound(found_candy1);
            
            if (!found_candy1)
            {
                player.addCandy(); // add candy to players candy stash
                player.addMyItem("Candy Bar");
                player.addItem();
            }
            found_candy1 = true; // make so the candy cannot be found again

        }

        if (map.getPlayerRow() == 6 && map.getPlayerCol() == 2) // if the player found a seperate pile of candy
        {
            candyFound(found_candy2);
            
            if(!found_candy2)
            {
                player.addCandy(); // add candy to players candy stash
                player.addMyItem("Candy Bar");
                player.addItem();
            }
            found_candy2 = true; // make so the candy cannot be found again
        }

        if (map.getPlayerRow() == 1 && map.getPlayerCol() == 11) // if the player has found the exit 
        {
            if (exit(player.getKeyFound()))
            {
                player.setEscaped(true);
                continue;
            }

        }

        if (map.getPlayerRow() == 0 && map.getPlayerCol() == 0) // if the player found the games ghost
        {
            if ( guess_game == false)
            {
                if (guessGame() == 1)
                {
                    player.addRemnants(); // add remnents to players inventory
                    player.addRemnants();
                    player.addRemnants();
                    player.addRemnants();
                }
            }

            else if (input != 'z') // if the input isn't to see the stats
            {
                cout << "The game ghost sees you approach once again and says, \"Haven't I told you mortal? Go AWAY! \"." << endl <<endl;
            }
            guess_game = true;
        }

        if (map.getPlayerRow() == 8 && map.getPlayerCol() == 7)
        {
            if (input != 'z')
            {
                cout << "On a small round table is an old but well kept type writer. There is fresh paper loaded and ink on" << endl;
                cout << "the keys." <<endl <<endl;

                cout << "t - Type a message" <<endl;
                cout << "m - Do nothing " <<endl;

                char choice;
                cin >> choice;

                while (choice != 't' && choice != 'm')
                {
                    cout << "Plese make valid selection." <<endl;
                    cin>> choice;
                }

                if (choice == 't')
                {
                    cout <<"What message would you like to type?" <<endl <<endl;

                    string message;
                    getline(cin, message);
                    cout <<endl; // formatting space

                    if (message == "Shivering Spines")
                    {
                        cout << "Once you finish typing the last \"s\" onto the page the type writer sends a shock to your" <<endl;
                        cout << "fingertips. And after a moment, the inside of the rickety house starts to illuminate," <<endl;
                        cout << "revealing all that lives within the house." <<endl;

                        lights_on = true;
                    }
                    else 
                    {
                        cout << "\"" << message << "\" is written in bold dark letters across the crisp page. " << endl;
                    }

                }
            }

            
        }


        if (map.getPlayerRow() == 11 && map.getPlayerCol() == 1) // cat toy
        {
            if (cat_toy == false)
            {
                cout << "You kick something as you walk and it rolls jingling across the floor. You walk over and pick up " << endl;
                cout << "the small yarn ball with bells attached that you had kicked." <<endl <<endl;

                cout << "You got a cat toy!" <<endl <<endl;

                player.addMyItem("Cat Toy");
                player.addItem();
                cat_toy = true;
            }

        }

        if (map.getPlayerRow() == 8 && map.getPlayerCol() == 3) // cat 
        {
            if (input != 'z')
            {
                cout << "An orange tabby sits near you, staring at you gently. You step closer to the cat but it hisses at you" << endl;
                cout << "the closer you get. From this distance you can see attatched to its collar is a ghost remnant." <<endl <<endl;
                
                if (cat_toy)
                {
                    cout << "i - Use cat toy" <<endl ;
                    cout << "m - Do nothing " <<endl << endl;

                    char choice_2;
                    cin>>choice_2;

                    while (choice_2 != 'i' && choice_2 != 'm')
                    {
                        cout << "Please enter valid selection." << endl;
                        cin >> choice_2;
                    }

                    if (choice_2 == 'i')
                    {
                        cout << "You get the cat toy you had found earlier and begin to tangle it above the tabby's head. The cat" <<endl;
                        cout << "is timid at first, just watching and occasionally wapping the toy, but as you continue to dangle " <<endl;
                        cout << "the toy above it's head, it starts to play with the yarn. Once the cat seems playful and calm you " <<endl;
                        cout << "you snatch the remnant from its collar." <<endl <<endl;

                        cout << "You got a ghost remnant!" <<endl << endl;

                        player.addRemnants();
                    }
                }
                cat_toy = false;
            }
        }






        // check position of player to see if they encountered ghost, item, or non interative feature
        
        if (!player.isFlashlightFound()) // if the flashlight has not been found 
        {
            if (map.getPlayerRow() == 0 && (map.getPlayerCol() == 11)) // if you can't move forward or right
            {
                limitedMenuPrint(5);
            }

            else if (map.getPlayerRow() == 0 && map.getPlayerCol() == 0) // if you can't move forward or left
            {
                limitedMenuPrint(6);
            }

            else if (map.getPlayerRow() == 11 && map.getPlayerCol() == 11) // if you can't move backwards or right
            {
                limitedMenuPrint(7);
            }

            else if (map.getPlayerRow() == 11 && map.getPlayerCol() == 0) // if you can't move backwards or left 
            {
                limitedMenuPrint(8);
            }

            else if (map.getPlayerRow() == 0) // if you can't move forward
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

            cout <<endl; // add space for formatting
            
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
                if (!map.move(input))
                {
                    cout << "You are unable to move in that direction, choose another option." << endl;
                    cin >> input; 
                }
                
                if (input == 'w' || input == 's')
                {
                    game_time.setTimeCount();
                    game_time.addTime();
                }  

                if(lights_on)
                {
                    map.displayMap(); // to check and debug
                    cout << endl;
                }
            }
        }



        if (player.isFlashlightFound()) // if the player can now use the flashlight
        {
            if (map.getPlayerRow() == 0 && (map.getPlayerCol() == 11)) // if you can't move forward or right
            {
                limitedMenuPrintNew(5);
            }

            else if (map.getPlayerRow() == 0 && map.getPlayerCol() == 0) // if you can't move forward or left
            {
                limitedMenuPrintNew(6);
            }

            else if (map.getPlayerRow() == 11 && map.getPlayerCol() == 11) // if you can't move backwards or right
            {
                limitedMenuPrintNew(7);
            }

            else if (map.getPlayerRow() == 11 && map.getPlayerCol() == 0) // if you can't move backwards or left 
            {
                limitedMenuPrintNew(8);
            } 
            else if (map.getPlayerRow() == 0)
            {
                limitedMenuPrintNew(1); 
            }
            
            else if (map.getPlayerRow() == 11)
            {
                limitedMenuPrintNew(4);
            }

            else if (map.getPlayerCol() == 0)
            {
                limitedMenuPrintNew(3);
            }

            else if (map.getPlayerCol() == 11)
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
            if (input == 'p')
            {
                flashlight.setSpaces(map.getPlayerRow(), map.getPlayerCol()); ////

            }

            else 
            {
                if (!map.move(input)) // if the input isn't valid
                {
                    cout << "You are unable to move in that direction, choose another option." << endl;
                    cin >> input; 
                }
                
                if (input == 'w' || input == 's') // increase time by one hour if the person moves forwards or backwards
                {
                    game_time.setTimeCount();
                    game_time.addTime();
                }  

                if (lights_on)
                {
                    map.displayMap(); // to check and debug
                    cout << endl;
                }
            }
        }

        


        

    } while (!player.isEscaped() && game_time.getTime() < 24);




    if (game_time.getTime() == 24) // if the time runs out and the player lost the game
    {
        cout << endl;
        cout << "You hear a clock strike 12 times. The deep ominous voice returns, " << endl;
        cout << "growling with a resonance that shakes the walls of the old rickety house." << endl;
        cout << "\"Well well well, seems like I have a new soul to torture. Didn't make it out in time" << endl;
        cout << "huh? Well better luck in your next life ... if you ever escape. \" " << endl << endl;;

        cout << "GAME OVER" << endl;
    }

    if (player.isEscaped())
    {
        cout << "Suddenly you feel your body began to re-merge with your soul, and you take a step back into " <<endl;
        cout << "the real world. Your feet land on the porch of the house, mysteriously back where you had entered " <<endl;
        cout << "the house originally. But before you can begin to process anything, you hear a deep whisper in the " <<endl;
        cout << "back of your head, \"You escaped this time human. But be warned, if you return you will not get the " <<endl;
        cout << "chance to again.\" " <<endl <<endl;

        cout << "YOU WIN!" <<endl <<endl;

        cout <<"Check file \"WinningStats.txt\" for your stats!" <<endl;

        ofstream winner;

        winner.open("WinningStats.txt");

        winner << game_time.getTimeCount() << " hours passed on your play through." << endl;
        winner << "You gathered " << player.getRemnants() << " ghost remnants." << endl;
        if (player.isFlashlightFound())
        {
            winner << "You found the flashlight!" << endl << endl;
        }
        else 
        {
            winner << "You did not find the flashlight." << endl <<endl;
        }

        winner << "Secret Message : Shivering-Spines" <<endl;
    }


    

    return;
    
}




int main()
{
    Time game_time;

    game_time.setTime(0);

    play(game_time);
    


    return 0;
}