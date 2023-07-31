/*
 * @Author: your name
 * @Date: 2022-05-03 16:54:39
 * @LastEditTime: 2022-05-03 17:48:47
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1059\1059.cpp
 */
#include <iostream>
using namespace std;
int race(int time)
{
    int t = 0;
    int rabbit = 0, tortoise = 0;
    int t2 = 0;
    int t3 = 0;
    bool flag = true;
    int n = 0;

    for (int i = 1; i <= time; i++)
    {
        if (flag)
            rabbit += 9;
        tortoise += 3;
        if (i % 10 == 0 && flag)
        {
            if (rabbit > tortoise)
            {
                n = 0;
                flag = false;
            }
        }
        if (!flag)
        {
            if (n == 30)
            {
                flag = true;
                n = 0;
            }
            n++;
        }
    }

    cout << rabbit << " " << tortoise << endl;
    return 0;
}
int main()
{
    int time = 0;
    cin >> time;
    race(time);
    return 0;
}