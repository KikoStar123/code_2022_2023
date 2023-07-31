#include<iostream>
using namespace std;

int main() {
	int x, y;
	for (x = 1; x <= 45; x++) {
		for (y = 1; y <= 45; y++) {
			if (x * x + y * y == 2017) {
				cout << x << " " << y<<endl;
			}
		}
	}
	return 0;
}