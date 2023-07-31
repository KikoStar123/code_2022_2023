
#include<iostream>

//函数定义
void input(int[],int size);
void print(int[], int);
//函数实现
void input(int values[],int len) 
{//传递数组指针
	if (len > 5) {
		cout << "越界";
		return;
	}
	string valueNames[] = { "one","two","three","four","five"};
	for (int i = 0; i <= len; i++) {
		cout << valueNames[i] << ":";
		cin >> values[i];
	}
}

void print(int values[], int len) {
	string valueNames[] = { "one","two","three","four","five" };
	for (int i = 0; i <= len; i++) {
		cout << valueNames[i] << ":"<<values[i];
		
	}
}