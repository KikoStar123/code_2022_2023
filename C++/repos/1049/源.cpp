#include<iostream>
using namespace std;
int a = 0;
int b = 0;
int c = 0;
int num = 0;
int main() {
	for (int i = 1; i <1000; i++) {
		a = i/100;//百位
		b = (i - 100 * a)/10;//十位
		c = i%10;//个位
		if ((a<=b && b<=c)||((a==0)&&(b==c-1)&&(b!=0))) {
			num++;
		}
	}
	cout << num<< endl;
	return 0;
}