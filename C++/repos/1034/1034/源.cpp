#include<iostream>
using namespace std;

int main() {
	int n, a, b, c;
	cin >> n;
	if ((n % 5 == 0) && (n % 3 == 0))
		cout << "A";
	if ((n % 5 != 0) && (n % 3 != 0))
		cout << "B";
	if ((n % 5 != 0) && (n % 3 == 0))
		cout << "C";
	if ((n % 5 == 0) && (n % 3 != 0))
		cout << "D";
	return 0;
}