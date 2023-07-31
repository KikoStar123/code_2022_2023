#include <iostream>
#include <cstring>
#include <limits>
using namespace std;

int main()
{
    char str[256];
    int i;
    cout << "请输入整数：" << endl;
    cin >> i;
    while (cin.fail())
    {
        cout << "状态字为：" << cin.rdstate() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 修改：使用limit模板确认流的最大大小
        cout << "输入错误，请重新输入整数：" << endl;
        cin >> i;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "请输入字符串：" << endl;
    cin.getline(str, 255);
    cout << "输入的字符串为：" << str << endl;
    cout << "请确认输入是否正确(Y/N):" << endl;
    char confirm;
    cin >> confirm;
    while (toupper(confirm) != 'Y' && toupper(confirm) != 'N') // toupper转换大写字母
    {
        cout << "输入有误,请重新输入(Y/N):" << endl;
        cin >> confirm;
    }
    if (toupper(confirm) == 'N')
    {
        cout << "请重新输入字符串：" << endl;
        cin.getline(str, 255);
    }
    cout << "输入的整数为：" << i << endl;
    cout << "输入的字符串为：" << str << endl;
    return 0;
}