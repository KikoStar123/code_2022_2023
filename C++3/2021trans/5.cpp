#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14

class Shape
{
public:
    Shape() {}
    virtual void get_area() {}
};

class TwoDimensionalShape : public Shape
{
public:
    TwoDimensionalShape() {}
    virtual void get_area() {}
};

class ThreeDimensionalShape : public Shape
{
public:
    ThreeDimensionalShape() {}
    virtual void get_area() {}
};

class Circle : public TwoDimensionalShape
{
private:
    double radius;

public:
    Circle(double r) { radius = r; }
    void get_area()
    {
        cout << "area:" << PI * radius * radius << endl;
    }
};

class Squre : public TwoDimensionalShape
{
private:
    double a;
    double b;

public:
    Squre(double a1, double b1)
    {
        a = a1;
        b = b1;
    }
    void get_area()
    {
        cout << "area:" << a * b << endl;
    }
};

class Triangle : public TwoDimensionalShape
{
private:
    double a, b, c;

public:
    Triangle(double a1, double b1, double c1)
    {
        a = a1;
        b = b1;
        c = b1;
    }
    void get_area()
    {
        double p = (a + b + c) / 2;
        cout << "area:" << sqrt(p * (p - a) * (p - b) * (p - c)) << endl;
    }
};

class Sphere : public ThreeDimensionalShape
{
private:
    double radius;

public:
    Sphere(double r)
    {
        radius = r;
    }

    void get_area()
    {
        cout << "area:" << 4.0 * PI * radius * radius << endl;
        cout << "volume:" << 0.75 * PI * radius * radius * radius << endl;
    }
};

class Cube : public ThreeDimensionalShape
{
private:
    double a, b, c;
    double v;

public:
    Cube(double a1, double b1, double c1)
    {
        a = a1;
        b = b1;
        c = c1;
        v = a * b * c;
    }

    void get_area()
    {
        cout << "area:" << 2 * (a * b + b * c + a * c) << endl;
        cout << "volume:" << v << endl;
    }
};

class Tetrahedron : public ThreeDimensionalShape
{
private:
    double a, b, c, a1, b1, c1;
    double v;

public:
    Tetrahedron(double a2, double b2, double c2, double a3, double b3, double c3)
    {
        a = a2;
        b = b2;
        c = c2;
        a1 = a3;
        b1 = b3;
        c1 = c3;
        v=sqrt(a * a * a1 * a1 * (-a * a - a1 * a1 + b * b + b1 * b1 + c * c + c1 * c1) +
                    b * b * b1 * b1 * (a * a + a1 * a1 - b * b - b1 * b1 + c * c + c1 * c1) +
                    c * c * c1 * c1 * (a * a + a1 * a1 + b * b + b1 * b1 - c * c - c1 * c1) -
                    (a * a * b * b * c * c + a1 * a1 * b1 * b1 * c1 * c1 + a * a * b1 * b1 * c1 * c1)) /
               12.0;
    }

    void get_area()
    {
        cout << "area:" << 0.5 * (a + b + c + a1 + b1 + c1) << endl;

        cout << "volume:" << v << endl;
    }
};

int main()
{
    Shape *Vector[20];
    Vector[0] = new Circle(2.5);
    Vector[1] = new Squre(2.5, 3.5);
    Vector[2] = new Triangle(3, 4, 5);
    Vector[3] = new Sphere(3);
    Vector[4] = new Cube(3, 4, 5);
    Vector[5] = new Tetrahedron(1, 1, 1, 1, 1, 1);

    for (int i = 0; i < 6; i++)
    {
        cout << i << ':' << ' ' << endl;
        Vector[i]->get_area();
    }

    return 0;
}