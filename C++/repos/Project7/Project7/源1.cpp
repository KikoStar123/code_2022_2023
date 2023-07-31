#include<iostream>
#include<vector>
#include<cstdio>
#include<iomanip>
#include<algorithm>
using namespace std;
vector<int> crax(200);
vector<int> cray(200);
vector<int> cx(200);
vector<int> ans(200);
int n, tot;

int print() {
	tot++;
	vector<int>::iterator it;
	for (it = ans.begin(); it != ans.end(); ++it) {
		if (*it == 0)continue;
		cout << *it ;
	}
	cout << endl;
	return 0;
}

int search(int x) {
	if (x > n) print();
	for (int y = 1; y <= n; y++) {
		if (cray[x + y])continue;
			if (cray[x - y + 10])continue;
				if (cx[y])continue;
				ans[x] = y;
				crax[x + y] = 1;
				cray[x - y + 10] = 1;
				cx[y] = 1;
				search(x + 1);
				crax[x + y] = 0;
				cray[x - y + 10] = 0;
				cx[y] = 0;

	}
	return 0;
}

int main() {
	cin >> n;
	search(1);
	if (tot == 0)cout << "no solute";
	return 0;
}