/*
 * @Author: KIKOSTAR 842544563@outlook.com
 * @Date: 2023-04-26 18:57:08
 * @LastEditors: KIKOSTAR 842544563@outlook.com
 * @LastEditTime: 2023-04-26 19:17:36
 * @FilePath: \CODE\C++(3)\A1参考代码.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class MyTime
{
    int hour, minute, second;

public:
    MyTime(int h = 0, int m = 0, int s = 0) // 默认构造函数
    {
        hour = h, minute = m, second = s;
    }
    void print()
    {
        cout << hour << ':' << minute << ':' << second << endl;
    }
    bool operator<(const MyTime &my)
    {
        // 请完成函数代码编写
        return hour * 3600 + minute * 60 + second <
               my.hour * 3600 + my.minute * 60 + my.second;
    }
};

class TimeArray
{
    MyTime *arr;
    int len;
    int count;

public:
    TimeArray(int l)
    {
        len = l;
        arr = new MyTime[len];
        count = 0;
    }
    ~TimeArray() { delete[] arr; }//错误5
    TimeArray(const TimeArray &ta)
    {
        len = ta.len, count = ta.count;
        arr = new MyTime[len];
        for (int i = 0; i < count; ++i)
            arr[i] = ta.arr[i];
    }
    TimeArray &operator=(const TimeArray &ta)
    {
        if (this == &ta)
            return *this;
        delete[] arr;
        len = ta.len, count = ta.count;
        arr = new MyTime[len];
        for (int i = 0; i < count; ++i)
            arr[i] = ta.arr[i];
        return *this;
    }
    void print()
    {
        for (int i = 0; i < count; ++i)
            arr[i].print();
    }
    void append(const MyTime &my)
    {
        arr[count++] = my;
    }
    void sort()
    {
        int i, j;
        for (i = 0; i < count - 1; ++i)
            for (j = count - 1; j > i; --j)
                if (arr[j] < arr[j - 1])
                    std::swap(arr[j], arr[j - 1]);
    }
};

int main()
{
    TimeArray ta(10);
    ta.append(MyTime(18, 10, 40));
    ta.append(MyTime(10, 20, 40));
    ta.append(MyTime(8, 30, 40));
    ta.append(MyTime(0, 0, 0));
    ta.append(MyTime(23, 59, 59));
    ta.sort();
    ta.print();
}