#include <iostream>
using namespace std;


class Point2D
{
    private:

    double x;
    double y;
    string label;

    public:
    Point2D();
    Point2D(double input_x, double input_y, string input_label);
    double getX();
    double getY();
    string getLabel();
    void setX(double input_x);
    void setY(double input_y);
    void setLabel(string input_label);
    void print(double x, double y, string label);
    double distance(Point2D);
};
