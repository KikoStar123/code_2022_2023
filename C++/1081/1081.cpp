/*
 * @Author: your name
 * @Date: 2022-04-19 15:15:29
 * @LastEditTime: 2022-04-19 15:32:25
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1081\1081.cpp
 */
#include <iostream>
using namespace std;
int main()
{
    int a[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[2 - j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}