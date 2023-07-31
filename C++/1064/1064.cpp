#include <iostream>
#include <cmath>
using namespace std;
double mysqrt(double a)
{
    double left = 0, right = a;
    double temp = left + a / 2;
    while (fabs(temp * temp - a) > 1e-6)
    {
        if (temp * temp < a)
        {
            left = temp;
            temp = (left + right) / 2;
        }
        else
        {
            right = temp;
            temp = (left + right) / 2;
        }
    }
    return temp;
}

double mysqrt1(double x)
{
    if (x < 1)
        return (1.0 / mysqrt1(1.0 / x));
    else
    {
        double begin = 0, end = x, mid = (begin + end) / 2;
        double t = mid * mid - x;
        while (fabs(t) >= 1e-12)
        {
            if (t > 0)
                end = mid;
            else
                begin = mid;
            mid = (begin + end) / 2;
            t = mid * mid - x;
        }
        return mid;
    }
}
int main()
{
    double a;
    cin >> a;
    cout << mysqrt1(a) << endl;
}