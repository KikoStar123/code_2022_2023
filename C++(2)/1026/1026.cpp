#include <iostream>
using namespace std;
int main()
{
    int a[3];
    int j = 0;
    cin >> j;
    for (int i = 0; i < 3; i++)
    {
        a[i] = j % 10;
        j = (j - a[i]) / 10;
    }
    for (int i = 0; i < 3; i++)
        cout << a[i];
    return 0;
}