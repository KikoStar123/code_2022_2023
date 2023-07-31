#include <iostream>
using namespace std;
int main()
{
    char c;
    int count = 0;
    c = cin.get();
    while (c != '\n')
    {
        if (c >= '0' && c <= '9')
            count++;
        c = cin.get();
    }
    cout << count << endl;
    return 0;
}