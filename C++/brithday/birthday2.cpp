#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define N 10           //���������ɫ
#define Time 202004270 //��ʱ��
//________________________________________________________________________________________________________________
//�������
const int A1 = 131;
const int A2 = 147;
const int A3 = 165;
const int A4 = 175;
const int A5 = 196;
const int A6 = 220;
const int A7 = 247;

//��������
const int B1 = 262;
const int B2 = 296;
const int B3 = 330;
const int B4 = 349;
const int B5 = 392;
const int B6 = 440;
const int B7 = 494;

//�������
const int C1 = 523;
const int C2 = 587;
const int C3 = 659;
const int C4 = 698;
const int C5 = 784;
const int C6 = 880;
const int C7 = 988;

//����߶���
const int D1 = 1047;
const int D2 = 1175;
const int D3 = 1319;
const int D4 = 1397;
const int D5 = 1568;
const int D6 = 1760;
const int D7 = 1976;

//�������
const int OneBeat = 600;
const int HalfBeat = 300;
//___________________________________________________________
char randk();
void cake();
void PrintHeart();
bool delay500ms();
string blessing[20] = {"�� ��Ϊ���ռ��˱�����е��������������յ���̨�ϡ�����˵�Ļ������ڻ����������Ϊ���ŵ����ܡ�",
                       "�� ������Խ��Խ����,�����Ļ�Խ��Խ����,�������յ���һ��,������Ҷ��������ף����",
                       "�� Ը�������յ�������,������ɫ�ĳ���,��ɫ���λ�......",
                       "�� ����ͷ׵�����,ֻ�����������,�����������������,ף�����!",
                       "�� ��������������/�����Ļ�һ��/����¶���Ļ�/�����ʶ����ɵ�����װ�㡣",
                       "�� �������������ʱ����������Ը�������ǻ�����ʵ�ʱ����������Ը����д��������ʱ����Ҳ������Ը��Ը���ڿ�����������һ���Ҹ����֣�",
                       "�� ����������һ��,�����ֵ�����,��Ϊ�����͸���",
                       "�� Ը��ӵ��365�����������ӣ����ĵ�ף����--���տ��֣�",
                       "�� �Լ������� �Լ�������/���ǹ�ͬ��������Ȼ/����/��/������",
                       "�� ֻ�ж���������ˣ����������ʻ��Ľ��ޣ�ֻ�ж��ð����ˣ��������Ե����зҷ���ף����һ���ر�����ա�",
                       "�� �������µĽ���/һ��С�ܶ���/һ�ж�����������/������ʱ����΢פ��/�ٻ�ͷ/����һ����β����ظ���/�ഺ��",
                       "�� ���������ϲ�õ����������ףԸ���ഺ��פ��Ը��һ��������ϲ�����Ĵ����㣬���տ��֣�",
                       "�� ���տ���! /��ס! ��������ÿһ���﷫����/�ҵ�ף���������ͬ��!",
                       "�� Ը��һ�������õ�ףԸ,Ƕ���⿨Ƭ��,ף����---����,����,΢Ц��",
                       "�� �����һ��,����һ������,����һ�ݳ���,����һ���ǻۣ�",
                       "�� Ը������հ������Ҹ���ϲ��,���ճ������䣡",
                       "                                                                    ��һ����,Ī������\n",
                       "                                                                    2020.4-7"};

