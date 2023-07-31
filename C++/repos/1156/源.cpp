#include<iostream>
using namespace std;

int main() {
	long salary;
	cin >> salary;
	long long i, j, k;
	i = salary * 12-60000;
	j = 0;
	if (i <= 36000) {
		j = i * 0.03;
	}
	else if(i<=144000){
		j = 1080 + (i - 36000) * 0.1;
	}else if(i<=300000){
		j = 11880 + (i - 144000) * 0.2;
	}
	else if (i <= 420000) {
		j = 43080 + (i - 300000) * 0.25;
	}else if (i <= 660000) {
		j = 73080 + (i - 420000) * 0.3;
	}
	else if (i <= 960000) {
		j = 145080 + (i - 660000) * 0.35;
	}
	else {
		j = 250080 + (i - 960000) * 0.45;
	}
	cout << j << endl;
	return 0;
}