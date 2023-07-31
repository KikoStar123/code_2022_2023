/*
 * @Author: your name
 * @Date: 2022-04-21 17:34:42
 * @LastEditTime: 2022-04-21 17:50:33
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\rpg\test.cpp
 */
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string Name[10];
string race[10];
int level[10] = {0};
int ex[10] = {0};
int health[10] = {0};
int attack[10] = {0};
int def[10] = {0};
int speed[10] = {0};
int basic_attack[10] = {0};
int weapon_id = 0;
int pill_id = 0;
int pill_num = 0;
int money[10];
int n = 1;
class ex_geting
{
private:
    int ex_temp = 1000 * pow(1.1, (level[n] - 1) * 1.0);
    int ex_temp2 = 0;
    int get_ex = 0;

public:
    ex_geting(int i)
    {
        get_ex = i;
    }
    void base()
    {
    }
    void calculation()
    {
        string race_list[3] = {"swordman", "dwarf", "shooter"};
        int i = 0;
        while (ex_temp <= get_ex)
        {
            ex_temp2 = ex_temp;
            ex_temp = ex_temp + ex_temp * 1.1;
            i++;
        }
        if (race[n] == race_list[0])
        {
            for (int j = 0; j < i; j++)
            {
                health[n] += 100;
                attack[n] += 20;
                def[n] += 5;
                speed[n] += 10;
                basic_attack[n] += 5;
            }
        }
        if (race[n] == race_list[1])
        {
            for (int j = 0; j < i; j++)
            {
                health[n] += 200;
                attack[n] += 10;
                def[n] += 20;
                speed[n] += 5;
                basic_attack[n] += 4;
            }
        }
        if (race[n] == race_list[2])
        {
            for (int j = 0; j < i; j++)
            {
                health[n] += 150;
                attack[n] += 5;
                def[n] += 10;
                speed[n] += 20;
                basic_attack[n] += 3;
            }
        }
        ex_temp = get_ex - ex_temp2;
        ex[n] = ex[n] + ex_temp;
        level[n] += i;
    }
    void output()
    {
        cout << Name[n] << " " << race[n] << " " << level[n] << " " << int(ex[n]) << " " << health[n] << " " << attack[n] << " " << def[n] << " " << speed[n] << endl;
    }
};

int main()
{
    for (int i = 1; i <= 1; i++)
    {
        cin >> Name[i] >> race[i] >> level[i] >> ex[i] >> health[i] >> attack[i] >> def[i] >> speed[i];
    }
    ex_geting ex1(3000);
    ex1.calculation();
    ex1.output();
    return 0;
}