#include <iostream>
using namespace std;
bool isprime(int n)
{
    bool flag = true;
    int num = n;
    if (num % 2 != 0)
    {
        for (int i = 2; i < num / 2; i++)
        {
            if (num % i == 0)
            {
                flag = false;
                break;
            }
        }
    }
    else
        flag = false;
    return flag;
}

int factorsum(int i)
{
    int sum = 0;
    int num1 = 2;
    int temp = i;
    bool flag1 = true;
    bool flag = isprime(i);
    if (flag)
        return 1;
    else
    {
        while (flag1)
        {
            if (i % num1 == 0)
            {
                for (int num2 = i / 2; num2 >= num1; num2--)
                {
                    if (num2 * num1 == i)
                    {
                        sum = sum + num1 + num2;
                        temp = num2;
                        break;
                    }
                }
            }
            num1++;
            if (temp <= num1)
                flag1 = false;
        }
    }
    return sum;
}

int main()
{
    int a, b;
    bool flag[400];
    for (int i = 0; i < 400; i++)
        flag[i] = true;
    for (int i = 4; i <= 200; i++)
    {
        if (flag[i])
        {
            a = factorsum(i);
            flag[a] = false;
            if (a > 0 && a <= 400 && a != i && a != 1)
            {
                b = factorsum(a);
                if (b == i)
                {
                    if (a <= b)
                        cout << a << " " << b << endl;
                    else
                        cout << b << " " << a << endl;
                    flag[b] = false;
                }
            }
        }
    }
    return 0;
}