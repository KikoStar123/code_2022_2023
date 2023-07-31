/*
 * @Author: your name
 * @Date: 2022-04-21 12:35:56
 * @LastEditTime: 2022-04-21 18:48:50
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\rpg\1104rpg1\1104.cpp
 */
#include <iostream>
#include <string>
#include <cmath>
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

int output()
{
    cout << Name[n] << " " << race[n] << " " << level[n] << " " << int(ex[n]) << " " << health[n] << " " << basic_attack[n] << " " << attack[n] << " " << def[n] << " " << speed[n] << endl;
    return 0;
}
int takeoff()
{
    return 0;
}

class ex_geting
{
private:
    int ex_temp = 0;
    int ex_temp2 = 0;
    int get_ex = 0;
    int n1 = 0;

public:
    ex_geting(int i, int k)
    {
        get_ex = i;
        n1 = k;
        ex_temp = 1000 * pow(1.1, (level[n1] - 1) * 1.0);
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
        if (race[n1] == race_list[0])
        {
            for (int j = 0; j < i; j++)
            {
                health[n1] += 100;
                attack[n1] += 20;
                def[n1] += 5;
                speed[n1] += 10;
                basic_attack[n1] += 5;
            }
        }
        if (race[n1] == race_list[1])
        {
            for (int j = 0; j < i; j++)
            {
                health[n1] += 200;
                attack[n1] += 10;
                def[n1] += 20;
                speed[n1] += 5;
                basic_attack[n1] += 4;
            }
        }
        if (race[n1] == race_list[2])
        {
            for (int j = 0; j < i; j++)
            {
                health[n1] += 150;
                attack[n1] += 5;
                def[n1] += 10;
                speed[n1] += 20;
                basic_attack[n1] += 3;
            }
        }
        ex_temp = get_ex - ex_temp2;
        ex[n1] = ex[n1] + ex_temp;
        level[n1] += i;
    }
    void output()
    {
        cout << Name[n1] << " " << race[n1] << " " << level[n1] << " " << int(ex[n1]) << " " << health[n1] << " " << attack[n1] << " " << def[n1] << " " << speed[n1] << endl;
    }
};
class pk
{
private:
    int damage = 0;
    int damage2 = 0;
    bool atb = true;
    bool awin = false;
    bool bwin = false;
    int health_left = 0;
    int surplus_health = health[n], surplus_health2 = health[n + 1];
    int health_start = health[n], health_start2 = health[n + 1];

public:
    pk(int i) {}
    void judgement()
    {
        if (speed[n] >= speed[n + 1])
        {
            if (speed[n] == speed[n + 1])
            {
                if (ex[n] >= ex[n + 1])
                {
                    if (ex[n] == ex[n + 1])
                        ;
                }
                else
                    atb = false;
            }
            else
                ;
        }
        else
            atb = false;
    }

