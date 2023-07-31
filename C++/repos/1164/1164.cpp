//问题 A: 求一元二次方程的根
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
	double a, b, c;
	double x1, x2, d;
	double i, j;
	x1 = x2 = d = 0;
	cin >> a >> b >> c;
	d = b * b - 4 * a * c;
	if (d >= 0) {
		x1 = (0 - b + sqrt(d)) / (2 * a);
		x2 = (0 - b - sqrt(d)) / (2 * a);
		if (x1 == x2)
			cout << "x1=x2=" << fixed << setprecision(5) << x1 << endl;
		else
		{
			cout << "x1=" << fixed << setprecision(5) << x1 << ';';
			cout << "x2=" << fixed << setprecision(5) << x2 << endl;
		}
	}
	else {
		i = 0 - b / (2 * a);
		j = sqrt(0 - d) / (2 * a);
		cout << "x1=" << fixed << setprecision(5) << i << '+' << fixed << setprecision(5) << j << "i" << ';';
		cout << "x2=" << fixed << setprecision(5) << i << '-' << fixed << setprecision(5) << j << "i" << endl;
	}
	return 0;
}