#include <iostream>
#include <cstring>
using namespace std;
bool instr(const char *s1, const char *s2)
{
    bool flag = true;
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
        } // 确定重合位置
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
    char c1[100];
    char c2[100];
    cin.getline(c1, 100);
    cin.getline(c2, 100);
    if (strlen(c1) < strlen(c2))
    {
        cout << "NO" << endl;
        return 0;
    }
    if (instr(c1, c2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    // system("pause");
    return 0;
}