#include<iostream>
using namespace std;

int main() {
	int i, j;
	j = 0;
	for (i = 1; i <101; i+=2) {
		j = j + i * (i + 1) * (i + 2);
	}
	cout << j << endl;
	return 0;
}