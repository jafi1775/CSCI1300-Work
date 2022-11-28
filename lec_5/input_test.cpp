#include <iostream>

using namespace std;

int main(){
    // print prompt asking user for their favorite LETTER
    cout << "What is your favorite letter?";
    // get the input from the user
    char yourFavLetter;
    cin >> yourFavLetter;
    // print out their favorite letter
    
    cout << "Your favorite letter is: " << yourFavLetter << endl;

    // print out the INTEGER representation of their favorite letter 
    cout << "The integer representation of your favorite letter is " 
        << static_cast<int>(yourFavLetter) << endl;
    // (remember our friend, the ASCII table?)
    

    return 0;
}