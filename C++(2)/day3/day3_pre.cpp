/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-18 19:20:24
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-11-10 20:11:53
 * @FilePath: \CODE\C++(2)\day3\day3_pre.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    srand((unsigned int)time(NULL));
    int shudu[10][10] = {0}, r, c, temp, ge, shu, sum = 0;
    bool used[10][10][3] = {0}, usedshu[10][10][10] = {0}, flag = 0; // 0横1竖2方格
    for (r = 1; r <= 9; r++)
    {
        for (c = 1; c <= 9; c++)
        {
            do
                temp = (rand() % (9)) + 1;
            while (usedshu[r][c][temp]);
            ge = (r - 1) / 3 * 3 + (c - 1) / 3 + 1;
            if (!(used[r][temp][0] || used[c][temp][1] || used[ge][temp][2]))
            {
                shudu[r][c] = temp;
                used[r][temp][0] = 1;
                used[c][temp][1] = 1;
                used[ge][temp][2] = 1;
                usedshu[r][c][temp] = 1;
            }
            else
            {
                usedshu[r][c][temp] = 1;
                flag = 1;
                while (flag)
                {
                    for (shu = 1; shu <= 9; shu++)
                    {
                        if (usedshu[r][c][shu])
                            sum++;
                    }
                    if (sum == 9)
                    {
                        for (shu = 1; shu <= 9; shu++)
                        {
                            usedshu[r][c][shu] = 0;
                        }
                        c--;
                        if (c == 0)
                        {
                            c = 9;
                            r--;
                            temp = shudu[r][c];
                            used[r][temp][0] = 0;
                            used[c][temp][1] = 0;
                            used[ge][temp][2] = 0;
                        }
                        temp = shudu[r][c];
                        ge = (r - 1) / 3 * 3 + (c - 1) / 3 + 1;
                        used[r][temp][0] = 0;
                        used[c][temp][1] = 0;
                        used[ge][temp][2] = 0;
                        shudu[r][c] = 0;
                    }
                    else
                    {
                        flag = 0;
                    }
                    sum = 0;
                }
                c--;
            }
        }
    }
    for (r = 1; r <= 9; r++)
    {
        for (c = 1; c <= 9; c++)
        {
            cout << shudu[r][c];
        }
        cout << endl;
    }
    return 0;
}
