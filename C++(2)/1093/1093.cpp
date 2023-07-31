#include <iostream>
#include <cstring>
using namespace std;

void strshift(char *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        char *templist = s;
        char tempptr = s[0];
        while (*(s + 1) != '\0')
        {
            *s = *(s + 1);
            s++;
        }
        *s = tempptr;
        s = templist;
    }
}

int main()
{
    int n;
    char c[200];
    cin.get(c, 200);
    cin >> n;
    strshift(c, n);
    cout << c << endl;
    return 0;
}