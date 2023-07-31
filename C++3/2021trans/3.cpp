#include <iostream>
#include <cmath>
using namespace std;

class mutinomial
{
private:
    int power[20];
    int number[20];
    int count;

public:
    mutinomial(char *str = "")
    {
        for (int i = 0; i < 20; i++)
        {
            number[i] = 0;
            power[i] = 0;
        }
        count = 0;
        char *temp = str;
        while (*temp != '\0')
        {
            if (*temp != 'x')
                temp++;
            else
            {
                if (*(temp - 1) == '+' || *temp == *str)
                    number[count] = 1;
                else
                    number[count] = int(*(temp - 1) - '0');
                if (*(temp + 1) == '+')
                    power[count] = 1;
                else
                    power[count] = int(*(temp + 1) - '0');
                count++;
                temp++;
            }
        }
        sort();
    }

    void sort()
    {
        for (int i; i < count; i++)
        {
            for (int j = count - 1; j > i; j--)
            {
                if (power[j - 1] < power[j])
                {
                    swap(power[j - 1], power[j]);
                    swap(number[j - 1], number[j]);
                }
            }
        }
    }

    mutinomial operator+(mutinomial &t)
    {
        mutinomial tempobj;
        bool flag[20];
        int n = 0;
        int c = max(count, t.count);
        for (int i = 0; i < 20; i++)
            flag[i] = 0;
        for (int i = 0; i < c; i++)
        {
            tempobj.power[i] = power[i];
            tempobj.number[i] = number[i];
            for (int j = 0; j < c; j++)
            {
                if (power[i] == t.power[j])
                {
                    tempobj.number[i] += t.number[j];
                    flag[j] = 1;
                    n++;
                }
            }
        }

        tempobj.count = c + n;
        n = c - n;

        for (int i = 0; i < c; i++)
        {
            if (flag[i] != 1)
            {
                tempobj.power[c + n - 1] = t.power[i];
                tempobj.number[c + n - 1] = t.number[i];
                n--;
            }
        }
        tempobj.sort();
        return tempobj;
    }

    void print()
    {
        for (int i = 0; i < count; i++)
        {
            if (i != count - 1)
                if (number[i] != 1)
                {
                    cout << number[i] << "x^" << power[i] << '+';
                }
                else
                {
                    cout << "x^" << power[i] << '+';
                }
            else
            {
                if (number[i] != 1)
                {
                    cout << number[i] << "x^" << power[i] << endl;
                }
                else
                {
                    cout << "x^" << power[i] << endl;
                }
            }
        }
    }
};

int main()
{
    mutinomial A("x3+2x2");
    mutinomial B("x5+3x2");
    A.print();
    B.print();
    mutinomial C;
    C = A + B;
    C.print();
    return 0;
}