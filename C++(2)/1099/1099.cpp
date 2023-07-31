/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-03-11 20:02:31
 * @LastEditors: KIKOSTAR 842544563@outlook.com
 * @LastEditTime: 2023-03-13 20:04:33
 * @FilePath: \CODE\C++(2)\1099\1099.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;

class cow
{
private:
	int weight;
	int age;

public:
	cow(int w = 50)
	{
		weight = w;
		age = 0;
	}
	void nurse();
	void eat();
	void milk();
	void print();
	void calculate();
};

void cow::nurse()
{
	weight += 20;
	age += 1;
}
void cow::eat()
{
	weight += 50;
	age += 1;
}
void cow::milk()
{
	weight -= 40;
	age += 1;
}
void cow::print()
{
	cout << weight << endl;
}

void cow::calculate()
{
	while (age <= 120)
	{
		if (age <= 12)
			nurse();
		else
		{
			eat();
			milk();
		}
	}
}

int main()
{
	int weight = 0;
	cin >> weight;
	cow A;
	cow B(weight);
	A.calculate();
	B.calculate();
	B.print();
	A.print();
}