#include <iostream>
using namespace std;
float sqr(float a)
{
    return a * a;
}
float p(float x, int n)
{
    cout << "in-porcess:"
         << "x=" << x << '\t' << "n=" << n << endl;
    if (n == 0)
        return 1;
    else if (n % 2 != 0)
        return x * sqr(p(x, n / 2));
    else
        return sqr(p(x, n / 2));
}
int main()
{
    cout << p(2.0, 13) << endl;
    return 0;
}