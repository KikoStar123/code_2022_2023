#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
int i;
int main() {
	int arrays[]{ 1,2,3,4,5 };
	int* ptr_start = arrays;//ָ���һ��Ԫ��
	int* ptr_end = arrays + 4;//ָ�����һ��Ԫ��
	int temp;
	while (ptr_start != ptr_end) {
		temp = *ptr_start;
		*ptr_start = *ptr_end;
		*ptr_end = temp;
		ptr_start++;
		ptr_end--;
	}

	for (i = 0; i < 5; i++) {
		cout << arrays[i] << endl;
	}
	/*int i;
	int arrays[]{ 1,2,3,4,5 };
	int* p_arrays = arrays;
	for (i = 0; i < 5; i++) {
		cout << *p_arrays+i << endl;
	}//ָ���ƶ���++���������ٴ�ʹ�ã�



	/*double score[]{11,22,33,44,55};
	double* ptr_score = score;
	cout << sizeof(score) << "\t" << sizeof(ptr_score) << endl;//ָ��������ռ���ֽ�����ͬ
	cout << ptr_score[3] << endl;*/

}