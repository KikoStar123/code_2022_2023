#include <iostream>
using namespace std;

int f(int m, int n)
{
    if (m == 1 || n == 1)
        return 1;
    if (m < n)
        return (m, m);
    if (m == n)
        return (1 + f(m, m - 1));
    return f(m - n, n) + f(m, n - 1);
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << f(m, n) << endl;
    return 0;
}