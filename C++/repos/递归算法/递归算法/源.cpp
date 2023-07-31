#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int i, j, k;

int xn(int j) {
	if (j == 0) { k = 1; }
	else {
		xn(j - 1);
		k = k * i;
	}
	return k;
}

int main() {
	cin >> i >> j;
	xn(j);
		cout << k;
}

