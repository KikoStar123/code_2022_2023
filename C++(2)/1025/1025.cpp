/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-09-25 17:18:59
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-13 21:50:20
 * @FilePath: \CODE\C++(2)\1025\1025.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c, p;
    double s;
    cin >> a >> b >> c;
    if (a + b > c && b + c > a && a + c > b)
    {
        p = (a + b + c) / 2.0;
        s = sqrt(p * (p - a) * (p - b) * (p - c));
        cout << s << endl;
    }
    return 0;
}