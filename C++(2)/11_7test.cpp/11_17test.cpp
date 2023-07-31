#include <iostream>
using namespace std;
double process(int n, double x)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n >= 1)
        return ((2 * n - 1) * x * process(n - 1, x) - (n - 1) * process(n - 2, x) / n);
}

int main()
{
    cout << process(4, 1.5) << endl;
    return 0;
}