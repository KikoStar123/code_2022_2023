/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-11-20 11:17:08
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-11-20 12:44:53
 * @FilePath: \CODE\C++(2)\1150\1150.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%A
 */
#include <iostream>
using namespace std;
int list[5][5];

int output(int y, int x, int temp)
{
    cout << x << " " << y << " " << temp << endl;
    return 0;
}
int main()
{
    bool flag = true;
    int temp = 0;
    int x_index[5] = {0, 0, 0, 0, 0};
    int y_index[5] = {0, 0, 0, 0, 0};
    int x, y;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> list[i][j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        temp = list[i][0];
        x = 0;
        for (int j = 1; j < 5; j++)
        {
            if (list[i][j] > temp)
            {
                temp = list[i][j];
                x = j;
            }
        }
        x_index[i] = x;
    }

    for (int i = 0; i < 5; i++)
    {
        int x1 = x_index[i];
        temp = list[0][x1];
        for (int j = 1; j < 5; j++)
        {
            if (list[j][x1] < temp)
            {
                temp = list[j][x1];
                y = j;
            }
        }
        y_index[i] = y;
        if (temp == list[i][x_index[i]])
        {
            output(x_index[i] + 1, y + 1, temp);
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "not found" << endl;
    return 0;
}