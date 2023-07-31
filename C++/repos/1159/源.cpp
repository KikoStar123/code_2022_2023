#include<iostream>
using namespace std;
int main() {
	int b = 120;
	int a = 0;
	int c[2];
	int j = 0;
	int sum = 0;
	int i;
	for (i = 0; i <= 120; ++i) {
		sum = b * a;
		if (sum == 3500) {
			cout << a << endl;
			break;
		}	
		b--;
		a++;
	}
	return 0;
}