#include <iostream>
#include <string>
using namespace std;
int get_ex;
string Name;
string race;
int level = 0;
int ex = 0;
int health = 0;
int attack = 0;
int def = 0;
int speed = 0;
int basic_attack = 0;
int weapon_id = 0;
int pill_id = 0;
int pill_num = 0;
int money = 10000;
int output()
{
    cout << Name << " " << race << " " << level << " " << int(ex) << " " << health << " " << basic_attack << " " << attack << " " << def << " " << speed << endl;
    return 0;
}
int takeoff()
{
    return 0;
}

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
            if (num * 1000 > money)
                num = money / 1000;
            for (int k = 0; k < num; k++)
            {
                health += 800;
            }
            break;
        }
        case 2:
        {
            if (num * 1000 > money)
                num = money / 1000;
            for (int k = 0; k < num; k++)
            {
                basic_attack += 5;
                attack += 10;
                def += 10;
                speed += 10;
                health += 100;
            }
            break;
        }
        case 3:
        {
            if (num * 1000 > money)
                num = money / 1000;
            for (int k = 0; k < num; k++)
            {
                basic_attack += 5;
                attack += 30;
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
            attack += 100;
            def += 20;
            speed += 20;
            health += 500;
            money -= 5000;
            weapon_set();
            break;
        }
        case 2:
        {
            attack += 20;
            def += 100;
            speed += 20;
            health += 1000;
            money -= 5000;
            weapon_set();
            break;
        }
        case 3:
        {
            attack += 20;
            def += 20;
            speed += 100;
            health += 300;
            money -= 5000;
            weapon_set();
            break;
        }
        default:;
        }
    }
};

class ex_geting
{
private:
    double ex_temp = 1000;
    double ex_temp2 = 0;

public:
    ex_geting(string a, string b, int c, int d, int e, int f, int g, int h)
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
        if (race == race_list[0])
        {
            for (int j = 0; j < i; j++)
            {
                health += 100;
                attack += 20;
                def += 5;
                speed += 10;
                basic_attack += 5;
            }
        }
        if (race == race_list[1])
        {
            for (int j = 0; j < i; j++)
            {
                health += 200;
                attack += 10;
                def += 20;
                speed += 5;
                basic_attack += 4;
            }
        }
        if (race == race_list[2])
        {
            for (int j = 0; j < i; j++)
            {
                health += 150;
                attack += 5;
                def += 10;
                speed += 20;
                basic_attack += 3;
            }
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
    // cin >> Name >> race >> level >> ex >> health >> attack >> def >> speed;
    //  cin >> get_ex;
    cin >> Name >> race >> level >> ex >> health >> basic_attack >> attack >> def >> speed;
    cin >> weapon_id;
    cin >> pill_id;
    cin >> pill_num;
    output();
    weapon weapon1(weapon_id);
    weapon1.weapon_calculation();
    output();
    pill pill1(pill_id, pill_num);
    pill1.pill_calculation();
    output();
    ex_geting ex1(Name, race, level, ex, health, attack, def, speed);
    // ex1.calculation();
    // ex1.output();
    return 0;
}