/*
 * @Author: your name
 * @Date: 2022-04-12 14:20:30
 * @LastEditTime: 2022-04-12 14:23:31
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1051\1051.cpp
 */
#include <iostream>
using namespace std;
int main()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            for (int k = 1; k <= 4; k++)
            {
                if (i != j && j != k && i != k)
                {
                    cout << i * 100 + j * 10 + k << endl;
                }
            }
        }
    }

    return 0;
}