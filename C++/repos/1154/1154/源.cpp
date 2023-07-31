#include<iostream>
using namespace std;
double a, b, r;
int k;

int main() {
	cin >> a >> b;
	k = a / b;
	r = a - (k * b);
	cout << r << endl;
}