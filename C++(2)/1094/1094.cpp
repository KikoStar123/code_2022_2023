/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-12-02 23:27:53
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-12-03 21:42:25
 * @FilePath: \CODE\C++(2)\1094\1094.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AEvo
 */
#include <iostream>
using namespace std;

char *ptrmove(char *c)
{
    char *temp = c;
    while (*c != '\0')
    {
        c++;
        *(c - 1) = *c;
    }
    return temp;
}

char *ptrdel(char *c, char delc)
{
    char *tempptr = c;
    while (*c != '\0')
    {
        if (*c == delc)
            c = ptrmove(c);
        else
            c++;
    }
    return tempptr;
}

int main()
{
    char c[200];
    cin.get(c, 200);
    char delc;
    cin >> delc;
    cout << ptrdel(c, delc) << endl;
    return 0;
}