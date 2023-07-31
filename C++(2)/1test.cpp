/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-02-21 18:22:08
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-02-22 21:32:59
 * @FilePath: \CODE\C++(2)\期末test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*编写程序 1：包含所需使用的头文件（5 分）*/
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
#define N 100
void create_string(char str[]);
int is_even(char str[]);
int get_str(char strings[][11], char result[][11]);
int main()
{
    char strings[N][11], result[N][11];
    int n = 0, i;
    /*编写程序 2：创建文件流对象，并打开 txt 文件（5 分）*/
    ofstream ofile;
    ofile.open("d:\\log1.txt");
    /*编写程序 3：调用函数为数组 strings 中的各行赋值为随机字符串，再将数组内容分别
    输出到 console 窗口和 txt 文件（5 分）*/
    srand(time(0));
    for (i = 0; i < N; i++)
    {
        create_string(strings[i]);
        cout << strings[i] << ' ';
        ofile << strings[i] << ' ';
        if ((i + 1) % 5 == 0)
            cout << endl;
    }
    /*调用函数，在函数内统计符合条件的字符串的个数，并将字符串存入数组 result 中*/
    n = get_str(strings, result);
    /*编写程序 4：将统计结果分别输出到 console 窗口和 txt 文件（5 分）*/
    cout << n << endl;
    ofile << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << ' ';
        ofile << result[i] << ' ';
        if ((i + 1) % 5 == 0)
            cout << endl;
    }
    /*编写程序 5：关闭文件流（5 分）*/
    ofile.close();
    return 0;
}
/*编写程序 6：请在此处给出函数 create_string 的定义（25 分）*/
void create_string(char str[])
{
    int randnum = 0;
    randnum = rand() % 5 + 5;
    for (int i = 0; i < randnum; i++)
        str[i] = char('A' + rand() % 26);
    str[randnum] = '\0';
}
/*编写程序 7：请在此处给出函数 get_str 的定义（25 分）*/
int get_str(char strings[][11], char result[][11])
{
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        if (is_even(strings[i]) == 1)
        {
            int k = 0;
            while (strings[i][k] != '\0')
            {
                result[j][k] = strings[i][k];
                k++;
            }
            result[j][k] = '\0';
            j++;
        }
    }
    return j;
}
/*编写程序 8：请在此处给出函数 is_even 的定义（25 分）*/
int is_even(char str[])
{
    int j = 0;
    int evennum = 0;
    while (str[j] != '\0')
    {
        if (str[j] == 'A' || str[j] == 'E' || str[j] == 'I' || str[j] == 'O' || str[j] == 'U')
            evennum += 1;
        j++;
    }
    if (evennum % 2 == 0)
        return 1;
    else
        return 0;
}
