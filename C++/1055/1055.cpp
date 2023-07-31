/*
 * @Author: your name
 * @Date: 2022-05-03 15:33:10
 * @LastEditTime: 2022-05-03 16:15:12
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1055\1055.cpp
 */
#include <iostream>
#include <cmath>
using namespace std;
double ex(double x)
{
    double sum = 0;
    double i = 1.0;
    double temp = 1.0;
    while (temp > 1e-6)
    {
        sum += temp;
        temp = temp * x / i;
        i = i + 1.0;
    }
    return sum;
}

int main()
{
    double x = 0;
    cin >> x;
    x = ex(x);
    cout << x << endl;
    return 0;
}