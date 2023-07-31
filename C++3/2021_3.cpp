/*实现多项式类*/
#include <iostream>
using namespace std;

class Polynomial
{
private:
    char *list;
    int mod[20];
    int power[20];

public:
    
    void analysis();
    void print();
    void def();
    Polynomial(char *a)
    {
        while (*a != '\0')
            *list++ = *a++;
        def();
    }
    ~Polynomial();
};

void Polynomial::analysis()
{
    char *l = list;
    int flag1 = 0;
    int flag2 = 0;
    for (int i = 0; i < 20; i++)
    {
        mod[i] = 0;
        power[i] = 0;
    }
    while (*l != '\0')
    {
        if (*l == 'x')
        {
            char *p = l - 1;
            char tempnum = 1;
            int tempmod = 0;
            int temppow = 0;
            int tempmod1 = 1;
            int temppow1 = 1;
            while (*p != '+')
            {
                tempmod1 = *p;
                for (int i = 0; i < tempnum; i++)
                    tempmod1 *= 10;
                tempmod += tempmod1;
                tempnum++;
                p--;
            }
            mod[tempmod] += 1;

            p = l + 1;
            while (*p != '+' && *p != '\0')
                p++;
            tempmod = 0;
            temppow = 0;
            tempmod1 = 1;
            temppow1 = 1;
            while (*p != '+')
            {
                tempmod1 = *p;
                for (int i = 0; i < tempnum; i++)
                    tempmod1 *= 10;
                tempmod += tempmod1;
                tempnum++;
                p--;
            }
            power[tempmod1] += 1;
        }
        l++;
    }
}

void Polynomial::def()
{
    for (int i = 0; i < 20; i++)
    {
        mod[i] = 0;
        power[i] = 0;
    }
}

void Polynomial::print()
{
}

int main()
{
    char list[100];
    cin.getline(list,100);
    Polynomial a(list);
    a.analysis();
    return 0;
}