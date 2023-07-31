#include <iostream> //成员函数版本
using namespace std;

class Complex
{
private:
    double r, i;

public:
    Complex(Complex &a)
    {
        r = a.r;
        i = a.i;
    } // 默认复制构造函数
    Complex(double real = 0.0, double image = 0.0)
    {
        r = real;
        i = image;
    } // 构造函数
    Complex operator-(Complex);
    Complex operator-(double);
    Complex &operator-=(Complex);
    Complex &operator-=(double);
    Complex &operator*=(Complex);
    Complex &operator*=(double);
    Complex &operator/=(Complex);
    Complex &operator/=(double);
    Complex &operator++();   // 前置++
    Complex operator++(int); // 后置++
    void output()
    {
        if (i > 0)
            cout << r << "+" << i << "i";
        if (i == 0)
            cout << r;
        if (i < 0)
            cout << r << i << "i";
    }
};

void OUTSTATEMENT(Complex A, Complex B, Complex C, char *st)
{
    cout << "测试运算符";
    cout << st << ":";
    A.output();
    cout << st << "(";
    B.output();
    cout << ")=";
    C.output(); // 测试格式化输出
}

void OUTSTATEMENT(Complex A, double B, Complex C, char *st)
{
    cout << "测试运算符";
    cout << st << ":";
    A.output();
    cout << st << "(";
    cout << B;
    cout << ")=";
    C.output(); // 测试格式化输出
}

Complex Complex::operator-(Complex a)
{
    Complex t;
    t.r = r - a.r;
    t.i = i - a.i;
    return t;
}

Complex Complex::operator-(double a)
{
    Complex t;
    t.r = r - a;
    t.i = i;
    return t;
}

Complex &Complex::operator-=(Complex a)
{
    i = i - a.i;
    r = r - a.r;
    return *this;
}

Complex &Complex::operator-=(double a)
{
    r = r - a;
    return *this;
}

Complex &Complex::operator*=(Complex a)
{
    Complex t = *this;
    t.r = r * a.r - i * a.i;
    t.i = r * a.i + a.r * i;
    return t;
}

Complex &Complex::operator*=(double a)
{
    r = r * a;
    i = i * a;
    return *this;
}

Complex &Complex::operator/=(Complex a)
{
    Complex t = *this;
    t.r = (r * a.r + i * a.i) / (a.r * a.r + a.i * a.i);
    t.i = (i * a.r - r * a.i) / (a.r * a.r + a.i * a.i);
    return t;
}

Complex &Complex::operator/=(double a)
{
    r = r / a;
    i = i / a;
    return *this;
}

Complex &Complex::operator++()
{
    r++;
    i++;
    return *this;
} // 前置++
Complex Complex::operator++(int)
{
    Complex t = *this;
    r++;
    i++;
    return t;
} // 后置++
int main()
{

    Complex A(2.0, 3.0);
    Complex B(1.0, 2.0);
    Complex C;
    double N = 3.5;
    C = A - B;
    OUTSTATEMENT(A, B, C, "-"); // 测试运算符-
    C = A - N;
    cout << endl;
    OUTSTATEMENT(A, N, C, "-");
    cout << endl;

    Complex D(A);
    D -= B;
    OUTSTATEMENT(A, B, D, "-="); // 测试-=
    D = A;
    D -= N;
    cout << endl;
    OUTSTATEMENT(A, N, C, "-=");
    cout << endl;

    D = A;
    D *= B;
    OUTSTATEMENT(A, B, D, "*="); // 测试-=
    D = A;
    D *= N;
    cout << endl;
    OUTSTATEMENT(A, N, D, "*=");
    cout << endl;

    D = A;
    D /= B;
    OUTSTATEMENT(A, B, D, "/="); // 测试/=
    D = A;
    D /= N;
    cout << endl;
    OUTSTATEMENT(A, N, D, "/=");
    cout << endl;

    D = A;
    Complex E;
    E = D++;
    cout << "D++返回值:";
    E.output();
    cout << endl;
    cout << "D++后D的真实值:";
    D.output(); // 测试前置++
    cout << endl;

    D = A;
    E = (++D);
    cout << "++D返回值:";
    E.output();
    cout << endl;
    cout << "++D后D的真实值:";
    D.output(); // 测试后置++
    cout << endl;
    return 0;
}
