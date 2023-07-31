/*
 * @Author: your name
 * @Date: 2022-04-14 08:54:20
 * @LastEditTime: 2022-04-14 09:16:52
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1167\1167.2.cpp
 */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int x, n;
    cin >> x >> n;
    int desitance = 0;
    desitance = (n / 7) * 1250;
    n = n % 7;
    desitance = desitance + n * 250;
    if (x <= 6 && 6 <= x + n - 1)
        desitance = desitance - 250;
    if (x <= 7 && 7 <= x + n - 1)
        desitance = desitance - 250;
    cout << desitance << endl;
    return 0;
}