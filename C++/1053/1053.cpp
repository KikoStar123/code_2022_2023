/*
 * @Author: your name
 * @Date: 2022-04-14 13:49:15
 * @LastEditTime: 2022-04-14 15:18:26
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1053\1053.cpp
 */
#include <iostream>
using namespace std;
int temp1 = 0, temp2 = 0;
int list1[5] = {0};
int list2[8] = {0};
bool check = true;
bool flag = false;
int n = 1;
int comparelists(int k)
{
    for (int i = 0; i < n; i++)
    {
        if (list1[i] == list2[i] && list1[i] != 0)
            flag = true;
        else
        {
            flag = false;
            break;
        }
    }
    return 0;
}

int digit(int i)
{
    temp2 = temp1;
    while (check)
    {
        temp2 = temp2 / 10;
        if (temp2 != 0)
            n++;
        else
            check = false;
    }
    return 0;
}

int main()
{
    for (int i = 0; i < 10000; i++)
    {
        n = 1;
        temp1 = i;
        for (int j = 0; j < 4; j++)
        {
            list1[j] = temp1 % 10;
            temp1 = temp1 / 10;
        }
        temp1 = i * i;
        for (int j = 0; j < 8; j++)
        {
            list2[j] = temp1 % 10;
            temp1 = temp1 / 10;
        }
        temp1 = i;
        digit(n);
        check = true;
        comparelists(n);
        if (flag)
            cout << i << endl;
        flag = false;
    }

    return 0;
}