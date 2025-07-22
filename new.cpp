#include<iostream>
using namespace std;

class BasicShape {
private:
    double area;
public:
    double getArea() const {return area};
    virtual void calcArea() = 0;

};

class Circle : public BasicShape {
private:
    long centerX;
    long centerY;
    double radius;
public:
    Circle(long X, long Y, double r) : centerX(X), centerY(Y), radius(r), BasicShape() {};
    void calcArea() {
        area = radius * radius * 3.14159;
    };

};