#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, count = 1, max1 = 0;
    cin >> n;
    int *arry = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arry[i];
    for (int j = 1; j < n; j++)
    {
        if (arry[j] == arry[j - 1] + 1)
            count++;
        else
            count = 1;
        max1 = max(count, max1);
    }
    cout << max1 << endl;
    return 0;
}