/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-03-30 12:18:11
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-08 15:50:22
 * @FilePath: \CODE\C++\1166\1166.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;
int main()
{
    int list[3];
    int temp = 0;
    cin >> list[0] >> list[1] >> list[2];
    if (list[1] <= list[0])
    {
        temp = list[0];
        list[0] = list[1];
        list[1] = temp;
    }
    if (list[2] <= list[1])
    {
        temp = list[1];
        list[1] = list[2];
        list[2] = temp;
    }
    cout << list[0] << " " << list[1] << " " << list[2] << endl;
    return 0;
}
