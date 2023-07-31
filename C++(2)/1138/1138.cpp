#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14

class shape
{

public:
    shape() {}
    virtual double area() {}
};

class circle : public shape
{
private:
    double radius;

public:
    circle(double r)
    {
        radius = r;
    }
    virtual double area()
    {
        return PI * radius * radius;
    }
};

class triangle : public shape
{
private:
    double A, B, C;

public:
    triangle(double a, double b, double c)
    {
        A = a;
        B = b;
        C = c;
    }
    virtual double area()
    {
        double p = (A + B + C) / 2;
        return sqrt(p * (p - A) * (p - B) * (p - C));
    }
};

int main()
{
    double r, a, b, c;
    cin >> r >> a >> b >> c;
    circle A(r);
    triangle B(a, b, c);
    cout << A.area() << ' ';
    cout << B.area() << endl;
    return 0;
}