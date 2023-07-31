#include <iostream>
using namespace std;

class weapon;

class list
{
private:
    node *head;
    node *tail;

public:
    list()
    {
        head = new node;
        tail = head;
    }

    void MakeEmpty()
    {
        node *tempP;
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

    void insertRear(node *p)
    {
        p->next = tail->next;
        tail->next = p;
        tail = p;
    }

    void print()
    {
        node *tempP = head->next;
        while (tempP != NULL)
        {
            tempP->data->print();
            tempP = tempP->next;
        }
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

class knife : public weapon
{
private:
    string class_name;

public:
    knife(string n, int d) : weapon(n, d)
    {
        next = NULL;
        class_name = "knife";
    }
    ~knife() {}

    void print()
    {
        cout << class_name << ' ' << name << ' ' << damage << endl;
    }
};

class sword : public weapon
{
private:
    string class_name;

public:
    sword(string n, int d) : weapon(n, d)
    {
        next = NULL;
        class_name = "sword";
    }
    ~sword() {}
    void print()
    {
        cout << class_name << ' ' << name << ' ' << damage << endl;
    }
};

class stick : public weapon
{
private:
    string class_name;

public:
    stick(string n, int d) : weapon(n, d)
    {
        next = NULL;
        class_name = "stick";
    }
    ~stick() {}
    void print()
    {
        cout << class_name << ' ' << name << ' ' << damage << endl;
    }
};

int main()
{
    string class_name;
    string name;
    list A;
    int damage;
    cin >> class_name;
    while (class_name != "END")
    {
        cin >> name >> damage;

        if (class_name == "knife")
        {
            knife temp(name, damage);
            node new_node(&temp);
            A.insertRear(new_node);
        }
        if (class_name == "sword")
        {
            knife temp(name, damage);
            node new_node(&temp);
        }
        if (class_name == "stick")
        {
            stick temp(name, damage);
            node new_node(&temp);
        }
    }
    return 0;
}