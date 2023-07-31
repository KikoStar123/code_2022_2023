#include<iostream>
using namespace std;

int main() {
	int i, j, k;
	int num = 0;
	int temp1, temp2, temp3;
	temp1 = temp2 = temp3=0;
	i = j = k = 0;
	for (i = 1; i <= 100; ++i) {
		for (k=	i; k <= 100; ++k) {
			for (j = k; j <= 100; ++j) {
				temp1 = i * i;
				temp2 = k * k;
				temp3 = j * j;
				if (temp1 + temp2 == temp3) {
					num++;
				}
			}
		}
	}
	cout << num << endl;
	return 0;
}