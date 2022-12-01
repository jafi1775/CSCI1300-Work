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
        cout << "until it is out of sight." <<endl <<endl;

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

void candyFound1(bool found)
{
    if (!found)
    {
        cout << "You step on something and it crunches under your foot. You look down" <<endl;
        cout << "and see a slightly mushed candy bar. You pick it up and see it's an expired" <<endl;
        cout << "chocolate from the 80s\'. Score! " << endl <<endl;

        cout << "You got some candy!" <<endl <<endl; 
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
        cout << "from me?? You can forget about that now bud! Go bother someone else!\"" << endl << endl;

        return 0;
    }

    if (choice == 'm')
    {
        return 0;
    }

    
    return 0;

}

