/*
 * @Author: your name
 * @Date: 2022-04-18 16:39:04
 * @LastEditTime: 2022-04-18 17:11:25
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\1143\1143.cpp
 */
#include <iostream>
#include <string>
using namespace std;
int main()
{
    char wordlist[1024];
    string wordlist2[26] = {"A(a)", "B(b)", "C(c)", "D(d)", "E(e)", "F(f)", "G(g)", "H(h)", "I(i)", "J(j)", "K(k)", "L(l)", "M(m)", "N(n)", "O(o)", "P(p)", "Q(q)", "R(r)", "S(s)", "T(t)", "U(u)", "V(v)", "W(w)", "X(x)", "Y(y)", "Z(z)"};
    int wordcount[26] = {0};
    int i = 0;
    int j = 0;
    while (wordlist[i - 1] != '#')
    {
        wordlist[i] = cin.get();
        if (wordlist[i] >= 65 && wordlist[i] <= 90)
        {
            j = wordlist[i] - 65;
            wordcount[j]++;
        }
        else if (wordlist[i] >= 97 && wordlist[i] <= 122)
        {
            j = wordlist[i] - 97;
            wordcount[j]++;
        }
        i++;
    }
    for (int k = 0; k < 26; k++)
    {
        if (wordcount[k] != 0)
            cout << wordlist2[k] << ":" << wordcount[k] << endl;
    }
    return 0;
}