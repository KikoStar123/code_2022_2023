#include<iostream>
using namespace std;
int i, ans;
int  k=1;

int digui(int n)
{
	if (n == 0)
		return 1;
	else
		return(digui(n-1)+digui(n-1));
}

int main() {
	cin >> i;
	k = digui(i);
	cout << k << endl;
	return 0;
}