#include <iostream>
#include <vector>
using namespace std;

class Student
{
public:
    Student(string id, string name)
    {
        strId = id;
        strName = name;
    }

    virtual void print() {}

protected:
    string strId;
    string strName;
};

class USstudent : public Student
{
public:
    USstudent(string id, string name, double Credits, bool result) : Student(id, name)
    {
        dCredits = Credits;
        bResult = result;
    }

    void print()
    {
        if (bResult)
            cout << strId << ' '<<strName << ' ' << dCredits << ' ' << bResult << endl;
    }

protected:
    double dCredits;
    bool bResult;
};

class GStudent : public USstudent
{
public:
    GStudent(string id, string name, double Credits, bool teaching, bool research, bool result)
        : USstudent(id, name, Credits, result)
    {
        bTeaching = teaching;
        bResearch = research;
    }

    void print()
    {
        if (bResult)
            cout << strId << ' ' << strName << ' ' << dCredits << ' ' << bTeaching << ' ' << bResearch << ' ' << bResult << endl;
    }

private:
    bool bTeaching;
    bool bResearch;
};

int main()
{
    vector<Student *> s(4);
    s[0] = new USstudent("1001", "Donald", 156, 1);
    s[1] = new USstudent("1002", "Vivion", 142, 0);
    s[2] = new GStudent("2003", "Chris", 36, 1, 1, 1);
    s[3] = new GStudent("2004", "Cindy", 38, 1, 1, 1);


    //ofstream ofile;
    //ofile.open("studentGraduate.data");
    for (int i = 0; i < s.size(); i++)
    {
        s[i]->print();
    }
    //ofile.close();

    for (int i = 0; i < s.size(); i++)
    {
        delete s[i];
    }
    return 0;
}