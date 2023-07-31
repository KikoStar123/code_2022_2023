/*
 * @Author: your name
 * @Date: 2022-04-19 15:06:48
 * @LastEditTime: 2022-04-19 15:12:52
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1080\1080.cpp
 */
#include <iostream>
using namespace std;
int main()
{
    int a[3][5];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> a[i][j];
        }
        a[i][5] = 0;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            a[i][4 - j] = a[i][3 - j];
        }
        a[i][0] = a[i][4];
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}