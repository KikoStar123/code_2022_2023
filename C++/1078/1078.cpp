/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-04-19 14:11:59
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-11-27 23:14:51
 * @FilePath: \CODE\C++\1078\1078.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;

int main()
{
    int a[10][10];
    int N;
    int sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (N % 2 == 0)
            sum = sum + a[i][i] + a[i][N - 1 - i];
        else if (i == N - 1 - i)
        {
            sum = sum + a[i][i];
        }
        else
            sum = sum + a[i][i] + a[i][N - 1 - i];
    }
    cout << sum << endl;
}