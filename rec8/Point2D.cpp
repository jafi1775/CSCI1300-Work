#include <iostream>
#include <cmath>
#include "Point2D.h"

using namespace std;

Point2D :: Point2D()
{
    x = 0.0;
    y= 0.0;
    label = "";
}

Point2D :: Point2D(double input_x, double input_y, string input_label)
{
    x = input_x;
    y = input_y;
    label = input_label;
}

double Point2D :: getX()
{
    return x;
}

double Point2D :: getY()
{
    return y;
}

void Point2D :: setX(double input_x)
{
    x = input_x;
}

void Point2D :: setY(double input_y)
{
    y = input_y;
}

void Point2D :: setLabel(string input_label)
{
    label = input_label;
}

void Point2D :: print(double x, double y, string label)
{
    cout << label << ": (" << x << "," << y << ")" << endl;

}

double Point2D :: distance(Point2D)
{
    double x2, y2;

    x1 = x;

    y1 = y;

    double x2 = getX();

    double y2 = getY();




    double distance = sqrt((x1 - x2)^2 + (y1 - y2)^2);

    return distance;

}

int main()
{
    Point2D p; //calls the default constructor
    p.print(); 

    Point2D q(3, 4, "Q");
    q.print();

    Point2D r(-10, 4); //uses the parameterized constructor
    r.print();
    r.setLabel("R"); //can also use setters to update data members
    r.print();

    cout << "q.distance(): " << q.distance() << endl;
    cout << "r.distance(q): " << r.distance(q) << endl;


}