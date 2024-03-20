#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

enum collor{
    red, blue, green, yellow
};

double Pi = 3.14;

struct coords
{
    double x = 0;
    double y = 0;
};

class ShapeSample
{
protected:
    coords center;
    int collor = -1;
    double dotLine_len = 0;
    double square = 0;

public:
    void showInfo() const{
        cout << "\nCurrent shape parameters:" << endl <<
            "Collor: " << this->collor << endl <<
            "Dot line length: " << this->dotLine_len << endl <<
            "Square: " << this->square << endl;
    }
};


class Circle: public ShapeSample
{
private:
    double radius = 0;

public:
    explicit Circle(double inRadius): radius(inRadius)
    {
        assert(inRadius > 0);
        this->collor = collor::red;
        square = Pi * pow(radius, 2);
        dotLine_len = radius * 2 * 4;
    }

};


class Triangle: public ShapeSample
{
private:
    double edge = 0;

public:
    explicit Triangle(double inEdge): edge(inEdge)
    {
        assert(inEdge > 0);
        this->collor = collor::blue;
        square = pow(edge, 2) * sqrt(3) / 4;
        dotLine_len = edge * 4;
    }
};


class Rectangle: public ShapeSample
{
protected:
    double length = 0;
    double width = 0;

public:
    Rectangle(double inLength, double inWidth):
            length(inLength), width(inWidth)
    {
        assert(inLength > 0 && inWidth > 0);
        this->collor = collor::yellow;
        square = length * width;
        dotLine_len = length * 2 + width * 2;
    }
};


class Square: public Rectangle
{
private:
    double edge = 0;

public:
    explicit Square(double inEdge):
        edge(inEdge), Rectangle(inEdge, inEdge)
    {
        assert(inEdge > 0);
        this->collor = collor::green;
    }
};


int main()
{
    string input;
    while (input != "exit"){
        cout << "\nEnter command: ";
        cin >> input;
        if (input == "circle"){
            double inRadius = 0;
            cout << "\nEnter radius: ";
            cin >> inRadius;
            auto* circle = new Circle(inRadius);
            circle->showInfo();
            delete circle;

        }else if (input == "triangle"){
            double side = 0;
            cout << "\nEnter side length: ";
            cin >> side;
            auto* triangle = new Triangle(side);
            triangle->showInfo();
            delete triangle;

        }else if (input == "square"){
            double side = 0;
            cout << "\nEnter side length: ";
            cin >> side;
            auto* square = new Square(side);
            square->showInfo();
            delete square;

        }else if (input == "rectangle"){
            double inLength = 0, inWidth = 0;
            cout << "\nEnter length and width: ";
            cin >> inLength >> inWidth;
            auto* rectangle = new Rectangle(inLength, inWidth);
            rectangle->showInfo();
            delete rectangle;

        }else cout << "\nWrong command" << endl;
    }
}