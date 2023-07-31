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
        hanoi(n - 1, source, target, temp); //��n-1�����Ӱᵽ�м������
        move(source, target);               //�����һ�����ӰᵽĿ������
        hanoi(n - 1, temp, source, target); //��n-1�����ӰᵽĿ������
    }
}
int main()
{
    int n;
    cout << "����������:" << endl;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}