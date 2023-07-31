#include <iostream>
using namespace std;
int main()
{
    cout << "please input two strings:" << endl;
    char a1[40];
    char a2[40];
    cin >> a1 >> a2;
    char *tempP1 = a1;
    char *tempP2 = a2;
    while (*tempP1 != '\0')
    {
        tempP1++;
    }
    *(tempP1 - 1) = ',';
    while (*tempP2 != '\0')
    {
        *tempP1++ = *tempP2++;
    }
    *tempP2='\0';
    cout<<a1<<endl;
    return 0;
}