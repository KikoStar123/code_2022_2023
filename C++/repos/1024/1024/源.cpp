#include<iostream>
#include<cstdio>
using namespace std;
const double pi = 3.14;
double h, r, c;

int main() {
	cin >> h >> r;
	double v, s1, s2;
	v = pi * r * r * h;
	s1 = 2 * pi * r * h;
	s2 = 2*pi * r * r + s1;
	cout << v <<" " << s1<< " " << s2;
	return 0;
}