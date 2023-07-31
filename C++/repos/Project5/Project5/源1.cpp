#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
int i, j, k;
int main() {
	int n, m;
	cout << "请输入数字的个数：" << endl;
	cin >> n;
	vector<double> vecDouble(n);
	
	
	for (i = 0; i < n; i++) {
		cin >> vecDouble[i];
	}
	cout << "补充一个数字" << endl;
	cin >> m;
	vecDouble.push_back(m);
	vector<double>::iterator t;
	for (t = vecDouble.begin(); t != vecDouble.end(); ++t) {
		cout << *t << endl;
	}
	k = 0;
	for (i = 0; i <= n; i++) {
		k = k + vecDouble[i];
	}
	cout << "和为：" << k<<endl;
	return 0;
}