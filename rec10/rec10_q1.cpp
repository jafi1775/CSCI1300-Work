#include <iostream>
#include <vector>
using namespace std;


float average(vector<float> vec)
{

    float average = 0;

    for(int i = 0; i < 15; i ++)
    {
        average += vec.at(i);
    }

    average = average / 15.0;

    return average;


}


vector<float> newVec(vector<float> input, float average)
{
    int run = 15;
    for (int i = 0; i < run; i++)
    {
        if (input.at(i) < average)
        {
            input.erase(input.begin() + i);
            run--;
            i--;
        }
    }

    return input;

}


int main()
{
    vector<float> input;

    for (int i = 0; i < 15; i++)
    {
        float x = 0;
        if (i == 0)
        {
            cout << "Please input 15 positive decimal values:" << endl;
        }

        cin >> x;
        while ( x < 0.0)
        {
            cout << "Invalid input, please input another value." << endl;
            cin >> x;
        }

        input.insert(input.begin() + i, x);

    }

    float average_val;
    average_val = average(input);
    cout << average_val << " this is the average." << endl;

    vector<float> new_Vec = newVec(input, average_val);

    for (int i = 0; i < new_Vec.size(); i ++)
    {
        cout << new_Vec.at(i) << endl;
    }



    return 0;
}