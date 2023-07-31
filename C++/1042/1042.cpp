/*
 * @Author: your name
 * @Date: 2022-04-12 15:13:11
 * @LastEditTime: 2022-04-12 15:17:40
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1042\1042.cpp
 *
 * 题目描述
从键盘输入一串包含数字和其他字符的符号，以回车符为终止标记，统计其中数字字符的个数。

如输入ab12CD34###，则输出总数是4个。

注：输入字符串，可以对单个字符变量不断重复的输入，并判断该次输入的字符是否符合要求，否则终止循环。

输入
一行字符串，以回车符终止。

输出
字符串当中数字字符的个数
 */

#include <iostream>
using namespace std;
int main()
{
    char c = cin.get(); //获得回车符号//循环的初始条件
    int count = 0;
    while (c != '\n')
    {
        if (c >= '0' && c <= '9') //循环任务
            ++count;
        c = cin.get(); //修正条件
    }
    cout << count << endl;
    return 0;
}