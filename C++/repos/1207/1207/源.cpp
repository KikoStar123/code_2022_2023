#include<iostream>
using namespace std;
double n, x, y;

int main() {
	cin >> n >> x >> y;
	int sum;
	sum = n - (y / x);
	cout << sum << endl;
	return 0;
}