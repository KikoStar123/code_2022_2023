/*
 * @Author: your name
 * @Date: 2022-04-18 16:01:43
 * @LastEditTime: 2022-04-18 16:11:21
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1076\1076.cpp
 */
#include <iostream>
using namespace std;
int main()
{
    int a[8];
    bool flag = false;
    for (int i = 0; i < 7; i++)
        cin >> a[i];
    a[7] = a[6] + 1;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
    for (int i = 0; i < 7; i++)
    {
        if (a[i] == a[i + 1])
            flag = true;
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}