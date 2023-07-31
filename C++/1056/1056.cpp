/*
 * @Author: your name
 * @Date: 2022-05-03 16:16:45
 * @LastEditTime: 2022-05-03 16:36:12
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1056\1056.cpp
 */
#include <iostream>
using namespace std;
double pai2()
{
    double pi = 1;
    double i = 1;
    double temp = 1;
    while (temp > 1e-6)
    {
        temp = temp * i / (2 * i + 1);
        pi += temp;
        i++;
    }
    return (pi * 2);
}
double pai()
{
    double pi = 0;
    bool flag = true;
    double i = 1;
    double temp = 1;
    while (temp > 1e-6)
    {
        temp = 1 / (2 * i - 1);
        if (flag)
        {
            pi += temp;
            flag = false;
            i++;
            continue;
        }
        if (!flag)
        {
            pi -= temp;
            flag = true;
            i++;
            continue;
        }
    }
    return (pi * 4);
}
int main()
{
    // cout << pai() << endl;
    cout << pai2() << endl;
    return 0;
}