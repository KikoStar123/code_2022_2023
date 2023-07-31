#include <iostream>
using namespace std;
int adjoin2(int a, int b)
{
    cout << a << b << endl;
    return 0;
}
int adjoin(int a, int b)
{
    int i = 0;
    int b1 = b;
    while (b != 0)
    {
        b /= 10;
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        a *= 10;
    }
    return a + b1;
}

int adjoin3(int a, int b)
{
    int temp = b;
    do
    {
        a *= 10;
        b /= 10;

    } while (b);
    return a + temp;
}

int main()
{
    int a, b;
    cin >> a >> b;
    // cout << adjoin(a, b) << endl;
    cout << adjoin3(a, b) << endl;
    int i, j;
    i = 4 * 5, i * 5, i + 25;
    cout << i;
    return 0;
}