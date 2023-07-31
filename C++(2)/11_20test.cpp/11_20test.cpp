#include <iostream>
using namespace std;
int main()
{
    int a1 = 123;
    double a2 = 123.123;
    char a3 = 'a';
    int *p1 = &a1;
    double *p2 = &a2;
    char *p3 = &a3;
    cout << "第一组目标值：" << a1 << "第一组目标地址:" << &a1 << endl;
    cout << "第一组指针值：" << *p1 << "第一组指针地址:" << p1 << endl;
    cout << "第一组指针所占字节长度" << sizeof(p1) << endl;
    cout << "第二组目标值：" << a2 << "第二组目标地址:" << &a2 << endl;
    cout << "第二组指针值：" << *p2 << "第二组指针地址:" << p2 << endl;
    cout << "第二组指针所占字节长度" << sizeof(p2) << endl;
    cout << "第三组目标值：" << a3 << "第三组目标地址:" << &a3 << endl;
    cout << "第三组指针值：" << *p3 << "第三组指针地址:" << p3 << endl;
    cout << "第三组指针所占字节长度" << sizeof(p3) << endl;
}