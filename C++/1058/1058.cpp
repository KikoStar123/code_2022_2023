/*
 * @Author: your name
 * @Date: 2022-05-03 16:38:15
 * @LastEditTime: 2022-05-03 16:51:16
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1058\1058.cpp
 */
#include <iostream>
using namespace std;
int QF(int n)
{
    int temp = n;
    int i = 2;
    cout << n << "=";
    while (temp != 1)
    {
        while (temp % i == 0)
        {
            temp = temp / i;
            if (temp != 1)
                cout << i << "*";
            else
                cout << i << endl;
        }
        i++;
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    QF(n);
}