#include <iostream>
using namespace std;

// Abstract base class
class Shape {
public:
    virtual double area() = 0;   // pure virtual function
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) { radius = r; }
    double area() { return 3.14159 * radius * radius; }
};

class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l, double w) { length = l; width = w; }
    double area() { return length * width; }
};

class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) { base = b; height = h; }
    double area() { return 0.5 * base * height; }
};

int main() {
    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(3, 8);

    Shape* s;   // base class pointer

    s = &c;
    cout << "Circle area: " << s->area() << endl;

    s = &r;
    cout << "Rectangle area: " << s->area() << endl;

    s = &t;
    cout << "Triangle area: " << s->area() << endl;

    return 0;
}