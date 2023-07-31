/*
 * @Author: your name
 * @Date: 2022-04-19 16:24:42
 * @LastEditTime: 2022-04-19 18:01:22
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1083\1083.cpp
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> a(11, vector<int>(11, 0));
    vector<vector<string>> b(11, vector<string>(11, "*"));
    int n, count = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            b[i][j] = '*';
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 0)
            {
                for (int k = i - 1; k <= i + 1; k++)
                {
                    for (int z = j - 1; z <= j + 1; z++)
                    {
                        if (a[k][z] == 1)
                            count++;
                    }
                }
                b[i][j] = static_cast<char>(count + '0');
                count = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}