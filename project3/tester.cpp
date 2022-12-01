#include <iostream>
//#include "time.cpp"
#include "player.h"


using namespace std;

int main() // tester for random time function
{
    // Time game_time;
    // game_time.randTime();
    // cout << game_time.getTime() << endl;

    Player player;

     player.setGhostsSaved(0);
     player.setNumItems(5);
     player.setFoundKey(false);
     player.setEscaped(false);

    cout << "A:" << player.getGhostsSaved() << endl;
    cout << "B: " << player.getNumItems() <<endl;
    cout << "C: " << player.getKeyFound() << endl;
    cout << "D: " << player.isEscaped() <<endl;

}
