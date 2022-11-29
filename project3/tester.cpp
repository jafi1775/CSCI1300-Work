#include <iostream>
#include "time.cpp"
#include "player.cpp"


using namespace std;

int main() // tester for random time function
{
    // Time game_time;
    // game_time.randTime();
    // cout << game_time.getTime() << endl;

    Player player;
    cout << player.getGhostsSaved() << endl;
    cout << player.getNumItems() <<endl;
    cout << player.getKeyFound() << endl;
    cout << player.isEscaped() <<endl;

}
