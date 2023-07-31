#include<iostream>
using namespace std;
int a, c;
int j[4];

int main() {
	cin >> a;
	j[1] = a % 10;
	j[2] = a / 10 % 10;
	j[3] = a / 100;
	for (int b = 1; b <= 3; ++b) {
		cout << j[b];
	}
	return 0;
}