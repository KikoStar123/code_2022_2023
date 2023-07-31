/*
 * @Author: your name
 * @Date: 2022-04-19 15:36:52
 * @LastEditTime: 2022-04-19 16:13:18
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1082\1082.cpp
 */
#include <iostream>
using namespace std;
int main()
{
    int a[11][11] = {1};
    int n = 0, i = 1, j = 1;
    int num = 1;
    bool flag[11][11] = {false};
    bool exit = false;
    int direction = 1;
    cin >> n;
    int count = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            flag[i][j] = true;
    }

    while (!exit)
    {
        if (direction == 1)
        {
            while (flag[i][j])
            {
                a[i][j] = num;
                flag[i][j] = false;
                num++;
                j++;
            }
            j--;
            i++;
            direction = 2;
        }
        if (direction == 2)
        {
            while (flag[i][j])
            {
                a[i][j] = num;
                flag[i][j] = false;
                num++;
                i++;
            }
            i--;
            j--;
            direction = 3;
        }
        if (direction = 3)
        {
            while (flag[i][j])
            {
                a[i][j] = num;
                flag[i][j] = false;
                num++;
                j--;
            }
            j++;
            i--;
            direction = 4;
        }
        if (direction = 4)
        {
            while (flag[i][j])
            {
                a[i][j] = num;
                flag[i][j] = false;
                num++;
                i--;
            }
            i++;
            j++;
            direction = 1;
        }
        if (num == n * n + 1)
            exit = true;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}