#include <iostream>
using namespace std;

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

class node
{
    weapon *data;
    node *next;

public:
    node() : next(NULL) {}
    node(weapon *d) : data(d), next(NULL) {}
    ~node() {}
    friend class list;
};

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

    /*void insertRear(weapon *p)
    {
        p->next = tail->next;
        tail->next = p;
        tail = p;
    }*/

    void insert(weapon *w)
    {
        node *p = head, *q = nullptr;
        while (p != nullptr)
        {
            q = p;
            p = p->next;
        }
        node *r = new node(w);
        if (q == nullptr)
            head = r;
        else
            q->next = r;
        r->next = p;
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
        cout << class_name << " name:" << name << " damage:" << damage << endl;
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
        cout << class_name << " name:" << name << " damage:" << damage << endl;
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
        cout << class_name << " name:" << name << " damage:" << damage << endl;
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
            A.insert(new knife(name, damage));
        if (class_name == "sword")
            A.insert(new sword(name, damage));
        if (class_name == "stick")
            A.insert(new stick(name, damage));
        cin >> class_name;
    }
    A.print();
    return 0;
}