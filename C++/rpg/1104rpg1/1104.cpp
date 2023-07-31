/*
 * @Author: your name
 * @Date: 2022-04-21 12:35:56
 * @LastEditTime: 2022-04-21 13:18:20
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\rpg\1104rpg1\1104.cpp
 */
#include <iostream>
using namespace std;
int get_ex;
class digit
{
private:
    string Name;
    string race;
    int level;
    int ex;
    int health;
    int attack;
    int def;
    int speed;

public:
    digit(string a, string b, int c, int d, int e, int f, int g, int h)
    {
        Name = a;
        race = b;
        level = c;
        ex = d;
        health = e;
        attack = f;
        def = g;
        speed = h;
    }
    void base()
    {
    }
    void culculation()
    {
        double ex_temp = 1000;
        double ex_temp2 = 0;
        int i = 0;
        while (ex_temp <= get_ex)
        {
            ex_temp2 = ex_temp;
            ex_temp = ex_temp + ex_temp * 1.1;
            i++;
        }
        for (int j = 0; j < i; j++)
        {
            health += 150;
            attack += 5;
            def += 10;
            speed += 20;
        }
        ex_temp = get_ex - ex_temp2;
        ex = ex + ex_temp;
        level += i;
    }
    void output()
    {
        cout << Name << " " << race << " " << level << " " << int(ex) << " " << health << " " << attack << " " << def << " " << speed << endl;
    }
};

int main()
{
    string Name;
    string race;
    int level;
    int ex;
    int health;
    int attack;
    int def;
    int speed;
    cin >> Name >> race >> level >> ex >> health >> attack >> def >> speed;
    cin >> get_ex;
    digit game1(Name, race, level, ex, health, attack, def, speed);
    game1.culculation();
    game1.output();
    return 0;
}