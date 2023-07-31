#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
int i;
int main() {
	int arrays[]{ 1,2,3,4,5 };
	int* ptr_start = arrays;//指向第一个元素
	int* ptr_end = arrays + 4;//指向最后一个元素
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
	}//指针移动（++）过不能再次使用；



	/*double score[]{11,22,33,44,55};
	double* ptr_score = score;
	cout << sizeof(score) << "\t" << sizeof(ptr_score) << endl;//指针与数组占用字节数不同
	cout << ptr_score[3] << endl;*/

}