#include <iostream> //友元函数版本
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
    friend Complex operator-(Complex &, const Complex &);
    friend Complex operator-(Complex &, double);
    friend Complex &operator-=(Complex &, const Complex &);
    friend Complex &operator-=(Complex &, double);
    friend Complex &operator*=(Complex &, const Complex &);
    friend Complex &operator*=(Complex &, double);
    friend Complex &operator/=(Complex &, const Complex &);
    friend Complex &operator/=(Complex &, double);
    friend Complex &operator++(Complex &);     // 前置++
    friend Complex operator++(Complex &, int); // 后置++
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
    cout << "-(";
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

Complex operator-(Complex &a, const Complex &b)
{
    Complex t;
    t.r = a.r - b.r;
    t.i = a.i - b.i;
    return t;
}
Complex operator-(Complex &a, double b)
{
    Complex t;
    t.r = a.r - b;
    t.i = a.i;
    return t;
}
Complex &operator-=(Complex &a, const Complex &b)
{
    a.i = a.i - b.i;
    a.r = a.r - b.r;
    return a;
}
Complex &operator-=(Complex &a, double b)
{
    a.r = a.r - b;
    return a;
}
Complex &operator*=(Complex &a, const Complex &b)
{
    Complex t = a;
    t.r = a.r * b.r - a.i * b.i;
    t.i = a.r * b.i + b.r * a.i;
    a = t;
    return t;
}
Complex &operator*=(Complex &a, double b)
{
    a.r = a.r * b;
    a.i = a.i * b;
    return a;
}
Complex &operator/=(Complex &a, const Complex &b)
{
    Complex t = a;
    t.r = (a.r * b.r + a.i * b.i) / (b.r * b.r + b.i * b.i);
    t.i = (a.i * b.r - a.r * b.i) / (b.r * b.r + b.i * b.i);
    a = t;
    return t;
}
Complex &operator/=(Complex &a, double b)
{
    a.r = a.r / b;
    a.i = a.i / b;
    return a;
}
Complex &operator++(Complex &a)
{
    a.r++;
    a.i++;
    return a;
} // 前置++
Complex operator++(Complex &a, int)
{
    Complex t = a;
    a.r++;
    a.i++;
    return t;
}

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
