#include <iostream>
#include <cmath>
using namespace std;

class CVector
{
private:
    double a;
    double b;

public:
    CVector(double x, double y)
    {
        a = x;
        b = y;
    }

    double modulus()
    {
        return sqrt(a * a + b * b);
    }

    double operator*(CVector r)
    {
        return a * r.a + b * r.b;
    }
};

double
cos_distance(CVector v1, CVector v2)
{
    return ((v1 * v2) / (v1.modulus() * v2.modulus()));
}

int main()
{
    CVector A(1, 2);
    CVector B(-2, 1);
    cout << A.modulus() << endl;
    cout << B.modulus() << endl;
    cout << "A*B=" << A * B << endl;
    cout << "cos(A,B)=" << cos_distance(A, B) << endl;
    if (A * B == 0)
        cout << "垂直" << endl;
    if (A * B == 1)
        cout << "A and B is similar" << endl;
    return 0;
}