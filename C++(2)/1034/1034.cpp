/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-09-22 15:26:54
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-09-22 15:30:20
 * @FilePath: \CODE\C++(2)\1034\1034.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n % 3 == 0 && n % 5 == 0)
        cout << "A" << endl;
    if (n % 3 != 0 && n % 5 != 0)
        cout << "B" << endl;
    if (n % 3 == 0 && n % 5 != 0)
        cout << "C" << endl;
    if (n % 3 != 0 && n % 5 == 0)
        cout << "D" << endl;
    return 0;
}