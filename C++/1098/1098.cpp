/*
 * @Author: your name
 * @Date: 2022-04-21 10:31:23
 * @LastEditTime: 2022-04-21 11:12:50
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\classtest.cpp
 */
#include <iostream>
using namespace std;
class Score
{
private:
    int No = 0;
    string Name;
    int Math = 0;
    int Phi = 0;
    int Com = 0;
    int Sum = 0;

public:
    Score(int a, string b, int c, int d, int e)
    {
        No = a;
        Name = b;
        Math = c;
        Phi = d;
        Com = e;
    }
    int get_No() { return No; }
    string get_Name() { return Name; }
    int get_Math() { return Math; }
    int get_Phi() { return Phi; }
    int get_Com() { return Com; }
    int get_Sum()
    {
        Sum = Math + Phi + Com;
        return Sum;
    }
};

int main()
{
    int a, c, d, e;
    string b;
    cin >> a >> b >> c >> d >> e;
    Score s(a, b, c, d, e);
    cout << "No:" << s.get_No() << endl;
    cout << "Name:" << s.get_Name() << endl;
    cout << "Math:" << s.get_Math() << endl;
    cout << "Phi:" << s.get_Phi() << endl;
    cout << "Com:" << s.get_Com() << endl;
    cout << "Total:" << s.get_Sum() << endl;
}