#include<iostream>
using namespace std;

int main() {
	int k,n;
	cin >> n;
	k = n % 2;
	if (k == 1)
		cout << "odd";
	else
		cout << "even";

}