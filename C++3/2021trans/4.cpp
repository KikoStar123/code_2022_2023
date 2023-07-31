#include <iostream>
using namespace std;

class Date
{
private:
    int year, month, day;

public:
    Date(int y = 0, int m = 0, int d = 0)
    {
        year = y;
        month = m;
        day = d;
    }

    void print()
    {
        cout << year << '-' << month << '-' << day;
    }
};

class Finaltest
{
private:
    string list;
    Date date;

public:
    Finaltest(string l = "defult", Date d = Date(2014, 1, 1))
    {
        list = l;
        date = d;
    }
    void print()
    {
        cout << "Title:" << list << endl;
        cout << "Test Date:";
        date.print();
        cout << endl;
    }
    void setDue(Date d)
    {
        date = d;
    }
};

int main()
{
    Finaltest item1("C++ Test", Date(2014, 6, 2));
    item1.print();
    Finaltest item2("Java");
    item2.print();
    item2.setDue(Date(2014, 6, 10));
    item2.print();
    return 0;
}