#include <iostream>
using namespace std;

int sequence(int n)
{
    if (n == 1 || n == 2)
        return 1;
    if (n == 0)
        return 0;
    return (sequence(n - 1) + sequence(n - 2) + sequence(n - 3));
}

int main()
{
    int n;
    cin >> n;
    cout << sequence(n) << endl;
    return 0;
}