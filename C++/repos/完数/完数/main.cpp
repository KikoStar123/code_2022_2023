#include<stdio.h>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int i, j, s, n;  /*����i����ѡ������Χ��j���Ƴ�����Χ��s��¼�ۼ�����֮��*/
    cout << "��������ֵ�ķ�Χ";
    cin >> n;
    for (i = 2; i <= n; i++)
    {
        s = 0;  /*��֤ÿ��ѭ��ʱs�ĳ�ֵΪ0*/
        for (j = 1; j < i; j++)
        {
            if (i % j == 0)  /*�ж�j�Ƿ�Ϊi������*/
                s = s + j;
        }
        if (s == i)  /*�ж���������Ƿ��ԭ�����*/
            cout << "it's a perfect number:" << i << endl;
    }
    return 0;
}