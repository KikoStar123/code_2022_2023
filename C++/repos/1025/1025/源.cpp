#include<iostream>
#include<cmath>
using namespace std;
double a, b, c, p,s;
int main() {
	cin >> a >> b >> c;
	p = 0.5 * (a + b + c);
	s = sqrt(p * (p - a) * (p - b) * (p - c));
	cout << s << endl;
	return 0;
}