/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-11-03 21:58:13
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-11-03 23:12:33
 * @FilePath: \CODE\C++(2)\test.cpp\s1122109.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std; //错误1
                     //输入实数x，输入整数n，依次循环输入n+1个实数系数a0～an
                     //用递推算法求出f(x) = a0 + a1x + a2x^2 + a3x^3 + ... + anx^n的导函数f'(x)值
                     //如x=2 n=3 a0~a3都是1 f(x)=1+x+x^2+x^3 f'(x)=1+2x+3x^2 则f'(2)=17
                     //如x=-2 n=4 a0~a4都是2 f(x)=2+2x+2x^2+2x^3+2x^4 f'(x)=2+4x+6x^2+8x^3 则f'(-2)=2-8+24-64=-46
int main(void)       //错误2
{
    int x, a, s = 0, t = 1; // a代表每次输入的系数, t是用来递推的通项
    int n = 0, i;           //错误5
    cout << "请输入实数x：";
    cin >> x; // 错误30a
    // 补充完善 1：输入合法性检查，确保n大于0 begin
    while (n <= 0)
    {
        cout << "请输入整数n：";
        cin >> n;
    }
    // 输入合法性检查 end
    cin >> a;                //第一个系数被忽略
    for (i = 1; i <= n; ++i) //错误4
    // 补充完善 2：用递推算法求出s
    {
        cin >> a;
        s = s + t * a;
        t = (i + 1) * x * t / i;
    }
    //补充完善2 end
    cout << "f'(" << x << ")=" << s << endl;
}
