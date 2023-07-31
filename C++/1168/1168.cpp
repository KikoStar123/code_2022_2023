/*
 * @Author: your name
 * @Date: 2022-03-30 16:24:58
 * @LastEditTime: 2022-03-30 16:43:43
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1168\1168.cpp
 */
#include <iostream>
using namespace std;
int main()
{
    int n, a[200], temp;
    cin >> n;
    temp = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j] >= a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    /*for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    */

    cout << a[0] << endl;

    return 0;
} // namespace std;
