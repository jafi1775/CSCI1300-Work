#include <iostream>

using namespace std;

int main()
{
    string user_input;
    int length;
    char char_value;

    cout << "Please enter a string." << endl;
    getline (cin,user_input);
    length = user_input.length();

    for (int i=0; i<length; i++)
    {
        char_value = int (user_input[i]);
      
        if (char_value >=97 && char_value<=122)
        {
            user_input[i]= char (char_value -32);
        }
        
    }
    cout << user_input << endl;

    return 0;
}