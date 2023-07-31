/*
 * @Author: KIKOSTAR 842544563@outlook.com
 * @Date: 2023-04-26 19:01:00
 * @LastEditors: KIKOSTAR 842544563@outlook.com
 * @LastEditTime: 2023-04-26 19:27:53
 * @FilePath: \CODE\C++(3)\test_4_26.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
// 本程序有5行代码有错误（每行可能不止一处），请修改，但不要添加或删除行
// 本程序有5段函数代码缺失，请补充
class MyTime
{
    int hour, minute, second;

public:
    MyTime(int h = 0, int m = 0, int s = 0) // 错误2
    {
        hour = h, minute = m, second = s;
    }
    void print()
    {
        cout << hour << ':' << minute << ':' << second << endl;
        // 完成本函数的代码，用来输出时间，格式见样例 10分
    }
    bool operator<(const MyTime &my)
    {
        int sum1, sum2;
        sum1 = 3600 * hour + 60 * minute + second;
        sum2 = 3600 * my.hour + 60 * my.minute + my.second;
        if (sum1 < sum2)
            return true;
        else
            return false;
        // 完成本符号重载函数的代码，用来比较两个时间 10分
    }
};

class TimeArray
{
    MyTime *arr; // 指向动态分配的数组
    int len;     // 动态数组的长度
    int count;   // 实际存入的元素个数

public:
    TimeArray(int l) // 错误1
    {
        len = l;
        arr = new MyTime[len];
        count = 0;
    }
    ~TimeArray() { delete arr; }
    TimeArray(const TimeArray &ta) // 错误3
    {
        len = ta.len, count = ta.count;
        arr = new MyTime[len];
        for (int i = 0; i < count; ++i)
            arr[i] = ta.arr[i];
    }
    TimeArray &operator=(const TimeArray &ta)
    {
        if (this == &ta) // 避免自身复制，本语句无误
            return *this;
        len = ta.len, count = ta.count;
        arr = new MyTime[len];
        for (int i = 0; i < count; ++i)
            arr[i] = ta.arr[i];
        return *this;
        // 补充完成本函数其余的代码 10分
    }
    void print()
    {
        for (int i = 0; i < count; ++i) // 错误4
            arr[i].print();
    }
    void append(const MyTime &my)
    {
        arr[count] = my;
        count++;
        // 完成本函数的代码，用来在数组尾部添加一个元素（可不考虑越界） 10分
    }
    void sort()
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = count - 1; j > i; j--)
            {
                if (arr[j] < arr[i])
                {
                    MyTime temp;
                    temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
    // 完成本函数的代码，用来对时间数组排序，方法不限 10分
};

int main()
{
    // main函数没有错误，请不要更动
    TimeArray ta(10);
    ta.append(MyTime(18, 10, 40));
    ta.append(MyTime(10, 20, 40));
    ta.append(MyTime(8, 30, 40));
    ta.append(MyTime(0, 0, 0));
    ta.append(MyTime(23, 59, 59));
    ta.sort();
    ta.print();
}
