#include<iostream>
#include<math.h>
using namespace std;
double i,j;
int main() {
	double h, r, v;
	cin >> h >> r;
	v = (3.14 * r * r * h) / 1000;
	i = 20/v;
	j = ceil(i);
	cout << j << endl;
	return 0;
}