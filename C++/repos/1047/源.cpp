#include<iostream>
using namespace std;

int main() {
	int i, j, k = 0;
	int a, b, c;
	a = b = c = 0;
	int sum = 0;
	for (i = 1; i <= 3; ++i) {
		a = a + 5;
		for (j = 1; j <= 10; ++j) {
			b = b + 2;
			for (k = 1; k <= 20; ++k) {
				c = c + 1;
				sum = a + b + c;
				if (sum == 20)
					cout << i << " " << j << " " << k << endl;
			}
			c = 0;
		}
		b = 0;
	}
	return 0;
}