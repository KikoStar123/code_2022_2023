/*
 * @Author: KIKOSTAR 842544563@outlook.com
 * @Date: 2023-03-02 21:26:03
 * @LastEditors: KIKOSTAR 842544563@outlook.com
 * @LastEditTime: 2023-04-26 18:33:32
 * @FilePath: \CODE\C++(2)\1098\1098.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;

class Score
{
private:
    int No;
    char Name[8];
    int Math;
    int Phi;
    int Com;
    int Sum;

public:
    void Show()
    {
        Sum = Phi + Math + Com;
        cout << "No:" << No << endl;
        cout << "Name:" << Name << endl;
        cout << "Math:" << Math << endl;
        cout << "Phi:" << Phi << endl;
        cout << "Com:" << Com << endl;
        cout << "Total:" << Sum << endl;
    }

    Score(int N = 1)
    {
    }

    Score(int N, char *name, int math, int phi)
    {
        No = N;
        for (int i = 0; i < 8; i++)
        {
            Name[i] = name[i];
        }
        Math = math;
        Phi = phi;
    }

    Score(int N, char *name, int math, int phi, int com)
    {
        No = N;
        for (int i = 0; i < 8; i++)
        {
            Name[i] = name[i];
        }
        Math = math;
        Phi = phi;
        Com = com;
    }

    Score(Score &a)
    {
        No = a.No;
        for (int i; i < 8; i++)
        {
            Name[i] = a.Name[i];
        }
        Math = a.Math;
        Phi = a.Phi;
        Com = a.Com;
    }

    void Input()
    {
        cin >> No >> Name >> Math >> Com >> Phi;
    }
};

int main()
{
    int No;
    char Name[8];
    int Math;
    int Phi;
    int Com;
    int Sum;
    
    cin >> No >> Name >> Math >> Com >> Phi;
    Score s(No, Name, Math, Phi, Com);
    Score a(s);
    s.Input();
    s.Show();
    return 0;
}