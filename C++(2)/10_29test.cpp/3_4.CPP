#include <iostream>
#include <cmath>
using namespace std;
int gcd(int, int);
int lcm(int, int);
int main()
{
    int num1, num2;
    cout << "please enter two numbers:";
    cin >> num1 >> num2;
    cout << "gcd is:" << gcd(num1, num2) << endl;
    cout << "lcm is:" << lcm(num1, num2) << endl;
    return 0;
}
int gcd(int num1, int num2)
{
    int tempnum = 0;
    if (num1 < num2)
        swap(num1, num2);
    tempnum = num1 % num2;
    while (tempnum != 0)
    {
        num1 = num2;
        num2 = tempnum;
        tempnum = num1 % num2;
    }
    return num2;
}
int lcm(int num1, int num2)
{
    return ((num1 * num2) / gcd(num1, num2));
}