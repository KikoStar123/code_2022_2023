/*
 * @Author: your name
 * @Date: 2022-04-18 14:12:36
 * @LastEditTime: 2022-04-18 14:43:23
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1054\1054.cpp
 */
#include <iostream>
using namespace std;
int main()
{
    int count = 0, sum = 0;
    int i = 0;
    int result = 0;
    cin >> count;
    for (int k = count / 2; k > 0; k--)
    {
        i = k;
        while (sum <= count)
        {
            sum = sum + i;
            i++;
            if (sum == count)
            {
                for (int j = k; j < i; j++)
                {
                    cout << j << " ";
                }
                cout << endl;
            }
        }
        sum = 0;
    }

    return 0;
}