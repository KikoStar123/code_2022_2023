/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-11-08 18:04:50
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-12-01 16:08:48
 * @FilePath: \CODE\C++(2)\test.cpp\test5.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;
int main()
{
    int x=5;
    int y=7;
    int z=8;
    z+=x++||y++||++z;
    cout<<z;
}