#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<double> vecDouble(200);
vector<int> b(200);
vector<double> vecDouble2(200);
int n;
int j = 0;

int print() {
	vector<double>::iterator it;
	for (it = vecDouble2.begin(); it != vecDouble.end(); ++it) {
		cout << *it;
	}
	return 0;
}

int search() {
	int k;
	for (int i = 0; i < n;i++) {
		/*sort(vecDouble2.begin(), vecDouble2.end());*/
		if (vecDouble[i] > vecDouble[i + 1]) {
			for (k = 0; k <= i - j; k++) {
				vecDouble2[j] = vecDouble[i] + vecDouble2[j];
			}
			j++;
		}
	}
	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >>vecDouble[i];
		/*vecDouble2[i] = vecDouble[i];*/
	}
	search();
	print();

	return 0;
}