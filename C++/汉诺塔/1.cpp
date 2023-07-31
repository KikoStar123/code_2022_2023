#include <iostream>
using namespace std;
void move(char source, char target)
{
    cout << source << "->" << target << endl;
}
void hanoi(int n, char source, char temp, char target)
{
    if (n == 1)
        move(source, target);
    else
    {
        hanoi(n - 1, source, target, temp); //将n-1个盘子搬到中间的柱子
        move(source, target);               //将最后一个盘子搬到目标柱子
        hanoi(n - 1, temp, source, target); //将n-1个盘子搬到目标柱子
    }
}
int main()
{
    int n;
    cout << "输入盘子数:" << endl;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}