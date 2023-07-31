#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    int k = 0;
    int j = 0;
    for (i = 0; i <= 100; ++i) {
        k = i % 3;
        j = i % 10;
        if (k == 0 && j == 6) {
            cout << i << " ";
        }
    }
    return 0;
}
