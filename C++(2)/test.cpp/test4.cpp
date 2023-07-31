/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-11-03 22:53:32
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-11-03 22:54:43
 * @FilePath: \CODE\C++(2)\test.cpp\test4.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std; //错误2

int main(void) //错误1
{
    int x, a, s = 0, t = 1; // a代表每次输入的系数, t是用来递推的通项
    int n, i;
    cout << "请输入实数x：";
    cin >> x; //错误3
    // 补充完善 1：输入合法性检查，确保n大于0 begin

    // 输入合法性检查 end
    cin >> a; //第一个系数被忽略
    for (i = 1; i <= n; ++i)//错误4
    // 补充完善 2：用递推算法求出s
    {
    }
    //补充完善2 end
    cout << "f'(" << x << ")=" << s << endl;
}
