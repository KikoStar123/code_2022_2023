#include <iostream>
using namespace std;
int function(int a)
{
    int n = 0;
    int sum = 0;
    int m = 0;
    bool flag = true;
    while (flag)
    {
        for (int i = 0; i < m; i++)
        {
            if (n == a)
            {
                flag = false;
                break;
            }
            sum += m;
            n++;
        }
        m++;
    }
    cout << sum << endl;
    return 0;
}
int main()
{
    int a;
    cin >> a;
    function(a);
    return 0;
}