/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-03-02 23:29:55
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-03-08 22:15:43
 * @FilePath: \CODE\C++(2)\3_2test.cpp\4_6.cpp\4_6.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string.h>
using namespace std;

class Person
{
private:
    int IdPerson;
    char Name[20];
    char Sex[20];
    char Birthday[20];
    char HomeAddress[20];

public:
    Person(int IdPerson = 0, char *Name = "NaN/0", char *Sex = "NaN/0", char *Birthday = "NaN/0", char *HomeAddress = "NaN/0")
    {
        if (IdPerson == 0)
            input();
        ID(IdPerson);
        getName(Name);
        getSex(Sex);
        getBirth(Birthday);
        getAdd(HomeAddress);
    }
    Person(Person &a)
    {
        IdPerson = a.IdPerson;
        strcpy(Name, a.Name);
        strcpy(Sex, a.Sex);
        strcpy(Birthday, a.Birthday);
        strcpy(HomeAddress, a.HomeAddress);
    }

    int ID(int Id)
    {
        IdPerson = Id;
        return IdPerson;
    }

    char *getName(char name[])
    {
        strcpy(Name, name);
        return Name;
    }

    char *getSex(char sex[])
    {
        strcpy(Sex, sex);
        return Sex;
    }

    char *getBirth(char birth[])
    {
        strcpy(Birthday, birth);
        return Birthday;
    }

    char *getAdd(char Add[])
    {
        strcpy(HomeAddress, Add);
        return HomeAddress;
    }

    void input()
    {
        cout << "ID:" << endl;
        cin >> IdPerson;
        cout << "Name:" << endl;
        cin >> Name;
        cout << "Sex:" << endl;
        cin >> Sex;
        cout << "Birthday:" << endl;
        cin >> Birthday;
        cout << "HomeAddress:" << endl;
        cin >> HomeAddress;
    }

    void output()
    {
        cout << "ID:";
        cout << IdPerson << endl;
        cout << "Name:";
        cout << Name << endl;
        cout << "Sex:";
        cout << Sex << endl;
        cout << "Birthday:";
        cout << Birthday << endl;
        cout << "HomeAddress:";
        cout << HomeAddress << endl;
    }
    ~Person() {}
};

int main()
{
    int IdPerson;
    char Name[20];
    char Sex[20];
    char Birthday[20];
    char HomeAddress[20];
    cout << "ID:" << endl;
    cin >> IdPerson;
    cout << "Name:" << endl;
    cin >> Name;
    cout << "Sex:" << endl;
    cin >> Sex;
    cout << "Birthday:" << endl;
    cin >> Birthday;
    cout << "HomeAddress:" << endl;
    cin >> HomeAddress;
    Person A(IdPerson, Name, Sex, Birthday, HomeAddress); // 对象A外部参数输入
    A.output();                                           // 对象A第一次输出

    cout << "id:" << endl;
    cin >> IdPerson;
    cout << "修改A id" << endl;
    A.ID(IdPerson); // 外部修改ID
    A.output();     // 对象A输出

    Person B(A); // 复制构造
    B.ID(783);   // 外部修改ID
    B.output();  // 对象B输出

    Person C;   // 对象C输入
    C.output(); // 对象C输出
    return 0;
}