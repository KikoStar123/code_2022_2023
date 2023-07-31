/*
 * @Author: your name
 * @Date: 2022-03-30 17:05:34
 * @LastEditTime: 2022-04-12 14:18:32
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1171\1171.cpp
 */
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    int a[200];
    int length[200];
    int count = 0;
    int maxkim = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        length[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == a[i + 1] - 1)
        {
            length[count]++;
        }
        else
        {
            count++;
        }
    }

    length[count] = 0;
    maxkim = length[0];
    for (int i = 0; i < count; i++)
    {
        if (length[i] > maxkim)
            maxkim = length[i];
    }
    cout << maxkim << endl;
} // namespace std
