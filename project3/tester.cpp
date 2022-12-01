#include <iostream>
//#include "time.cpp"
#include "player.h"


using namespace std;

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
            cout << number << endl;
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

int main() // tester for random time function
{
    // Time game_time;
    // game_time.randTime();
    // cout << game_time.getTime() << endl;

    // Player player;

    //  player.setGhostsSaved(0);
    //  player.setNumItems(5);
    //  player.setFoundKey(false);
    //  player.setEscaped(false);

    // cout << "A:" << player.getGhostsSaved() << endl;
    // cout << "B: " << player.getNumItems() <<endl;
    // cout << "C: " << player.getKeyFound() << endl;
    // cout << "D: " << player.isEscaped() <<endl;

    srand(time(0));

    int number = rand() % (10);
    
    guessGame();

    return 0;


}
