#include <iostream>
#include <string.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class mystring
{
private:
    char *str;
    int len;

public:
    mystring(const char *tstr = "")
    {
        len = strlen(tstr);
        if (len)
            if (str = new char[strlen(tstr) + 1])
                strcpy(str, tstr);
            else
            {
                str = new char[1];
                str[0] = '\0';
            }
        else
        {
            str = new char[1];
            str[0] = '\0';
        }
    }

    ~mystring()
    {
        delete[] str;
    }

    mystring(mystring &a)
    {
        if (a.len)
        {
            if (str = new char[a.len])
            {
                len = a.len;
                strcpy(str, a.str);
            }
            else
            {
                str = NULL;
                len = 0;
            }
        }
        else
        {
            str = NULL;
            len = 0;
        }
    }

    mystring &operator=(const mystring &s);
    void print();
    mystring &operator+=(const mystring &s);
    mystring operator+(const mystring &s);
    char &operator[](int i);
    mystring upper();
    mystring lower();
    mystring reverse();
    int find(const mystring &s);
    int length();
};

mystring &mystring::operator=(const mystring &s)
{
    if (this == &s)
        return *this;
    delete[] str;
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);
    return *this;
}

int mystring::length()
{
    return len;
}

void mystring::print()
{
    cout << str;
    cout << endl;
}

mystring mystring::operator+(const mystring &s)
{
    mystring tmp;
    tmp.len = len + s.len;
    tmp.str = new char[tmp.len + 1];
    strcpy(tmp.str, str);
    strcat(tmp.str, s.str);
    return tmp;
}

mystring &mystring::operator+=(const mystring &s)
{
    char *tmp = new char[len + s.len + 1];
    strcpy(tmp, str);
    strcat(tmp, s.str);
    len += s.len;
    delete[] str;
    str = tmp;
    return *this;
}

char &mystring::operator[](int i)
{
    return str[i];
}

mystring mystring::upper()
{
    mystring tmp;
    tmp.len = len;
    tmp.str = new char[tmp.len + 1];
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            tmp.str[i] = str[i] + ('A' - 'a');
        else
            tmp.str[i] = str[i];
    }
    return tmp;
}

mystring mystring::lower()
{
    mystring tmp;
    tmp.len = len;
    tmp.str = new char[tmp.len + 1];
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            tmp.str[i] = str[i] - ('A' - 'a');
        else
            tmp.str[i] = str[i];
    }
    return tmp;
}

mystring mystring::reverse()
{
    mystring tmp;
    tmp.len = len;
    tmp.str = new char[tmp.len + 1];
    for (int i = 0; i < len; i++)
    {
        tmp.str[tmp.len - i - 1] = str[i];
    }
    tmp.str[len + 1] = '\0';
    return tmp;
}

int mystring::find(const mystring &s)
{
    char *tmp;

    for (int i = 0; i <= (len - s.len); i++)
    {
        tmp = new char[s.len];
        for (int j = 0; j < s.len; j++)
            tmp[j] = str[i + j];
        tmp[s.len] = '\0';
        if (!strcmp(tmp, s.str))
            return i;
        delete[] tmp;
    }
    return -1;
}

int main()
{
    /*mystring s1("south");
    mystring s2("east");
    mystring s3;
    s3 = s1 + s2;
    s3.print();
    s1 += s2;
    s1.print();*/
    char s[20];
    char t[20];
    cin >> s;
    cin >> t;
    mystring str1(s);
    mystring str2(t);
    for (int i = 0; i < str1.length(); i++)
        cout << str1[i] << ' ';
    cout << endl;
    mystring str3;
    str3 = str2.upper();
    str3.print();
    str3 = str1.reverse();
    str3.print();
    cout << str1.find(str2) << endl;
    return 0;
}