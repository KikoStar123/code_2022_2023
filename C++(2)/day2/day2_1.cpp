#include <iostream>
using namespace std;
int main()
{
    int m, l, n = 0;
FLAG1:
    cout << "m=";
    cin >> m;
    cout << "l=";
    cin >> l;
    cout << "n=";
    cin >> n;
    if (m == 0 || l == 0 || n == 0)
        goto FLAG1;
    int **arry1 = new int *[m];
    for (int i = 0; i < m; i++)
        arry1[i] = new int[l];
    int **arry2 = new int *[l];
    for (int i = 0; i < l; i++)
        arry2[i] = new int[n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < l; j++)
            arry1[i][j] = rand() % 10;
    }
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < n; j++)
            arry2[i][j] = rand() % 10;
    }

    //输出两个矩阵的乘积
    int **arry = new int *[m];
    for (int i = 0; i < l; i++)
        arry[i] = new int[n];

    cout << "矩阵ml为:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cout << arry1[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "矩阵ln为:" << endl;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arry2[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = 0;
            for (int k = 0; k < l; k++)
            {
                x += arry1[i][k] * arry2[k][j];
            }
            arry[i][j] = x;
        }
    }
    cout << "矩阵乘积为:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arry[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}