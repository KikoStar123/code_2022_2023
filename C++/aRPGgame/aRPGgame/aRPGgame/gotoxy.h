#pragma once
#include <Windows.h>
using namespace std;
void gotoxy(int x, int y) {           //光标移动:修改输出字符的在屏幕上的位置  (参考:)  此函数及代码串来自于网络以及DBM_PIGEON的支持           
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);            //1.找到控制台的这个窗口
	COORD coord;                                                //2.光标的结构体
	coord.X = x; coord.Y = y;                                   //3.设置光标的坐标 
	SetConsoleCursorPosition(handle, coord);                    //4.设置控制台光标位置                              
}//基础函数 用于输出 定义画布
