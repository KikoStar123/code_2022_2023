#include <iostream>
#include <cmath>
using namespace std;

class Triangle
{
private:
    double a, b, c, length, area;
    int type;

public:
    Triangle(double A = 0.0, double B = 0.0, double C = 0.0)
    {
        a = A;
        b = B;
        c = C;
        type = Sort();
        area = Size();
        length = Circumference();
    }

    int Sort()
    {
        if (((a + b) <= c) || ((b + c) <= a) || ((a + c) <= b))
            return 0;
        if (a == b && b == c)
            return 1;
        if ((a == c && (a * a + c * c == b * b)) || (a == b && (a * a + b * b == c * c)) || (c == b && (c * c + b * b == a * a)))
            return 2;
        if ((a == c && a != b) || (a == b && a != c) || (b == c && c != a))
            return 3;
        if ((a * a + c * c == b * b) || (a * a + b * b == c * c) || (c * c + b * b == a * a))
            return 4;
        return 5;
    }

    double Circumference()
    {
        if (type == 0)
            return 0;
        return (a + b + c);
    }

    double Size()
    {
        if (type == 0)
            return 0;
        double p = (a + b + c) / 2;
        return (sqrt((p) * (p - a) * (p - b) * (p - c)));
    }

    bool operator<(Triangle a)
    {
        if (area < a.area)
            return true;
        return false;
    }
    bool operator>(Triangle a)
    {
        if (area > a.area)
            return true;
        return false;
    }
    void print()
    {
        cout << a << " " << b << " " << c << " " << length << " " << area << " " << type << endl;
    }
};

int main()
{
    int a1, a2, a3, b1, b2, b3;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    Triangle A(a1, a2, a3);
    Triangle B(b1, b2, b3);
    A.print();
    B.print();
    if (A < B)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    if (A > B)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}