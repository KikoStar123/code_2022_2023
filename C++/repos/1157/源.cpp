#include<iostream>
using namespace std;
int main() {
	double a, temp1,temp2;
	int temp3,temp4,temp5;
	cin >> a;
	while (a != 0) {
		temp3 = a;
		temp4 = temp3 % 10;
		temp5 = 100 * temp4;
		temp3 = temp3 / 10;
		temp4 = temp3 % 10;
		temp5 = temp5 + 10 * temp4;
		temp3 = temp3 / 10;
		temp5 = temp5 + temp3;
		temp2 = temp5;
		temp2 = temp2 / 1000;
		temp3 = a;
		temp1 = (a - temp3)*10.0;
		a = temp1 + temp2;
		cout << a << endl;
		a = 0;	
	}
	return 0;
}