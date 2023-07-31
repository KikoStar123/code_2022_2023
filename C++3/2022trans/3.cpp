#include <iostream>
#include <string.h>
using namespace std;

class Date
{
private:
    int year, month, day;

public:
    Date(int y = 0, int m = 0, int d = 0)
    {
        year = y;
        month = m;
        day = d;
    }
    void print()
    {
        cout << year << '-' << month << '-' << day << endl;
    }
};

class Items
{
private:
    char item_name[20];
    double price;
    int number;

public:
    Items(char *name = "",  int num = 0,double p = 0.0)
    {
        int i = 0;
        while (*name != '\0')
        {
            item_name[i++] = *name++;
        }
        item_name[i] = '\0';

        price = p;
        number = num;
    }

    double amount()
    {
        return double(number) * price;
    }

    void print()
    {
        cout << "itemName:" << item_name << ' ';
        cout << "number:" << number << ' ';
        cout << "price:" << price << ' ';
        cout << "amount:" << double(number) * price << endl;
    }
};

class Customer
{
private:
    string ID;
    Date dt;
    Items *list[20];
    int Item_account;
    double totalPrice;

public:
    Customer(string id, Date d)
    {
        ID = id;
        dt = d;
        Item_account = 0;
        totalPrice = 0.0;
    }

    void selectItem(char *item, int number, double p)
    {
        list[Item_account] = new Items(item, number, p);
        totalPrice += list[Item_account++]->amount();
    }
    void print()
    {
        cout << "Customer ID:" << ID << endl;
        cout << "Purchase Date:";
        dt.print();
        cout << "The Purchase items are listed as follows:" << endl;
        for (int i = 0; i < Item_account; i++)
        {
            cout << i + 1 << ':' << ' ';
            list[i]->print();
        }
        cout << "The total amount of the Purchase items is " << totalPrice << endl;
    }
};

int main()
{
    Date dt(2022, 6, 18);
    Customer c1("11000001", dt);
    c1.selectItem("cup", 2, 9.2);
    c1.selectItem("jacket", 1, 50);
    c1.selectItem("steak", 3, 10);
    c1.print();
    return 0;
}