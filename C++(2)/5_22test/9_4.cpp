#include <iostream>
using namespace std;

int main()
{
    char str[256];
    int i;
    int flag1 = 0;
    int flag2 = 0;

    while (!flag1)
    {
        cout << "请输入整数：" << ' ';
        cout << "是否确认输入？(是/1 否/0):";
        cin >> i >> flag1;
        if (flag1)
        {
            while (cin.fail())
            {
                cout << "状态字为：" << cin.rdstate() << endl;
                cin.clear();
                cin.getline(str, 255);
                cout << "输入错误，请重新输入整数" << endl;
                cin >> i;
            }
        }
    }

    cin.getline(str, 256);
    cout << "请输入字符串" << endl;
    cin.getline(str, 255);
    cout << "输入整数为" << i << endl;
    cout << "输入字符串为：" << str << endl;
    return 0;
}