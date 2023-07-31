/*
 * @Author: your name
 * @Date: 2022-04-07 09:15:34
 * @LastEditTime: 2022-04-07 09:29:38
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1145\1145.cpp
 */
#include <iostream>
using namespace std;
int main()
{
    int list[20];
    int sum = 0;
    int day = 1;
    int inday = 0;
    int max = 0;
    for (int i = 0; i < 14; i++)
    {
        cin >> list[i];
    }
    for (int i = 0; i < 14; i = i + 2)
    {
        sum = list[i] + list[i + 1];
        if (sum > 8)
        {
            if (sum > max)
            {
                max = sum;
                inday = day;
            }
        }
        day++;
    }
    cout << inday << endl;
    return 0;
} // namespace std
