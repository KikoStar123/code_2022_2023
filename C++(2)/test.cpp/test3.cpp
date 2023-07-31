/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-20 16:04:48
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-20 20:10:06
 * @FilePath: \CODE\C++(2)\test.cpp\test3.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <cmath> //1
using namespace std;

#include <iostream>
#include <cmath> //1 math-cmath
using namespace std;

int main(void)
{
    int n, num = 1, i, j;    // num代表素数的个数
    int row = 1, column = 0; // row代表输出的行，column代表列
    // 补充完善 1：输入合法性检查 begin
FLAG:
    cout << "请输入一个20-50之间(包含20和50)的整数：";
    cin >> n;
    if (n < 20 || n > 50)
        goto FLAG;

    // 输入合法性检查 end
    int k = n;
    while (num <= 9)
    // 5 删除;
    {
        j = sqrt(n);

        for (i = 2; i <= j; i++) // 2 ,-;
        {
            if (n % i == 0) // 3 = - ==
                break;
        }
        if (i > j && n > k) // 4 n>k  //5 i>j
        {
            num++;
            // 补充完善2：按照三层三角形输出素数
            if (row == 1)
            {
                cout << n << '\t';
                row++;
                cout << endl;
                column = 0;
            }

            else if (row == 2)
            {
                cout << n << '\t';
                column++;
                if (column >= 3)
                {
                    row++;
                    cout << endl;
                    column = 0;
                }
            }

            else if (row == 3)
            {
                cout << n << '\t';
                column++;
                if (column >= 5)
                {
                    row++;
                    cout << endl;
                    column = 0;
                }
            }

            // 三层三角形输出素数 end
        }
        n++;
    }
}
