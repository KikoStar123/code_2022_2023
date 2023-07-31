#include <iostream>
using namespace std;
bool isprimenum(int);
void process(int);
int main()
{
    for (int i = 4; i <= 50; i = i + 2)
        process(i);
    return 0;
}
bool isprimenum(int num)
{
    if (num % 2 == 0 && num != 2)
        return false;
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
void process(int num)
{
    for (int i = 1; i <= num / 2; i++)
    {
        if (isprimenum(i) && isprimenum(num - i))
            cout << num << "=" << i << "+" << num - i << endl;
    }
}
