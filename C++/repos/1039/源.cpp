#include<iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b)
		cout << "C";
	if (a == c)
		cout << "B";
	if (b == c)
		cout << "A";
	
	return 0;
}