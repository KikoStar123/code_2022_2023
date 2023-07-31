#include<iostream>
#include <cstdio>
#include<vector>
#include<iomanip>
#include<algorithm>

using namespace std;
/*对于给定的一个长度为N的正整数数列A[i]，现要将其分成M（M≤N）段，并要求每段连续，且每段和的最大值最小。
关于最大值最小：
例如一数列4 2 4 5 1要分成3段
将其如下分段：
[4 2][4 5][1]
第一段和为6，第2段和为9，第3段和为1，和最大值为9。
将其如下分段：
[4][2 4][5 1]
第一段和为4，第2段和为6，第3段和为6，和最大值为6。
并且无论如何分段，最大值不会小于6。
所以可以得到要将数列4 2 4 5 1要分成3段，每段和的最大值最小为6。*/

vector<int>vec(200);
vector<int>container1(200);
int n;
int i = 0;
int j = 0;
int search() {

	while (i <n) {
		if vec[i] > vec[i + 1]{
			for (int k = i; k < i - j; k++) {
					container1[j]=container1[j]+
			}
			j++;
			i++;
		}
		else {
			i++;
		}
	}



	/*for (int j = 0; j < n; j++) {
		if vec[i] > vec[i + 1]{
			cout << vec[i];
		}
		else {
			
		}
		    
	}
}
*/

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	search();
}
/*class
{
public:
	();
	~();

private:

};

::()
{
}

::~()
{
}*/