    void fire1() // a attack b
    {
        if (attack[n] > def[n + 1])
            damage = int(basic_attack[n] + (attack[n] - def[n + 1] + 20) * speed[n] / (speed[n] + speed[n + 1]));
        else
            damage = int(basic_attack[n] + 20 * speed[n] / (speed[n] + speed[n + 1]));
    }
    void fire2() // b attack a
    {
        if (attack[n + 1] > def[n])
            damage2 = int(basic_attack[n + 1] + (attack[n + 1] - def[n] + 20) * speed[n + 1] / (speed[n] + speed[n + 1]));
        else
            damage2 = int(basic_attack[n + 1] + 20 * speed[n + 1] / (speed[n] + speed[n + 1]));
    }
    int output()
    {
        if (awin)
        {
            cout << Name[n] << " " << race[n] << " " << level[n] << " " << int(ex[n]) << " " << health_left << " " << basic_attack[n] << " " << attack[n] << " " << def[n] << " " << speed[n] << endl;
            cout << Name[n + 1] << " DEAD" << endl;
        }
        if (bwin)
        {
            cout << Name[n] << " DEAD" << endl;
            cout << Name[n + 1] << " " << race[n + 1] << " " << level[n + 1] << " " << int(ex[n + 1]) << " " << health_left << " " << basic_attack[n + 1] << " " << attack[n + 1] << " " << def[n + 1] << " " << speed[n + 1] << endl;
        }
        return 0;
    }
    void fire_progression()
    {
        judgement();
        while (surplus_health2 > 0 && surplus_health > 0)
        {
            if (atb)
            {
                fire1();
                surplus_health2 = surplus_health2 - damage;
                atb = false;
            }
            else
            {
                fire2();
                surplus_health = surplus_health - damage2;
                atb = true;
            }
            if (surplus_health <= 0)
                bwin = true;
            if (surplus_health2 <= 0)
                awin = true;
            if (awin || bwin)
            {
                if (awin)
                {
                    ex_geting ex1(health[n + 1], n);
                    ex1.calculation();
                    health_left = health[n] - health_start + surplus_health;
                    output();
                }
                else
                {
                    ex_geting ex2(health[n], n + 1);
                    ex2.calculation();
                    health_left = health[n + 1] - health_start2 + surplus_health2;
                    output();
                }
                break;
            }
        }
    }
};

class pill
{
private:
    string pill_name;
    int id = 0;
    int num = 0;

public:
    pill(int i, int j)
    {
        id = i;
        num = j;
    }
    void pill_calculation()
    {
        switch (id)
        {
        case 1:
        {
            if (num * 1000 > money[n])
                num = money[n] / 1000;
            for (int k = 0; k < num; k++)
            {
                health[n] += 800;
            }
            break;
        }
        case 2:
        {
            if (num * 1000 > money[n])
                num = money[n] / 1000;
            for (int k = 0; k < num; k++)
            {
                basic_attack[n] += 5;
                attack[n] += 10;
                def[n] += 10;
                speed[n] += 10;
                health[n] += 100;
            }
            break;
        }
        case 3:
        {
            if (num * 1000 > money[n])
                num = money[n] / 1000;
            for (int k = 0; k < num; k++)
            {
                basic_attack[n] += 5;
                attack[n] += 30;
            }
            break;
        }
        }
    }
};

class weapon
{
private:
    string weapon_name;
    int weapon_num = 0;
    int id;

public:
    weapon(int a)
    {
        id = a;
    }
    void weapon_set()
    {
        weapon_num++;
    }
    void weapon_price()
    {
    }
    void weapon_calculation()
    {
        switch (id)
        {
        case 1:
        {
            attack[n] += 100;
            def[n] += 20;
            speed[n] += 20;
            health[n] += 500;
            money[n] -= 5000;
            weapon_set();
            break;
        }
        case 2:
        {
            attack[n] += 20;
            def[n] += 100;
            speed[n] += 20;
            health[n] += 500;
            1000;
            money[n] -= 5000;
            weapon_set();
            break;
        }
        case 3:
        {
            attack[n] += 20;
            def[n] += 20;
            speed[n] += 100;
            health[n] += 300;
            money[n] -= 5000;
            weapon_set();
            break;
        }
        default:;
        }
    }
};

int main()
{
    for (int i = 0; i < 10; i++)
    {
        money[i] = 10000;
    }
    // cin >> Name >> race >> level >> ex >> health >> attack >> def >> speed;
    //  cin >> get_ex;
    for (int i = 1; i <= 2; i++)
    {
        cin >> Name[i] >> race[i] >> level[i] >> ex[i] >> health[i] >> basic_attack[i] >> attack[i] >> def[i] >> speed[i];
    }

    /*cin >> weapon_id;
cin >> pill_id;
cin >> pill_num;
output();
weapon weapon1(weapon_id);
weapon1.weapon_calculation();
output();
pill pill1(pill_id, pill_num);
pill1.pill_calculation();
output();
ex_geting ex1(3000);*/
    // ex1.calculation();
    // ex1.output();
    pk fire(ex[n]);
    fire.fire_progression();
    return 0;
}