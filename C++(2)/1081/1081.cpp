#include <iostream>
using namespace std;

void Str_Rotate(int (*s1)[3])
{
    int b[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            b[i][j] = s1[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            s1[j][2 - i] = b[i][j];
        }
    }
}

int main()
{
    int a[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    }
    Str_Rotate(a);
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}