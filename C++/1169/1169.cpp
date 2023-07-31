/*
 * @Author: kiko
 * @Date: 2022-03-30 16:44:48
 * @LastEditTime: 2022-03-30 16:56:36
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1169\1169.cpp
 */
//一尺之锤
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int count = 1;
    while (n != 1)
    {
        n = floor(n / 2);
        count++;
    }
    cout << count << endl;
    return 0;
} // namespace std;