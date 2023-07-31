/*
 * @Author: your name
 * @Date: 2022-03-30 11:59:19
 * @LastEditTime: 2022-03-30 12:16:16
 * @LastEditors: Please set LastEditors
 * @Description: ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1165\1165.cpp
 */
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    int x1, x2, x3, x4;
    x1 = x2 = x3 = x4 = 0;
    cin >> a;
    b = a % 2;
    if (b == 0 && a > 4 && a <= 12)
    {
        x1 = 1;
    }
    else
    {
        x1 = 0;
    }

    if (b == 0 || (a > 4 && a <= 12))
    {
        x2 = 1;
    }
    else
    {
        x2 = 0;
    }

    if ((b != 0 && a > 4 && a <= 12) || (b == 0 && a <= 4 && a > 12))
    {
        x3 = 1;
    }
    else
    {
        x3 = 0;
    }

    if (b == 0 && a > 4 && a <= 12)
    {
        x4 = 0;
    }
    else
    {
        x4 = 1;
    }
    cout << x1 << " " << x2 << " " << x3 << " " << x4 << endl;
    return 0;
} // namespace std
