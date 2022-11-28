#include <iostream>

using namespace std;

int main(){
    // declare an int
    int testInt = 12;

    // declare another int
    int secondInt = 7;

    // divide one int by the other USING INTEGER DIVISION, print result
        cout << testInt / secondInt << endl;

    // divie one int by the other USING FLOATING POINT DIVISION, print result
        cout << testInt / static_cast<double>(secondInt) << endl;


    // print out remainder of dividing one int by the other (hint: modulo operator)
        cout << testInt % secondInt << endl;

    return 0;
}