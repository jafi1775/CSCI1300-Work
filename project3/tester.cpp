#include <iostream>
#include "time.cpp"

using namespace std;

int main() // tester for random time function
{
    Time game_time;
    game_time.randTime();
    cout << game_time.getTime() << endl;
}
