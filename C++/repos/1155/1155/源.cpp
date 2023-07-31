#include<iostream>
#include<iomanip>
using namespace std;
double a, b, c;
int main() {
	cin >> a >> b;
	c = b / a;
	c = c * 100;
	cout << fixed<<setprecision(3) << c << "%" << endl;
	return 0;
}