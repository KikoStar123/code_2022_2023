#include <iostream>
#include <cstring>
using namespace std;

char *Insert_Str(char *s1, const char *s2, int n)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char *p = new char[len1 + len2];
    char *t = p;
    for (int i = 0; i < n; i++)
    {
        *p = *s1;
        s1++;
        p++;
    }
    while (*s2 != '\0')
    {
        *p = *s2;
        s2++;
        p++;
    }
    while (*s1 != '\0')
    {
        *p = *s1;
        s1++;
        p++;
    }
    *p = '\0';
    return t;
}

int main()
{
    char s1[200];
    char s2[200];
    int n;
    cout << "请输第一个字符串：" << endl;
    cin.getline(s1, 200);
    cout << "请输第二个字符串：" << endl;
    cin.getline(s2, 200);
    cout << "请输入插入第二个字符串到第一个字符串当中的位置:" << endl;
    cin >> n;
    cout << Insert_Str(s1, s2, n);
    return 0;
}