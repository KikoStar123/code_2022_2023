#include <iostream>
using namespace std;
long T2_7(int n);
int T2_9(int *list, int numbers);
bool T2_10(int num);
int main()
{
    // 2.7
    int n;
    cin >> n;
    cout << T2_7(n) << endl;
    // 2.9
    int list[10000];
    int num = 1;
    int index = 0;
    while (num != 0)
    {
        cin >> num;
        list[index] = num;
        index++;
    }
    T2_9(list, index);
    // 2.10
    int i = 1;
    for (i; i <= 500; i++)
    {
        if (T2_10(i))
            cout << i << endl;
    }

    return 0;
}
long T2_7(int n)
{
    long sum = 0;

    for (int i = 1; i <= n; i++)
    {
        int x = 1;
        for (int j = i; j >= 1; j--)
            x *= j;
        sum += x;
    }
    return sum;
}
int T2_9(int *list, int numbers)
{
    double sum = 0;
    int positive_num = 0;
    int negative_num = 0;
    for (int i = 0; i < numbers; i++)
    {
        sum += list[i];
        if (list[i] > 0)
            positive_num += 1;
        if (list[i] < 0)
            negative_num += 1;
    }
    cout << "Average number is:" << sum / (numbers - 1) << endl;
    cout << "The amount of Positive Numbers is:" << positive_num << endl;
    cout << "The amount of Negative Numbers is:" << negative_num << endl;
    return 0;
}
bool T2_10(int num)
{
    if ((num % 3 == 2) && (num % 5 == 3) && (num % 7 == 2))
        return true;
    else
        return false;
}