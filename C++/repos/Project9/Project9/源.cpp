#include<iostream>
#include <cstdio>
#include<vector>
#include<iomanip>
#include<algorithm>

using namespace std;
/*���ڸ�����һ������ΪN������������A[i]����Ҫ����ֳ�M��M��N���Σ���Ҫ��ÿ����������ÿ�κ͵����ֵ��С��
�������ֵ��С��
����һ����4 2 4 5 1Ҫ�ֳ�3��
�������·ֶΣ�
[4 2][4 5][1]
��һ�κ�Ϊ6����2�κ�Ϊ9����3�κ�Ϊ1�������ֵΪ9��
�������·ֶΣ�
[4][2 4][5 1]
��һ�κ�Ϊ4����2�κ�Ϊ6����3�κ�Ϊ6�������ֵΪ6��
����������ηֶΣ����ֵ����С��6��
���Կ��Եõ�Ҫ������4 2 4 5 1Ҫ�ֳ�3�Σ�ÿ�κ͵����ֵ��СΪ6��*/

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