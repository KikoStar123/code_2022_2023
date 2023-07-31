/*
 * @Author: kiko
 * @Date: 2022-03-31 08:50:53
 * @LastEditTime: 2022-03-31 09:27:50
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1084\1084.cpp
 */
#include <iostream>
using namespace std;
int main()
{
    int a[8];
    int b = 0;
    int c = 1;
    for (int i = 0; i < 7; i++)
    {
        cin >> a[i];
    }
    a[8] = a[7];
    for (int i = 0; i < 7; i++)
    {
        if (a[i + 1] <= a[i])
            b++;
        if (a[i + 1] == a[i])
            c++;
    }
    if (b == 7 && c != 7)
        cout << "DOWN" << endl;
    else if (c == 7)
        cout << "EQUAL" << endl;
    else
    {
        b = 1;
        for (int i = 0; i < 7; i++)
        {
            if (a[i] <= a[i + 1])
                b++;
        }
        if (b == 7)
            cout << "UP" << endl;
        else
            cout << "OTHER" << endl;
    }

    return 0;
}
