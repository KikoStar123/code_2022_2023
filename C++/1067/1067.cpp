#include <iostream>
using namespace std;

int age(int n, int ag)
{
    if (n == 5)
        return ag;
    return (age(n + 1, ag + 2));
}

int main()
{
    int n = 1;
    int ag = 20;
    cout<<age(n, ag)<<endl;
    return 0;
}