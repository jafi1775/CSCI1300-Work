#include <iostream>
using namespace std; 

double fertilize(double stock, double amount)
{
    double x;
    if (stock<amount)
    {
        string x = "Please enter a valid input.";
    }
    else 
    {
        x= stock-amount;
    }
    return x;
}

double restock(double stock, double amount)
{
    double x;
    x = amount + stock;
    return x;
}

int main()
{
    double stock = 100;
    double amount = 20.5;

    cout << restock(stock, amount) << endl;
    cout << fertilize (stock, amount) << endl;
}