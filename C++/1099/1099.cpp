/*
 * @Author: your name
 * @Date: 2022-04-21 11:15:16
 * @LastEditTime: 2022-04-21 12:11:33
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1099\1099.cpp
 */
#include <iostream>
#include "cow.h"
using namespace std;
int main()
{
    int weight = 0;
    cin >> weight;
    cow s1(weight, 0);
    s1.calculation();
    s1.output();
    cow s2(50, 0);
    s2.calculation();
    s2.output();
    return 0;
}