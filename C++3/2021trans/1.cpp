#include <iostream>
using namespace std;

template <typename T>
void two_smallest(T &a, T &b, T c)
{
    T temp1, temp2;
    if (a > b)
    {
        temp1 = b;
        if (a > c)
            temp2 = c;
        else
            temp2 = a;
    }
    else
    {
        temp1 = a;
        if (b > c)
            temp2 = c;
        else
            temp2 = b;
    }
    a = temp1;
    b = temp2;
}

int main()
{
    int a, b, c;
    char a1, b1, c1;
    cin >> a >> b >> c;
    two_smallest(a, b, c);
    cout << "the two smallest elements is:" << a << ' ' << b << endl;
    cin >> a1 >> b1 >> c1;
    two_smallest(a1, b1, c1);
    cout << "the two smallest elements is:" << a1 << ' ' << b1 << endl;
    return 0;
}