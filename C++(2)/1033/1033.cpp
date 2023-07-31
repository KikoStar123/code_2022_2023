#include <iostream>
using namespace std;
bool judgement(int y);
int main()
{
    int year, month;
    cin >> year >> month;
    if (month == 2)
    {
        if (judgement(year))
            cout << 29 << endl;
        else
            cout << 28 << endl;
    }

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        cout << 31 << endl;
    else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
        cout << 30 << endl;

    return 0;
}

bool judgement(int y)
{
    if ((y % 4 == 0 && y & 100 != 0) || (y % 400 == 0))
        return true;
    else
        return false;
}