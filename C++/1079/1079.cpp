/*
 * @Author: your name
 * @Date: 2022-04-19 14:44:22
 * @LastEditTime: 2022-04-19 14:58:48
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1079\1079.cpp
 */
#include <iostream>
using namespace std;

int main()
{
    int a[3][4];
    int sum1 = 0;
    int avg = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sum1 = sum1 + a[i][j];
        }
        avg = sum1 / 4;
        cout << avg << " ";
        sum1 = 0;
    }
    cout << endl;
    sum1 = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum1 = sum1 + a[j][i];
        }
        avg = sum1 / 3;
        cout << avg << " ";
        sum1 = 0;
    }
    cout << endl;
    return 0;
}