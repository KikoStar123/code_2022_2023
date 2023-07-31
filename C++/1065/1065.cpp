#include <iostream>
using namespace std;
double cal(double n)
{
    double sum = 0;
    double j = 0.01;
    for (int i = 0; i < n; i++)
    {
        j *= 2;
        sum += j;
    }
    return sum;
}

long long money_sum(int n)
{
    long long s = 0, t = 1;
    for (int i = 1; i <= n; ++i)
    {
        s += t;
        t *= 2;
    }
    return s;
}

int main()
{
    int n = 30;
    double n1;
    cin >> n1;
    if (30 * n1 * 100 >= money_sum(30))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}