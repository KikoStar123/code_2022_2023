#include<iostream>
using namespace std;
int year, month;

int main() {
	cin >> year >> month;
	int i , j,k;
	const int a = 31;
	const int b = 30;
	const int c = 28;
	const int d = 29;
	i = year % 4;
	j = year % 100;
	k = year % 400;
	if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)  )
		cout << a<<endl;
	if ((month == 4) || (month == 6) || (month == 9) || (month == 11)  )
		cout << b<<endl;
	if (month == 2) {
		if ((i == 0 && j != 0)||(k==0))
			cout << d<<endl;
		else
			cout << c<<endl;
	}
	return 0;
}