long f = 0;
char s[10] = "color ";
//________________________________________________________________________________________________________________
int main()
{
    int i = 0;
    puts("\n\n\n\n\n\n\n\n\n\n ");
    for (i = 0; i < N; i++) //Ҫ��ɫ�Ĵ���
    {
        s[6] = randk();
        s[7] = randk();
        system(s); //����cmd��color����
        printf("\r                                                  ��!���տ���!��");
        while (f < 81474400)
            f = f + 1;
    }
    putchar('\n');
    cake();
    int T = 1;
    while (T--)
    {
        Beep(C5, HalfBeat);
        Beep(C5, HalfBeat);
        Beep(C6, OneBeat);
        Beep(C5, OneBeat);
        Beep(D1, OneBeat);
        Beep(C7, OneBeat * 2);

        Beep(C5, HalfBeat);
        Beep(C5, HalfBeat);
        Beep(C6, OneBeat);
        Beep(C5, OneBeat);
        Beep(D2, OneBeat);
        Beep(D1, OneBeat * 2);

        Beep(C5, HalfBeat);
        Beep(C5, HalfBeat);
        Beep(D5, OneBeat);
        Beep(D3, OneBeat);
        Beep(D1, OneBeat);
        Beep(C7, OneBeat);

        Beep(D4, HalfBeat);
        Beep(D4, HalfBeat);
        Beep(D3, OneBeat);
        Beep(D1, OneBeat);
        Beep(D2, OneBeat);
        Beep(D1, OneBeat * 2);

        Beep(C5, HalfBeat);
        Beep(C5, HalfBeat);
        Beep(D5, OneBeat);
        Beep(D3, OneBeat);
        Beep(D1, OneBeat);
        Beep(C7, HalfBeat);
        Beep(C6, OneBeat * 2);

        Beep(D4, HalfBeat);
        Beep(D4, HalfBeat);
        Beep(D3, OneBeat);
        Beep(D1, OneBeat);
        Beep(D2, OneBeat);
        Beep(D1, OneBeat * 3);

        Sleep(500);
    }
    puts("\n\n\n���װ��ľ���:\n\n\n");
    s[6] = 'b'; //����Ϊ����ɫ��
    for (int i = 0; i < 20; i++)
    {
        s[7] = randk();
        system(s);
        printf("\n");
        cout << blessing[i] << endl;
        f = delay500ms();
    }
    printf("\n\t\t\t  ");
    system("PAUSE"); //��ͣ
    system("cls");   //����
    PrintHeart();
    printf("\n\t\t\t  ");
    system("PAUSE");
    system("cls");
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t  лл����   Happy birthday����\n");
    getchar();
    return 0;
}
char randk() //���������
{
    char a = 0;
    a = (char)abs(rand() % 16);
    if (a >= 10)
    {
        a -= 10;
        a += 97;
    }
    else
        a += 48;

    return a;
}
float ff(float x, float y, float z)
{
    float a = x * x + 9.0f / 4.0f * y * y + z * z - 1;
    return a * a * a - x * x * z * z * z - 9.0f / 80.0f * y * y * z * z * z;
}

float hh(float x, float z)
{
    for (float y = 1.0f; y >= 0.0f; y -= 0.001f)
        if (ff(x, y, z) <= 0.0f)
            return y;
    return 0.0f;
}
void PrintHeart() //����
{
    for (float z = 1.5f; z > -1.5f; z -= 0.05f)
    {
        for (float x = -1.5f; x < 1.5f; x += 0.025f)
        {
            float v = ff(x, 0.0f, z);
            if (v <= 0.0f)
            {
                // s[7]=randk();
                // system(s);
                float y0 = hh(x, z);
                float ny = 0.01f;
                float nx = hh(x + ny, z) - y0;
                float nz = hh(x, z + ny) - y0;
                float nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
                float d = (nx + ny - nz) * nd * 0.5f + 0.5f;
                putchar(".:-=+*#%@"[(int)(d * 5.0f)]);
            }
            else
                putchar(' ');
        }
        putchar('\n');
        f = delay500ms();
    }
}
bool delay500ms()
{
    while (f < Time)
    {
        f = f + 1;
        f = f - 1;
        f = f + 1;
    }
    return 0;
}
void cake()
{
    printf("                                                         !  !  !\n");
    printf("                                                     ---------\n");
    printf("                                                    |��С����ʦ ��|\n");
    printf("                                                  -------------\n");
    printf("                                                  | �� �� �� �� |\n");
    printf("                                               -----------------\n");
    printf("                                               | 2020                |\n");
    printf("                                               |�� �� �� �� �� �� ��|\n");
}
