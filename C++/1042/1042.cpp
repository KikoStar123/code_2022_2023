/*
 * @Author: your name
 * @Date: 2022-04-12 15:13:11
 * @LastEditTime: 2022-04-12 15:17:40
 * @LastEditors: Please set LastEditors
 * @Description: ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1042\1042.cpp
 *
 * ��Ŀ����
�Ӽ�������һ���������ֺ������ַ��ķ��ţ��Իس���Ϊ��ֹ��ǣ�ͳ�����������ַ��ĸ�����

������ab12CD34###�������������4����

ע�������ַ��������ԶԵ����ַ����������ظ������룬���жϸô�������ַ��Ƿ����Ҫ�󣬷�����ֹѭ����

����
һ���ַ������Իس�����ֹ��

���
�ַ������������ַ��ĸ���
 */

#include <iostream>
using namespace std;
int main()
{
    char c = cin.get(); //��ûس�����//ѭ���ĳ�ʼ����
    int count = 0;
    while (c != '\n')
    {
        if (c >= '0' && c <= '9') //ѭ������
            ++count;
        c = cin.get(); //��������
    }
    cout << count << endl;
    return 0;
}