#include <iostream>
#include "map.h"
#include "time.h"
#include <string>
#include "player.h"
#include "flashlight.h"
#include "story_build.h"

using namespace std;

// if returns true remove 3 ghost remnants from player and give key
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
        cout << "travler! I hope to see you again soon!\" The ghost rises back up to the ceiling slowly." <<endl;

        return true;

    }

}

// if returns true, remove one candy from characters inventory and give 2 ghost remnants
bool hungryGhost(bool has_item)
{

    cout << "\"BlAaaaAaAaaAAAAaAAaH\"" <<endl;
    cout << "A rabid looking figure appears out of the darkness. You take a " << endl;
    cout << "step closer to it to see it is a wolf-like looking ghost scavenging the " <<endl;
    cout << "small corner it seems to guard. " << endl <<endl;

    if (has_item)
    {
        cout << "It doesn't seem like the creature has found anything to eat. Maybe you " << endl;
        cout << "could give it something to snack on." <<endl << endl;

        cout << "y - Give the Ghost some candy." << endl;
        cout << "n - Walk away slowly. Hopefully it doesn't bite." <<endl;

        char choice;
        cin >> choice;
        cout << endl;

        if (choice == 'y')
        {
            return true;
        }

        if (choice == 'n')
        {
            cout << "You back away from the rabid ghost. It gives you no attention as it " <<endl;
            cout << "continues searching for a meal." <<endl;
            return false;
        }
    
    }

}
