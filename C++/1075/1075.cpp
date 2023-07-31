/*
 * @Author: your name
 * @Date: 2022-04-18 15:51:57
 * @LastEditTime: 2022-04-18 16:00:51
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1075\1075.cpp
 */
#include <iostream>
using namespace std;

int main()
{
    int a[8];
    for (int i = 0; i < 7; i++)
        cin >> a[i];
    a[7] = a[6];
    for (int i = 0; i < 7; i++)
    {
        if (i % 2 == 0)
        {
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        }
        else if (a[i] < a[i + 1])
            swap(a[i], a[i + 1]);
    }
    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}