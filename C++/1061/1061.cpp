#include <iostream>
using namespace std;

double squaresum(double a, double b);
int main()
{
    double a, b;
    cin >> a >> b;
    cout << squaresum(a, b) << endl;
    return 0;
}
double squaresum(double a, double b)
{
    double c;
    c = a * a + b * b;
    return c;
}