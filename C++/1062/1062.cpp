#include <iostream>
using namespace std;
int isprime(int n)
{
    bool flag = true;
    bool flag2 = true;
    int count = 0;
    int num = 2;
    while (flag)
    {
        num++;
        if (num % 2 != 0)
        {
            for (int i = 2; i < num / 2; i++)
            {
                if (num % i == 0)
                {
                    flag2 = false;
                    break;
                }
            }
            if (flag2)
            {
                count++;
                flag2 = true;
            }
            else
                flag2 = true;
        }
        if (count == n - 1)
            flag = false;
    }
    return num;
}

int main()
{
    int n, m;
    cin >> n;
    m = isprime(n);
    cout << m << endl;
    return 0;
}