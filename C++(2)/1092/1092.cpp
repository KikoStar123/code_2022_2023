#include <iostream>
#include <cstring>
using namespace std;

void Mid(const char *str, char *s, int start, int len)
{
    int orig_len = strlen(str);
    if (orig_len < start + len)
        len = orig_len - start;
    str += start;
    while (*str != '\0'&&len>0)
    {
        *s = *str;
        s++;
        str++;
        len--;
    }
}

int main()
{
    char c[300];
    char s[300];
    cin.get(c, 300);
    int start = 0;
    int len;
    cin >> start >> len;
    Mid(c, s, start, len);
    cout << s << endl;
    return 0;
}