#include<iostream>
using namespace std;
int main() {
	int x1, x2, x3, y1, y2, y3;
	int k, b;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if (x1 != x2) {
		k = (y1 - y2) / (x1 - x2);
		b = y1 - k * x1;
		if (y3 == k * x3 + b)
			cout << "BAD";
		else
			cout << "OK";
	}
	else {
		if(x3==x1)
			cout << "BAD";
		else
			cout << "OK";
	}
	
	return 0;
}