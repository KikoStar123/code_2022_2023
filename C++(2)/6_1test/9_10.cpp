/*
 * @Author: KIKOSTAR 842544563@outlook.com
 * @Date: 2023-06-01 09:48:27
 * @LastEditors: KIKOSTAR 842544563@outlook.com
 * @LastEditTime: 2023-06-01 10:33:33
 * @FilePath: \CODE\C++(2)\6_1test\9_10.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <bitset>

using namespace std;

void read_from_binary_file(bool reverse = false)
{
    ifstream in("binary.txt", ios::binary);
    in.seekg(0, ios::end);
    int size = in.tellg();
    in.seekg(0, ios::beg);
    int i = reverse ? size - 1 : 0;
    int step = reverse ? -1 : 1;
    while (i >= 0 && i < size)
    {
        bitset<8> bits;
        in.read((char *)&bits, sizeof(bits));
        int n = bits.to_ulong();
        if (n != 0)
        {
            cout.width(6);
            cout << n;
        }
        if ((i + 1) % 10 == 0)
            cout << endl;
        i += step;
    }
    in.close();
}

int main()
{
    ofstream txt("text.txt");
    ofstream binary_txt("binary.txt", ios::binary);
    int i, j, a[100];
    for (i = 0; i < 100; i++)
        a[i] = i + 1;
    a[0] = 0;
    for (i = 0; i < 100; i++)
        for (j = i + 1; j < 100; j++)
        {
            if (a[i] != 0 && a[j] != 0)
                if (a[j] % a[i] == 0)
                    a[j] = 0;
        }

    for (i = 0, j = 0; i < 100; i++)
    {
        if (a[i] != 0)
        {
            j++;
            txt.width(6);
            txt << left << a[i];
            binary_txt.write((const char *)&a[i], sizeof(a[i]));
            if (j % 10 == 0)
                txt << endl;
        }
    }

    txt.close();
    binary_txt.close();

    cout << "正序读取二进制文件：" << endl;
    read_from_binary_file(false);
    cout << endl
         << "逆序读取二进制文件：" << endl;
    read_from_binary_file(true);
    return 0;
}