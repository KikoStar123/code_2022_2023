/*
 * @Author: KIKOSTAR 842544563@outlook.com
 * @Date: 2023-05-18 19:54:32
 * @LastEditors: KIKOSTAR 842544563@outlook.com
 * @LastEditTime: 2023-05-18 20:02:46
 * @FilePath: \CODE\C++(3)\2022年转专业考试\1.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
void sort(T a[])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 9; j > i; j--)
        {
            if (a[j] < a[j - 1])
            {
                T temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}

template <typename T>
int search(T *list, T target)
{
    for (int i = 0; i < 10; i++)
    {
        if (target == list[i])
            return i + 1;
    }
}

template <typename T>
void print(T &a)
{
    for (int i = 0; i < 10; i++)
        cout << a[i] << ' ';
}

int main()
{
    int a[10];
    string b[10];
    srand(time(0));
    for (int i = 0; i < 10; i++)
        a[i] = rand() % 101;
    for (int i = 0; i < 10; i++)
        cin >> b[i];

    sort(a);
    sort(b);
    print(a);
    cout<<endl;
    print(b);

    int a1;
    cin >> a1;
    string b1;
    cin >> b1;

    cout << search(a, a1) << endl;
    cout << search(b, b1) << endl;
    return 0;
}