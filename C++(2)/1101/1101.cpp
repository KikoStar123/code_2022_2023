/*
 * @Author: KIKOSTAR 842544563@outlook.com
 * @Date: 2023-03-16 19:11:20
 * @LastEditors: KIKOSTAR 842544563@outlook.com
 * @LastEditTime: 2023-03-16 20:13:24
 * @FilePath: \CODE\C++(2)\1101\1101.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;

class Fraction
{
private:
    int a;
    int b;

public:
    Fraction(int A = 0, int B = 1)
    {
        a = A;
        b = B;
    }
    Fraction(Fraction &c)
    {
        a = c.a;
        b = c.b;
    }
    Fraction &divide();       // 约分
    int gongyueshu(int, int); // 公约数
    void show();              // 输出函数
    Fraction operator+(Fraction &);
    Fraction operator-(Fraction &);
    Fraction operator*(Fraction &);
    Fraction operator/(Fraction &);
};

Fraction &Fraction::divide() // 约分
{
    int c, d, tempnum;
    c = max(a, b);
    d = min(a, b);
    tempnum = gongyueshu(c, d);
    if (tempnum)
    {
        a /= tempnum;
        b /= tempnum;
    }
    return *this;
}

int Fraction::gongyueshu(int c, int d)
{
    int tempa = c;
    int tempb = d;
    if (tempa % tempb == 0)
    {
        return tempb;
    }
    while (tempa % tempb != 0)
    {
        int tempc;
        tempc = tempa % tempb;
        tempa = tempb;
        tempb = tempc;
        if (tempa % tempb == 0)
            return tempb;
    }
    return 0;
}

void Fraction::show()
{
    if (b < 0)
    {
        b = 0 - b;
        a = 0 - a;
    }
    cout << "(" << a << "/" << b << ")";
}

Fraction Fraction::operator+(Fraction &c)
{
    Fraction temp = *this;
    a = a * c.b + b * c.a;
    b = b * c.b;
    Fraction temp2 = divide();
    *this = temp;
    return temp2;
}

Fraction Fraction::operator-(Fraction &c)
{
    Fraction temp = *this;
    a = a * c.b - b * c.a;
    b = b * c.b;
    Fraction temp2 = divide();
    *this = temp;
    return temp2;
}

Fraction Fraction::operator*(Fraction &c)
{
    Fraction temp = *this;
    a = a * c.a;
    b = b * c.b;
    Fraction temp2 = divide();
    *this = temp;
    return temp2;
}

Fraction Fraction::operator/(Fraction &c)
{
    Fraction temp = *this;
    a = a * c.b;
    b = b * c.a;
    Fraction temp2 = divide();
    *this = temp;
    return temp2;
}

void print(Fraction A, Fraction B, string C, Fraction D)
{
    A.show();
    cout << C;
    B.show();
    cout << "=";
    D.show();
    cout << endl;
}

int main()
{
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    Fraction A(a1, b1);
    Fraction B(a2, b2);
    Fraction D;
    D = A + B;
    print(A, B, "+", D);
    D = A - B;
    print(A, B, "-", D);
    D = A * B;
    print(A, B, "*", D);
    D = A / B;
    print(A, B, "/", D);
    return 0;
}