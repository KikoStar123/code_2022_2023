#pragma once
#include <Windows.h>
using namespace std;
void gotoxy(int x, int y) {           //����ƶ�:�޸�����ַ�������Ļ�ϵ�λ��  (�ο�:)  �˺��������봮�����������Լ�DBM_PIGEON��֧��           
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);            //1.�ҵ�����̨���������
	COORD coord;                                                //2.���Ľṹ��
	coord.X = x; coord.Y = y;                                   //3.���ù������� 
	SetConsoleCursorPosition(handle, coord);                    //4.���ÿ���̨���λ��                              
}//�������� ������� ���廭��
