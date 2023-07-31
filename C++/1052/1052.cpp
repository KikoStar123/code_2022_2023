/*
 * @Author: your name
 * @Date: 2022-04-12 14:25:12
 * @LastEditTime: 2022-04-14 13:39:55
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1052\1052.cpp
 */
#include <iostream>
using namespace std;
int main()
{
    int sum = 0;
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    bool flag = true;
    while (flag)
    {
        a += 5;
        e = 0;
        while (flag)
        {
            e += 4;
            d = e + a / 5;
            c = d + e / 4;
            if (d % 3 != 0)
                continue;
            if (c % 2 != 0)
                continue;
            b = c + d / 3;
            if (b + c / 2 == a)
                flag = false;
            if (b + c / 2 > a)
                break;
        }
    }
    sum = 2 * a + b;
    cout << sum << endl;
    cout << a << " " << b << " " << c << " " << d << " " << e << endl;
    return 0;
}