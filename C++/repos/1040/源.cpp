/*
 * @Author: your name
 * @Date: 2022-03-30 11:04:08
 * @LastEditTime: 2022-03-30 21:47:41
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\repos\1040\源.cpp
 */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int i, j, n;
	int year_list[10];
	int temp1, temp2;
	cin >> n;
	temp1 = n - 4;
	j = 8;
	for (i = 0; i < 9; i++) {
		if ((temp1 % 4 == 0) && (temp1 % 100 != 0) || (temp1 % 400 == 0))
		{
			year_list[j] = temp1;
			j++;
		}
		temp1++;
	}
	year_list[6] = abs(year_list[8] - n);
	year_list[7] = abs(year_list[9] - n);
	if (year_list[6] < year_list[7]) {
		cout << year_list[8] << endl;
	}
	else if(year_list[6] == year_list[7]){
		cout << year_list[8] << " " << year_list[9];
	}
	else {
		cout << year_list[9] << endl;
	}
	return 0;
}