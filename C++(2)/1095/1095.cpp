/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-12-02 21:25:34
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-12-08 16:23:10
 * @FilePath: \CODE\C++(2)\1095\1095.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * 
 */
#include <iostream>
using namespace std;

int strnumsum(const char *list)
{
    int sum = 0;
    bool conti = true;
    while (*list != '\0')
    { 

        int tempnum = 0;
        while (*list >= '0' && *list <= '9')
        {
            tempnum = tempnum * 10 + int(*list-48);
            list++;
            conti = false;
        }
        sum += tempnum;
        if (!conti)
        {
            list--;
            conti = true;
        }
        list++;
        
    }
    return sum;
}

int main()
{
    char c[200];
    cin.getline(c, 200);
    cout << strnumsum(c) << endl;
    return 0;
}