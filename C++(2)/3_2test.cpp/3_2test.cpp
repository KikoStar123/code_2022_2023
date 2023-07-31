/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-03-02 22:44:44
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-03-02 23:27:39
 * @FilePath: \CODE\C++(2)\3_2test.cpp\3_2test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;

class Timedate
{
private:
    int hour, minute, second, day, year;
    int month;

public:
    Timedate(int i)
    {
        SetTime();
        Show();
    }
    Timedate()
    {
    }
    void SetTime()
    {
        cout << "Please input time-year/month/day/hour/minute/second:" << endl;
        cin >> year >> month >> day >> hour >> minute >> second;
    }
    void Show()
    {
        cout << year << '/' << month << '/' << day << ' ' << hour << ':' << minute << ':' << second << endl;
    }
};

int main()
{
    cout << "Part1:" << endl;
    Timedate(1);
    cout << "Part2" << endl;
    Timedate a;
    a.SetTime();
    a.Show();
    return 0;
}