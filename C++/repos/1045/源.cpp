#include<iostream>
using namespace std;

int main() {
	int i, j = 0;
	for (i = 1; i <=9; i+=2) {
		for (j = 0; j < i-1; j++) {
			cout << "*";
		}
		cout << "*" << endl;
	}
	return 0;
}