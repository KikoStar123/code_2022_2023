#include <iostream>
#include <cstring>
using namespace std;

class bigint
{
private:
    char *str;
    int sign;
    int len;

public:
    bigint(const char *str1 = "")
    {
        if (str1[0] == '-')
        {
            sign = -1;
            str1++;
        }
        else
            sign = 1;
        len = strlen(str1);
        if (len)
        {
            str = new char[len + 1];
            strcpy(str, str1);
        }
        else
        {
            str = new char[1];
            str[0] = '\0';
        }
    }

    bigint(int list)
    {
        int i = 0;
        if (list >= 0)
            sign = 1;
        else
        {
            sign = -1;
            list = -list;
        }
        while (list % 10 != 0)
        {
            str[i++] = '0' + (list / 10);
            list /= 10;
        }
        str[i] = '\0';
        len = i - 1;
    }

    bigint(bigint &a)
    {
        if (a.len)
        {
            if (str = new char[a.len])
            {
                len = a.len;
                sign = a.sign;
                strcpy(str, a.str);
            }
            else
            {
                str = "";
                sign = 1;
                len = 0;
            }
        }
        else
        {
            str = "";
            sign = 1;
            len = 0;
        }
    }

    ~bigint()
    {
        delete[] str;
    }

    bigint &operator=(const bigint &);
    void print();
    bool operator>(const bigint &) const;
    bool operator==(const bigint &) const;
    bool operator<(const bigint &) const;
};

bigint &bigint::operator=(const bigint &b)
{
    if (this != &b)
    {
        delete[] str;
        len = b.len;
        sign = b.sign;
        str = new char[len + 1];
        strcpy(str, b.str);
    }
    return *this;
}

void bigint::print()
{
    if (sign == -1)
        cout << '-';
    cout << str << endl;
}

bool bigint::operator>(const bigint &a) const
{
    if (sign != a.sign)
        return sign > a.sign;
    if (len != a.len)
        return len > a.len;
    for (int i = 0; i < len; i++)
    {
        if (str[i] != a.str[i])
            return sign * (str[i] - '0') > a.sign * (a.str[i] - '0');
    }
    return false;
}

bool bigint::operator==(const bigint &a) const
{
    if (sign != a.sign)
        return false;
    if (len != a.len)
        return false;
    for (int i = 0; i < len; i++)
    {
        if (str[i] != a.str[i])
            return false;
    }
    return true;
}

bool bigint::operator<(const bigint &a) const
{
    if (sign != a.sign)
        return sign < a.sign;
    if (len != a.len)
        return len < a.len;
    for (int i = 0; i < len; i++)
    {
        if (str[i] != a.str[i])
            return sign * (str[i] - '0') < a.sign * (a.str[i] - '0');
    }
    return false;
}

char *input()
{
    char *tmp;
    char *tmp2;
    char c;
    c = cin.get();
    int i = 1;
    int capacity = 80;
    tmp = new char[capacity];
    tmp[0] = c;
    while (c != '\n')
    {
        c = cin.get();
        tmp[i++] = c;
        if (i > capacity)
        {
            tmp[i] = '\0';
            tmp2 = new char[capacity];
            strcpy(tmp2, tmp);
            delete[] tmp;
            capacity *= 2;
            tmp = new char[capacity];
            strcpy(tmp, tmp2);
            delete[] tmp2;
        }
    }
    tmp[i - 1] = '\0';
    return tmp;
}

int main()
{
    char *a1, *a2;
    a1 = input();
    a2 = input();
    bigint b1(a1);
    bigint b2(a2);
    bigint b3(b1);
    b3.print();
    bigint b4;
    b4 = b2;
    b4.print();
    if(b1>b2)cout<<'1'<<endl;
    if(b1==b2)cout<<'0'<<endl;
    if(b1<b2)cout<<"-1"<<endl;
    return 0;
}