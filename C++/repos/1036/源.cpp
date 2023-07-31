#include<iostream>
using namespace std;

int main() {
	int d1, d2, h1, h2, m1, m2;
	int t1, t2;
	int temp1,temp2;
	cin >> d1 >> h1 >> m1 >> d2 >> h2 >> m2;
	if (d2 > d1) {
		temp1 = 24 * 60 - h1 * 60 - m1;
		temp2 = h2 * 60 + m2;
		temp1 = temp1 + temp2;
		temp2 = temp1 / 60;
		temp1 = temp1 % 60;
		cout << temp2 << " " << temp1;
	}
	else {
		temp1 = (h2 * 60 + m2) - (h1 * 60 + m1);
		temp2 = temp1 / 60;
		temp1 = temp1 % 60;
		cout << temp2 << " " << temp1;
	}
	return 0;
}