#include <iostream>
#include <string>
using namespace std;

class weapon;
class list
{
private:
    weapon *head;
    weapon *tail;

public:
    list()
    {
        head = new weapon;
        tail = head;
    }

    void MakeEmpty()
    {
        weapon *tempP;
        while (head->next != nullptr)
        {
            tempP = head->next;
            head->next = tempP->next;
            delete tempP;
        }
    }

    ~list()
    {
        MakeEmpty();
        delete head;
    }
};

class weapon
{
protected:
    string name;
    int damage;
    weapon *next;
    virtual void print() = 0;
    friend class list;

public:
    weapon(string n, int d) : name(n), damage(d)
    {
        next = NULL;
    }
    virtual ~weapon() {}
};

class knife(string n, int d) : weapon(n, d)
{
}

int main()
{

    return 0;
}