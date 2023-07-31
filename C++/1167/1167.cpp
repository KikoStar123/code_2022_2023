/*
 * @Author: kiko
 * @Date: 2022-03-30 12:28:55
 * @LastEditTime: 2022-03-30 13:11:00
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1167\1167.cpp
 */
#include <iostream>
using namespace std;
int main()
{
    /*int x, i, n, j, k;
    i = j = k = 0;
    cin >> x >> n;
    int temp;
    temp = 7 - x;
    i = (n - temp) % 7;
    j = (n - temp) / 7;
    k = j * 1250;
    if (temp >= 2)
    {
        j += (6 - x) * 250;
    }
    if (i <= 5)
    {
        j += i * 250;
    }
    else
    {
        j += 1250;
    }
    cout << j << endl;*/
    int x, i, n, j, k;
    int temp = 0;
    i = j = k = 0;
    cin >> x >> n;
    temp = 7 - x;
    i = n - temp;
    j = i / 7;
    temp = i % 7;
    k = k + j * 1250;
    if (temp < 6)
    {
        k = k + temp * 250;
    }
    else
        k = k + 1250;

    if (x < 6)
    {
        k = k + (6 - x) * 250;
    }
    cout << k;
    return 0;

} // namespace std;
