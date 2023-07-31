/*
 * @Author: your name
 * @Date: 2022-04-21 11:58:32
 * @LastEditTime: 2022-04-21 11:58:32
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1099\cow.h
 */
#include <iostream>
class cow
{
private:
    int weight = 0;
    int age = 0;

public:
    cow(int we, int ag)
    {
        weight = we;
        age = ag;
    }
    void nurse()
    {
        weight += 20;
        age += 1;
    }
    void eat()
    {
        weight += 50;
        age += 1;
    }
    void out()
    {
        weight -= 40;
        age += 1;
    }
    void output()
    {
        cout << weight << " ";
    }
    void calculation()
    {
        while (age <= 12 * 10)
        {
            if (age > 12)
            {
                eat();
                out();
            }
            else
                nurse();
        }
    }
};