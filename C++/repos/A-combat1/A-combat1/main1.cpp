#include<iostream>
#include<cstdio>
#include<iomanip>
#include<ctime>
#include<vector>
#include<array>
#include<cmath>
#include<string>
#include"G.h";

using namespace std;

int sum(int, int);//函数原型
void calcCylinder();
void ch(int& c) {
	c++;//形参无返回值原参不变，但带地址的可以；
}

int main()
{
	string value_f_name;
	string value_d_name;
	int value_brith_date;
	int value_brith_month	;
	string value_d_constell;
	int usingname = 0;
	while (usingname)
	{
		int result = sum(5, 6);
		cout << result << endl;
		calcCylinder();
		int c = 10;
		ch(c);
		cout << c;
	}
	int values[5];
	input(values, sizeof(values)/sizeof(int);
}

int sum(int num1, int num2) {
	int result = num1 + num2;
	return result;
}//先进行函数定义再进行函数执行内容；

void calcCylinder() {
	double radius, height;
	cin >> radius >> height;
	//输入半径和高；
	double pi = 4 * atan(1.0);
	double v = pi * pow(radius, 2) * height;
	cout << v;
}







