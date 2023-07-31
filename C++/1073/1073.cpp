/*
 * @Author: your name
 * @Date: 2022-04-18 14:48:46
 * @LastEditTime: 2022-04-18 15:22:53
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1073\1073.cpp
 */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int a[10];
    int maxsize1, minsize1, avgsize1 = 0;
    int maxsize2, minsize2, avgsize2 = 0;
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
        if (a[i] < 0)
            maxsize2 = a[i];
    }
    maxsize1 = a[0], minsize1 = a[0], avgsize1 = 0;
    minsize2 = a[0], avgsize2 = 0;
    int sum1 = 0, sum2 = 0;
    double avg1 = 0, avg2 = 0;
    for (int i = 0; i < 10; i++)
    {
        if (a[i] >= 0)
        {
            maxsize1 = max(maxsize1, a[i]);
            minsize1 = min(minsize1, a[i]);
            sum1 = sum1 + a[i];
            avgsize1++;
        }
        else
        {
            maxsize2 = max(maxsize2, a[i]);
            minsize2 = min(minsize2, a[i]);
            sum2 = sum2 + a[i];
            avgsize2++;
        }
    }
    avg1 = double(sum1) / double(avgsize1);
    avg2 = double(sum2) / double(avgsize2);
    cout << maxsize1 << " " << minsize1 << " " << fixed << setprecision(5) << avg1 << " " << endl;
    cout << maxsize2 << " " << minsize2 << " " << fixed << setprecision(5) << avg2 << " " << endl;
    return 0;
}