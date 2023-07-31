/*
 * @Author: KIKOSTAR 842544563@outlook.com
 * @Date: 2023-03-20 20:54:22
 * @LastEditors: KIKOSTAR 842544563@outlook.com
 * @LastEditTime: 2023-03-20 21:12:24
 * @FilePath: \CODE\C++(3)\2021_2.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*Store two user input strings into character arrays. Connect them, change the
punctuation and convert(转换) the lowercase letters(小写字母)
into uppercase letters(大写字母) for output as
follows:
Please input two strings:
Hello C#"!
Happly New Year, 2019!
Ouput:
HELLO C#", HAPPY NEW YEAR, 2019!
*/
#include <iostream>
using namespace std;
int main()
{
    char a[100];
    char b[100];
    cin.getline(a, 100);
    cin.getline(b, 100);
    char *a1 = a;
    char *b1 = b;

    while (*a1 != '\0')
    {
        a1++;
    }
    while (*b1 != '\0')
    {
        *a1 = *b1;
        b1++;
        a1++;
    }
    *a1 = '\0';
    a1 = a;
    while (*a1 != '\0')
    {
        int temp = 'A' - 'a';
        if (*a1 >= 'a' && *a1 <= 'z')
            *a1 += temp;
        a1++;
    }
    a1 = a;
    cout << a1;
    return 0;
}