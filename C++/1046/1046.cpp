/*
 * @Author: your name
 * @Date: 2022-04-12 15:26:06
 * @LastEditTime: 2022-04-12 15:44:21
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1046\1046.cpp
 */
#include <iostream>
using namespace std;
int main()
{
    bool inword = true;
    char c;
    int count = 0;
    while (c != '\n')
    {
        c = cin.get();
        if (c >= 'A' && c <= 'z' && inword)
        {
            count++;
        }
        if (c == ' ')
            inword = true;
        else
            inword = false;
    }
    cout << count << endl;
    return 0;
}