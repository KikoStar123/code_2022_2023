#include <iostream>
#include <cstring>
using namespace std;

bool instr(char *s1, char *s2, int startstatement = 0, int comparmode = 0)
{

    bool flag = true;
    if (comparmode == 1)
    {
        char *temp1 = s1;
        char *temp2 = s2;
        while (*s1 != '\0')
        {
            if (*s1 >= 'A' && *s1 <= 'Z')
                *s1 = *s1 - ('A' - 'a');
            s1++;
        }
        while (*s2 != '\0')
        {
            if (*s2 >= 'A' && *s2 <= 'Z')
                *s2 = *s2 - ('A' - 'a');
            s2++;
        }
        s1 = temp1;
        s2 = temp2;
    }
    s1 += startstatement;
    if (strlen(s1) < strlen(s2))
        return false;
    while (flag)
    {
        while (*s2 != *s1)
        {
            if (*s1 == '\0')
            {
                flag = false;
                break;
            }
            s1++;
        } //确定重合位置
        const char *s4 = s2;
        const char *s3 = s1;
        while (*s4 != '\0')
        {
            s4++;
            s3++;
            if (*s3 != *s4)
                break;
            if (*(s4 + 1) == '\0')
            {
                if (*s4 == *s3)
                    return true;
            }
        }
        s1++;
    }
    return false;
}

int main()
{
    char s1[100];
    char s2[100];
    int start = 0;
    int compare = 0;
    cin.getline(s1, 100);
    cin.getline(s2, 100);
    cin >> start >> compare;
    if (instr(s1, s2, start, compare))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}