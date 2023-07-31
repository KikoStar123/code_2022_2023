/*
 * @Author: KIKOSTAR 842544563@outlook.com
 * @Date: 2023-04-08 23:31:45
 * @LastEditors: KIKOSTAR 842544563@outlook.com
 * @LastEditTime: 2023-04-08 23:31:54
 * @FilePath: \CODE\C++(2)\1117\1117_2.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <cstring>
using namespace std;
class mystring
{
private:
    char *str;
    int len;

public:
    mystring(const char *s = "")
    {
        len = strlen(s);
        if (len == 0)
        {
            str = new char[1];
            str[0] = '\0';
        }
        else
        {
            str = new char[len + 1];
            strcpy(str, s);
        }
    }
    mystring(const mystring &s)
    {
        len = s.len;
        str = new char[len + 1];
        strcpy(str, s.str);
    }
    ~mystring()
    {
        delete[] str;
    }
    void print()
    {
        cout << str << endl;
    }
    mystring &operator=(const mystring &s)
    {
        if (this == &s)
            return *this;
        delete[] str;
        len = s.len;
        str = new char[len + 1];
        strcpy(str, s.str);
        return *this;
    }
    mystring operator+(const mystring &s)
    {
        mystring tmp;
        tmp.len = len + s.len;
        tmp.str = new char[tmp.len + 1];
        strcpy(tmp.str, str);
        strcat(tmp.str, s.str);
        return tmp;
    }
    mystring &operator+=(const mystring &s)
    {
        char *tmp = new char[len + s.len + 1];
        strcpy(tmp, str);
        strcat(tmp, s.str);
        len += s.len;
        delete[] str;
        str = tmp;
        return *this;
    }
};
int main()
{
    mystring s1("south"), s2("east"), s3;
    s3 = s1 + s2;
    s3.print();
    s1 += s2;
    s1.print();
    return 0;
}