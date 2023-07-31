/*
 * @Author: your name
 * @Date: 2022-04-21 12:13:02
 * @LastEditTime: 2022-04-21 12:28:50
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1100\1100.cpp
 */
#include <iostream>
using namespace std;

class Human
{
private:
    string Name;
    int year1, month1, day1;

public:
    Human(string name) { Name = name; }
    void nameout()
    {
        cout << "Name:" << Name << endl;
    }
    void birth_day(int y1, int m1, int d1)
    {
        year1 = y1;
        month1 = m1;
        day1 = d1;
        cout << "Birth:" << year1 << "-" << month1 << "-" << day1 << endl;
    }
    void death_day(int y1, int m1, int d1)
    {
        year1 = y1;
        month1 = m1;
        day1 = d1;
        cout << "Death:" << year1 << "-" << month1 << "-" << day1 << endl;
    }
};

int main()
{
    int y1, m1, d1, y2, m2, d2;
    string name;
    cin >> name >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
    Human s1(name);
    s1.nameout();
    s1.birth_day(y1, m1, d1);
    s1.death_day(y2, m2, d2);
    return 0;
}