/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-12-14 14:59:48
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-12-15 13:12:50
 * @FilePath: \CODE\C++(2)\1083.cpp\1083.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int **a1 = new int *[N + 2];

    for (int i = 0; i < N + 2; i++)
        a1[i] = new int[N + 2];

    int **b = new int *[N + 2];
    for (int i = 0; i < N + 2; i++)
        b[i] = new int[N + 2];

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            cin >> a1[i][j];
            b[i][j] = 0;
        }
    }

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            if (a1[i][j] != 1)
            {
                for (int k1 = 0; k1 < 3; k1++)
                {
                    for (int k2 = 0; k2 < 3; k2++)
                    {
                        if (k1 == 1 && k2 == 1)
                            continue;
                        if (a1[i - 1 + k1][j - 1 + k2] == 1)
                            b[i][j]++;
                    }
                }
            }
        }
    }

    cout << endl;

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            if (b[i][j] == 0)
                cout << '*' << ' ';
            else
                cout << b[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}