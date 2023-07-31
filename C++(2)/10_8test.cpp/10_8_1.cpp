/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-08 15:54:00
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-08 16:28:28
 * @FilePath: \CODE\C++(2)\10_8test.cpp\10_8_1.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// 2.2 2.4
#include <iostream>
using namespace std;
double T2_2(double x);
double T2_4(double y);
int main()
{
    double x;
    cout << "x:";
    cin >> x;
    cout << "y=" << T2_2(x) << endl;
    cout << "YOUR SALARY IS:" << endl;
    double y;
    cin >> y;
    cout << "TAX IS:" << T2_4(y - 1000);
    return 0;
}
double T2_2(double x)
{
    if (x < 1)
        return x;
    if (x >= 1 && x <= 10)
        return (2 * x - 1);
    if (x >= 10)
        return (3 * x - 11);
    return 0;
}
double T2_4(double y)
{
    double salary = y;
    if (salary <= 0)
        return 0;
    if (salary <= 500)
        return (salary * 0.05);
    if (salary <= 2000)
        return (T2_4(500) + (salary - 500) * 0.10);
    if (salary <= 5000)
        return (T2_4(2000) + (salary - 2000) * 0.15);
    if (salary <= 20000)
        return (T2_4(5000) + (salary - 5000) * 0.20);
    if (salary <= 40000)
        return (T2_4(20000) + (salary - 20000) * 0.25);
    if (salary <= 60000)
        return (T2_4(40000) + (salary - 40000) * 0.30);
    if (salary <= 80000)
        return (T2_4(60000) + (salary - 60000) * 0.35);
    if (salary <= 100000)
        return (T2_4(80000) + (salary - 80000) * 0.40);
    if (salary > 100000)
        return (T2_4(100000) + (salary - 100000) * 0.45);
    return 0;
}