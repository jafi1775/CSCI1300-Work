#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

void newRad(double side_length)
{

    srand(time(0));

    double half = side_length/2;

    //double scaling = rand() / double(RAND_MAX);
    //cout << scaling << endl;
    //double radius = scaling * (side_length/2.0);

    int radius = fmod(rand(), half);

    cout << "The radius of the circle is: " << radius << endl;

    double circ_A = radius * radius * 3.14;

    double squ_A = side_length * side_length;

    double prob = circ_A / squ_A; 

    cout << "The probability of landing in the circle is " << prob << endl;

}

int main()
{
    double side_length;

    cout << "Enter side length:" << endl;
    cin >> side_length;

    newRad(side_length);
}