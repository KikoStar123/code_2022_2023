/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-21 20:35:11
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-21 21:32:44
 * @FilePath: \CODE\C++(2)\10_21test.cpp\T2_14.CPP
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double xn = -2, t = 1;
    while (fabs(t) > 1e-5)
    {
        xn = (pow(xn, 2) - 10 * (xn * sin(xn) + cos(xn))) / (2 * xn - 10 * sin(xn));
        t = pow(xn, 2) + 10 * cos(xn);
    }
    cout << xn << endl;
    cout << 0 - xn << endl;
    return 0;
}