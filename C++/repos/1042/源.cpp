#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main()
{
	char a[255];
	char k;
	int i = 0;
	int num = 0;
	while (cin>>k)
	{
		a[++i] = k;
		if (a[i-1]>='0'&&a[i]<='9')
		{
			num++;
		}
	}
	cout << num << endl;
	/*char string;
	cin >> string;
	int i = 0;
	i = string.size();
	int j = 0;
	int num=0;
	for (j = 0; j < 7; j++) {
		if (string[j] >= '0' && string[j] <= '9') {
			num++;
		}
	}
	cout << num << endl;*/
		
}