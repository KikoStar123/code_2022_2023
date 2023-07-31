#include <iostream>
using namespace std;

class MyString
{
private:
    char *list;
    int size;

public:
    MyString(char *str)
    {
        size = strlen(str);
        list = new char[size + 1];
        strcpy(list, str);
    }

    MyString(char *str, int size)
    {
        list = new char[size + 1];
        strcpy(list, str);
    }

    MyString()
    {
        list = new char[1];
    }
};

int main()
{

    return 0;
}