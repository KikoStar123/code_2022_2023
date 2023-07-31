#include <iostream>
using namespace std;

char *encryption(char *list)
{
    char *list2=list;
    while (*list != '\0')
    {
        if ((*list >= 'a' && *list < 'z') || (*list >= 'A' && *list < 'Z'))
        {
            (*list)++;
            list++;
            continue;
        }
        if (*list >= '0' && *list < '9')
        {
            (*list)++;
            list++;
            continue;
        }
        if (*list == 'z')
        {
            *list = 'a';
            list++;
            continue;
        }
        if (*list == 'Z')
        {
            *list = 'A';
            list++;
            continue;
        }
        if (*list == '9')
        {
            *list = '0';
            list++;
            continue;
        }
        list++;
    }
    return list2;
}

int main()
{
    char c[200];
    cin.getline(c, 200);
    char *c1 = encryption(c);
    cout << c1 << endl;
    return 0;
}