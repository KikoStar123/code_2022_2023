#include <iostream>
using namespace std;

class Complex
{
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0)
    {
        real = r;
        imag = i;
    }

    Complex Adding(Complex x)
    {
        real += x.real;
        imag += x.imag;
    }

    Complex Subtracting(Complex x)
    {
        real -= x.real;
        imag -= x.imag;
    }

    void printing()
    {
        cout << real << "+" << imag << "i" << endl;
    };
};

int main()
{
    Complex a(2, 3);
    Complex b(4, 5);
    a.Adding(b);
    a.printing();
    cout << endl;
    a.Subtracting(b);
    a.printing();
    cout << endl;
    return 0;
}