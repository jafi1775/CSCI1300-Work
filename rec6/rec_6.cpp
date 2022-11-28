#include <iostream>
using namespace std;

void swap(int myArray[], int startIndex, int endIndex)
{
    int x = myArray[startIndex];
    myArray[startIndex] = myArray[endIndex];
    myArray[endIndex] = x;
    
    return;
}

void reverseArray(int myArray[], int arrayLength)
{
    for (int i=0; i<= arrayLength/2; i++)
    {
        swap(myArray, i, arrayLength - i -1);
    }

    return;

}

int main()
{
    int arrayLength;
    cout << "Please enter the size of the array:" << endl;
    cin >> arrayLength;
    int myArray[arrayLength];
    cout << "Please enter the elements of the array:" << endl;
    cin.getline(myArray, arrayLength);

    cout << "The reversed array:" << reverseArray(myArray, arrayLength) << endl;

    return 0;
}