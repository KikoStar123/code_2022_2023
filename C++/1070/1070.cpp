/*
 * @Author: your name
 * @Date: 2022-03-30 16:57:20
 * @LastEditTime: 2022-03-30 17:03:39
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1070\1070.cpp
 */
#include <iostream>
using namespace std;
int main()
{
    int n, count;
    count = 1;
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (count < 10)
            {
                cout << 0 << count;
                count++;
            }
            else
            {
                cout << count;
                count++;
            }
        }
        cout << endl;
    }

    return 0;
} // namespace std;
