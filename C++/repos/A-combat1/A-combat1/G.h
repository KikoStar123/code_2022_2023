
#include<iostream>

//��������
void input(int[],int size);
void print(int[], int);
//����ʵ��
void input(int values[],int len) 
{//��������ָ��
	if (len > 5) {
		cout << "Խ��";
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