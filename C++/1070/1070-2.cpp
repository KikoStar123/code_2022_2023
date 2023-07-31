#include <iostream>
using namespace std;
double list(double n)
{
    if (n == 0)
        return 1;
    return (n / (2 * n + 1)) * list(n - 1);
}

int main()
{
    double i = 1;
    double pi = 1;
    while (list(i) > 1e-6)
    {
        pi += list(i);
        ++i;
    }
    cout << 2 * pi << endl;
    return 0;
}
