/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-09-22 15:31:44
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-09-22 15:37:36
 * @FilePath: \CODE\C++(2)\1035\1035.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;

int main()
{
    int n;
    double sum1;
    const int a = 9;
    cin >> n;
    if (n <= 3)
    {
        sum1 = a;
        cout << sum1 << endl;
    }
    else
    {
        sum1 = a + 2 + (n - 3) * 2.4;
        cout << sum1 << endl;
    }

    return 0;
}