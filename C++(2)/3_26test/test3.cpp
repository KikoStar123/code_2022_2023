#include <iostream>
#include <string.h>
using namespace std;

template <typename T>
class String
{
protected:
    T *_data;

public:
    int _size;
    String()
    {
        _data = new char[1];
        _data[0] = 0;
        _size = 0;
    }

    String(const T *str)
    {
        _size = strlen(str);
        _data = new char[_size + 1];
        char *pTemp = _data;
        while (*str != '\0')
            *_data++ = *str++;
        *_data = '\0';
        _data = pTemp;
    }
    String(T *data, int length)
    {
        T pTemp = _data += length;
        pTemp = data;
        _size += length;
    }
    String(const String &right)
    {
        _size = right._size;
        _data = new char[_size + 1];
        strcpy(_data, right._data);
    }

    ~String() {}

    void operator=(String &right)
    {
        delete[] _data;
        _size = right._size;
        _data = new char[_size + 1];
        strcpy(_data, right._data);
    }
    void operator+=(const String &right)
    {
        char *pTemp = new char[_size + right._size + 1];
        strcpy(pTemp, _data);
        strcpy(pTemp + _size, right._data);
        delete[] _data;
        _data = pTemp;
        _size += right._size;
    }
    void operator+=(const T *str)
    {
        int len = strlen(str);
        char *pTemp = new char[_size + len + 1];
        strcpy(pTemp, _data);
        strcpy(pTemp + _size, str);
        delete[] _data;
        _data = pTemp;
        _size += len;
    }
    void operator+(const T *str)
    {
        int len = strlen(str);
        char *pTemp = new char[_size + len + 1];
        strcpy(pTemp, _data);
        strcpy(pTemp + _size, str);
        delete[] _data;
        _data = pTemp;
        _size += len;
    }
    void operator=(const T *str)
    {
        delete[] _data;
        _size = strlen(str);
        _data = new char[_size + 1];
        strcpy(_data, str);
    }
    String operator+(const String &right)
    {
        char *pData = new char[_size + right._size + 1];
        strcpy(pData, _data);
        strcpy(pData + _size, right._data);
        return String(pData, _size + right._size);
    }
    bool operator!=(const String &right) const
    {
        if (_size != right._size)
            return false;
        while (*_data != '\0')
        {
            if (_data != right._data)
                return false;
        }
        return true;
    }
    // bool operator!=(char) const{

    //}

    char &operator[](int index)
    {
        return _data[index];
    }

    template <typename T1>
    int BinarySearch(T1 &x, const int low, const int high)
    {

        int mid = -1;
        if (low <= high)
        {
            mid = (low + high) / 2;
            if (_data[mid] < x)
                mid = BinarySearch(x, mid + 1, high);
            else if (x < _data[mid])
                mid = BinarySearch(x, low, mid - 1);
        }
        return mid;
    }

    void _Sort();
    T _In_Max();
    int Append(const T &x);
    int Remove(int i);
    void Reverse();

    /*void _Sort()
    {
        char *slist = _data;
        int last = _size;
        bool noswap;
        int i, j;
        char temp;
        for (i = 0; i < last; i++)
        {
            noswap = true;
            for (j = last; j > i; j--)
            {
                if (slist[j] < slist[j - 1])
                {
                    temp = slist[j];
                    slist[j] = slist[j - 1];
                    slist[j - 1] = temp;
                    noswap = false;
                }
            }
            if (noswap)
                break;
        }
        _data = slist;
    }*/

    void print()
    {
        for (int i = 0; i < _size; ++i)
            cout << _data[i] << " ";
    }
};

template <typename T>
T String<T>::_In_Max()
{
    int i = 0;
    T max = _data[i];
    T pTemp = _data[i];
    while (pTemp != '\0')
    {
        if (pTemp > max)
            max = _data[i];
        i++;
        pTemp = _data[i];
    }
    return max;
}

template <typename T>
void String<T>::_Sort()
{
    T temp;
    int i, j;
    for (i = 1; i <= _size - 1; i++)
    {
        temp = _data[i];
        j = i;
        while (j > 0 && temp < _data[j - 1])
        {
            _data[j] = _data[j - 1];
            j--;
        }
        _data[j] = temp;
    }
}

template <typename T>
int String<T>::Append(const T &x)
{
    char *pData = new char[_size + 1];
    strcpy(pData, _data);
    char *pData2 = pData;
    while (*pData2 != '\0')
        pData2++;
    *pData2 = char(x);
    pData2++;
    *pData2 = '\0';
    delete[] _data;
    _data = pData;
    _size++;
    return 1;
}

template <typename T>
int String<T>::Remove(int i)
{
    char *pData = new char[_size - 1];
    char *pData2 = pData;
    char *pData3 = _data;
    for (int j = 0; j < i; j++)
        *pData++ = *pData3++;
    pData3++;
    while (*pData3 != '\0')
        *pData++ = *pData3++;
    *pData = '\0';
    delete[] _data;
    _data = pData2;
    _size--;
    return 1;
}

template <typename T>
void String<T>::Reverse()
{
    char *pData = new char[_size];
    for (int i = 0; i < _size; i++)
    {
        pData[_size - 1 - i] = _data[i];
    }
    pData[_size] = '\0';
    _data = pData;
}

int main()
{
    /*String<char> A = "1293898734987192387";
    A._Sort();
    A.print();
    cout << endl;
    cout << "max:" << endl;
    char max;
    max = char(A._In_Max());
    cout << max << endl;
    int result;
    char target;
    // cout << "target:";
    // cin >> target;
    target = '4';
    result = A.BinarySearch(target, 0, A._size - 1);
    cout << "result:" << result + 1 << endl;

    A.Append('4');
    A.print();
    cout << endl;
    A.Remove(2);
    A.print();
    cout << endl;
    A.Reverse();
    A.print();
    cout << endl;*/

    char a[6];
    int n, m;
    char max;
    for (int i = 0; i < 5; i++)
        cin >> a[i];
    cin >> m;
    cin >> n;
    a[6] = '\0';
    String<char> A(a);
    A.print();
    cout << endl;

    A.Append(m + '0');
    A.print();
    cout << endl;

    A.Remove(n);
    A.print();
    cout << endl;

    A.Reverse();
    A.print();
    cout << endl;

    max = A._In_Max();
    cout << max;
    return 0;
}