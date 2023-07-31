#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class stu;
class stu_list
{
private:
    stu *list[];

public:
    stu_list(stu tempobj)
    {
    }
    stu *&operator[](int index)
    {
        return list[index];
    }
};

class stu
{
private:
    string No;
    string Name;
    string Score;

public:
    stu(string no = 0, string name = 0, string score = 0)
    {
        No = no;
        Name = name;
        Score = score;
    }
    friend ostream &operator<<(ostream &dist, stu &iv);
    friend ostream &operator>>(istream &sour, stu &iv);
};
ostream &operator<<(ostream &dist, stu &iv)
{
    dist << left << setw(10) << iv.No << setw(10) << iv.Name << setw(10) << iv.Score << endl;
    return dist;
}

ostream &operator>>(istream &sour, stu &iv)
{
    if (sour == cin)
    {
        cout<<"No:";
        sour
    }
}

int main()
{

    return 0;
}