/*write function template two_smallest,
and find the two minimum values of the three elements(元素)*/

#include <iostream>
using namespace std;
template <typename T>
T two_smallest(T &A, T &B)
{
    if (A <= B)
        return A;
    else
    {
        T C;
        C = A;
        A = B;
        B = C;
        return B;
    }
}

int main()
{
    int a, b, c;
    int min1, min2;
    cin>> a>>b>>c;
    min1 = two_smallest(a, b);
    min2 = two_smallest(a, c);
    cout << min1 << " " << min2 << endl;
    return 0;
}