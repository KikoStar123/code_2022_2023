#include <iostream>
#include <string>
using namespace std;
template <class T, int size>
class LIST
{
private:
    T _data[size];
    int _size;

public:
    LIST(T *l)
    {
        T *pTemp = _data;
        while (*l != '\0')
            *pTemp++ = *l++;
        *pTemp = '\0';
        _size = size;
    }
    void MPsort();
    void print();
};

template <class T, int size>
void LIST<T, size>::MPsort()
{
    bool noswap;
    int i, j;
    T temp;
    for (int i = 0; i < _size; i++)
    {
        noswap = true;
        for (j = _size-1; j > i; j--)
        {
            if (_data[j] > _data[j - 1])
            {
                temp = _data[j];
                _data[j] = _data[j - 1];
                _data[j - 1] = temp;
                noswap = false;
            }
        }
        if (noswap)
            break;
    }
}

template <class T, int size>
void LIST<T, size>::print()
{
    for (int i = 0; i < _size; i++)
        cout << _data[i] << ' ';
    cout << endl;
}

int main()
{
    char a[18] = {'s', 'd', 'c', 'd', 'g', 'r', 'w', 'j', 'c', 'g', 'w', 'q', 'b', 'c', 'm', 'c', 'i', 'p'};
     LIST<char, 18> A(a);
    A.print();
    A.MPsort();
    A.print();
    return 0;
}