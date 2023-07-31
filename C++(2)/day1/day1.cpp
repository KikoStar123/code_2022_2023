#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int cal();
int main()
{
    cal();
    return 0;
}
int cal()
{
    int a, b, c;
    double d = 0;
    cout << "输入a,b,c的值" << endl;
    cout << "a=";
    cin >> a;
    cout << "b=";
    cin >> b;
    cout << "c=";
    cin >> c;
    if (a == 0)
    {
        cout << "该方程组不是二元一次方程" << endl;
        cout << "请重新输入" << endl;
        cal();
        return 0;
    }
    d = b * b - 4 * a * c;
    if (d == 0 || d > 0)
    {
        cout << "第一个解为" << fixed << setprecision(6) << ((-b + sqrt(d)) / 2 * a) << endl;
        cout << "第二个解为" << fixed << setprecision(6) << ((-b - sqrt(d)) / 2 * a) << endl;
        cout << "结束请输入0,继续请输入其它" << endl;
        int i = 0;
        cin >> i;
        if (i == 0)
        {
            cout << "运算结束";
            return 0;
        }
        else
        {
            cal();
            return 0;
        }
    }
    if (d < 0)
    {
        cout << "该方程无解" << endl;
        cout << "请重新输入" << endl;
        cal();
        return 0;
    }
}
