#include <iostream>
using namespace std;
char enter();
char trans(char);
int main()
{

    cout << trans(enter()) << endl;
    cout << trans(enter()) << endl;
    return 0;
}
char enter()
{
    char c;
    cout << "please enter a alphabet:";
    cin >> c;
    return c;
}

char trans(char c)
{
    if (c >= 65 && c <= 90)
        return (c + 32);
    else if (c >= 95 && c <= 122)
        return (c - 32);
    else
        return -1;
}