#include <iostream>
using namespace std;

class peoples
{
protected:
    string name;
    char gender;
    int age;

public:
    peoples(string n, char g, int a)
    {
        name = n;
        gender = g;
        age = a;
    }

    virtual void print()
    {
        cout << "name:" << name << ' ';
        cout << "gender:" << gender << ' ';
        cout << "age:" << age << ' ';
        cout << endl;
    }
};

class teachers : public peoples
{
    int ID;
    string title;
    int wage;

public:
    teachers(string n, char g, int a,
             int id, string t, int w) : peoples(n, g, a)
    {
        ID = id;
        title = t;
        wage = w;
    }

    void print()
    {
        cout << "name:" << name << ' ';
        cout << "gender:" << gender << ' ';
        cout << "age:" << age << ' ';
        cout << "ID:" << ID << ' ';
        cout << "title:" << title << ' ';
        cout << "wage:" << wage << ' ';
        cout << endl;
    }
};

class students : public peoples
{
    int ID;
    int classes;
    string major;
    int grade;

public:
    students(string n, char g, int a,
             int id, int c, string m, int grades) : peoples(n, g, a)
    {
        ID = id;
        classes = c;
        major = m;
        grade = grades;
    }

    void print()
    {
        cout << "name:" << name << ' ';
        cout << "gender:" << gender << ' ';
        cout << "age:" << age << ' ';
        cout << "ID:" << ID << ' ';
        cout << "class:" << classes << ' ';
        cout << "major:" << major << ' ';
        cout << "grade:" << grade << ' ';
        cout << endl;
    }
};

int main()
{
    string name;
    char gender;
    int age;
    int ID1;
    string title;
    int wage;
    cin >> name >> gender >> age >> ID1 >> title >> wage;
    teachers A(name, gender, age, ID1, title, wage);
    A.print();

    string name1;
    char gender1;
    int age1;
    int ID2;
    int classes;
    string major;
    int grade;
    cin >> name1 >> gender1 >> age1 >> ID2 >> classes >> major >> grade;
    students B(name1, gender1, age1, ID2, classes, major, grade);
    B.print();

    return 0;
}