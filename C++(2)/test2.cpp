#include <iostream>
using namespace std;

int gcd(int a, int b) { // 辗转相除法求最大公约数
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

class Fraction {
private:
    int numerator; // 分子
    int denominator; // 分母
public:
    Fraction(int num = 0, int den = 1) { // 构造函数
        numerator = num;
        denominator = den;
    }
    Fraction(const Fraction& f) { // 复制构造函数
        numerator = f.numerator;
        denominator = f.denominator;
    }
    void reduce() { // 约分函数
        int factor = gcd(numerator, denominator);
        numerator /= factor;
        denominator /= factor;
    }
    void print() { // 打印函数
        if (denominator < 0) { // 处理负数分母
            numerator = -numerator;
            denominator = -denominator;
        }
        cout << "(" << numerator << "/" << denominator << ")";
    }
    void commonDenominator(Fraction& f) { // 通分函数
        int lcm = denominator * f.denominator / gcd(denominator, f.denominator);
        numerator *= lcm / denominator;
        denominator = lcm;
        f.numerator *= lcm / f.denominator;
        f.denominator = lcm;
    }
    Fraction operator+(const Fraction& f) { // 加号重载
        Fraction res(*this);
        res.commonDenominator(f);
        res.numerator += f.numerator;
        res.reduce();
        return res;
    }
    Fraction operator-(const Fraction& f) { // 减号重载
        Fraction res(*this);
        res.commonDenominator(f);
        res.numerator -= f.numerator;
        res.reduce();
        return res;
    }
    Fraction operator*(const Fraction& f) { // 乘号重载
        Fraction res(numerator * f.numerator, denominator * f.denominator);
        res.reduce();
        return res;
    }
    Fraction operator/(const Fraction& f) { // 除号重载
        Fraction res(numerator * f.denominator, denominator * f.numerator);
        res.reduce();
        return res;
    }
};

int main() {
    int num1, den1, num2, den2;
    cin >> num1 >> den1 >> num2 >> den2;

    Fraction f1(num1, den1), f2(num2, den2);

    // 加法
    Fraction sum = f1 + f2;
    f1.print();
    cout << " + ";
    f2.print();
    cout << " = ";
    sum.print();
    cout << endl;

    // 减法
    Fraction diff = f1 - f2;
    f1.print();
    cout << " - ";
    f2.print();
    cout << " = ";
    diff.print();
    cout << endl;

    // 乘法
    Fraction product = f1 * f2;
    f1.print();
    cout << " * ";
    f2.print();
    cout << " = ";
    product.print();
    cout << endl;

    // 除法
    Fraction quotient = f1 / f2;
    f1.print();
    cout << " / ";
    f2.print();
    cout << " = ";
    quotient.print();
    cout << endl;

    return 0;
}