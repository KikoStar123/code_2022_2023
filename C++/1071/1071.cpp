#include <iostream>
using namespace std;

int magic(int a)
{
    int list[20];
    int n = a;
    int radix = 0;
    int even = 0;
    int nums = 0;
    int j = 0;

    if (n == 321)
        return 0;
    if (n == 0)
    {
        nums = 1;
        even = 1;
        radix = 0;
        n = 101;
    }
    else
    {
        while (n != 0)
        {
            nums++;
            if (n % 2 == 0)
                even++;
            else
                radix++;
            n /= 10;
        }

        while (even != 0)
        {
            list[j++] = even % 10;
            even /= 10;
        }
        while (radix != 0)
        {
            list[j++] = radix % 10;
            radix /= 10;
        }
        while (nums != 0)
        {
            list[j++] = nums % 10;
            nums /= 10;
        }
        n = 0;
        for (int k = 0; k < j; k++)
        {
            for (int p = 0; p < k; p++)
                list[k] *= 10;
            n += list[k];
        }
    }
    cout << n << endl;
    return magic(n);
}

int main()
{
    int n = 0;
    cin >> n;
    magic(n);
    return 0;
}