/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-09-22 14:33:19
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-09-22 14:40:29
 * @FilePath: \CODE\C++(2)\1032\1032.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%A
 */
#include <iostream>
using namespace std;
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    if (n >= 3 && n <= 5)
        cout << "spring" << endl;
    else if (n >= 6 && n <= 8)
        cout << "summer" << endl;
    else if (n >= 9 && n <= 11)
        cout << "autumn" << endl;
    else if (n == 12 || n == 1 || n == 2)
        cout << "winter" << endl;
    else
        cout << "bad" << endl;
    return 0;
}