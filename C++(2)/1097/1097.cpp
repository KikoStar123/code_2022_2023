/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-12-03 23:14:04
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-12-15 14:41:27
 * @FilePath: \CODE\C++(2)\1097\1097.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

string str = "LoadAccelerators";
char *Str_Reverse(char *list)
{
    char *temp = list;
    int len = strlen(list);
    for (int i = 0; i < len / 2; i++)
    {
        char templist = list[i];
        list[i] = list[len - 1 - i];
        list[len - 1 - i] = templist;
    }

    return temp;
}

char *Longnumbers_sum(char *lista, char *listb, char *listc)
{
    int lenA = strlen(lista);
    int lenB = strlen(listb);
    int Len_diffs = int(abs(lenA - lenB));
    if (lenB > lenA)
    {
        char *temp = lista;
        lista = listb;
        listb = temp;
        swap(lenA, lenB);
    }

    for (int i = 0; i <= lenA; i++)
        listc[i] = '0';
    listc[lenA + 1] = '\0';
    char *tempc = listc;
    char *tempb = listb;
    for (int i = 0; i < lenB; i++)
    {
        *(listc + Len_diffs) = *listb;
        listc++;
        listb++;
    }
    listb = tempc;
    listc = tempb;
    char *tempa = lista;
    tempb = listb;
    tempc = listc;
    while (*lista != '\0')
    {
        *listc = *lista + *listb - '0';
        listc++;
        listb++;
        lista++;
    }
    listc = tempc;
    Str_Reverse(listc);
    int acc = 0;
    while (*listc != '\0')
    {
        if (*listc > '9')
        {
            acc++;
            int num = *listc - '0';
            if (acc < lenA)
                *(listc + 1) += (num / 10);
            else
                *(listc + 1) += ((num / 10) + '0');
            *listc = num % 10 + '0';
        }
        listc++;
    }
    Str_Reverse(tempc);
    return tempc;
}

int main()
{
    char lista[100];
    char listb[100];
    char listc[100];
    cin.getline(lista, 100);
    cin.getline(listb, 100);
    cout << Longnumbers_sum(lista, listb, listc) << endl;
    return 0;
}