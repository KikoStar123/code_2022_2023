/*
 * @Author: your name
 * @Date: 2022-04-18 16:12:09
 * @LastEditTime: 2022-06-14 16:47:24
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1077\1077.cpp
 */
#include <iostream>
using namespace std;

int main()
{
    int n;
     int a[10000] = {0};
    int k;
    int i = 0;
    cin >> n >> k;
    while (n != 0)
    {
        a[i] = n % k;
        n = n / k;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        switch (a[j])
        {
        case 10:
            cout << "A";
            break;
        case 11:
            cout << "B";
            break;
        case 12:
            cout << "C";
            break;
        case 13:
            cout << "D";
            break;
        case 14:
            cout << "E";
            break;
        case 15:
            cout << "F";
            break;
        default:
            cout << a[j];
        }
    }
    return 0;
}