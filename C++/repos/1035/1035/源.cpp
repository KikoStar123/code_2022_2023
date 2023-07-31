#include<iostream>
using namespace std;

int main() {
	float  cost, l;
	cin >> l;
	if (l <= 3)
		cout << 9<<endl;
	else {
		cost = 9 + (l - 3) * 2.4 + 2;
		cout << cost << endl;
	}
	return 0;
}