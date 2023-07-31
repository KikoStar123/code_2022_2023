/*
 * @Author: your name
 * @Date: 2022-04-18 15:28:26
 * @LastEditTime: 2022-04-18 15:50:33
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1074\1074.cpp
 */
#include <iostream>
using namespace std;
int main()
{
    int a[8];
    int temp;
    for (int i = 0; i < 7; i++)
    {
        cin >> a[i];
    }
    a[7] = 0;
    for (int j = 0; j < 7; j++)
    {
        for (int i = 0; i < 7; i++)
        {

            if (a[i] == 0)
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}