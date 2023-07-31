#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class Stack
{
    int top;
    T *elements;
    int maxSize;

public:
    Stack(int = 20);
    ~Stack()
    {
        delete[] elements;
    }
    void Push(const T &data); // 压栈
    T Pop();                  // 弹出 top
    T GetElem(int i);         // 取出数据
    void MakeEmpty()          // 清空栈
    {
        top = -1;
    }
    bool IsEmpty() const
    {
        return top == -1;
    }
    bool IsFull() const
    {

        return top == maxSize - 1;
    }
    void PrintStack();
    void StackFull();
    int GetSize()
    {
        return maxSize;
    }
};

template <typename T>
Stack<T>::Stack(int maxs)
{
    maxSize = maxs;
    top = -1;
    elements = new T[maxSize];
    assert(elements != 0);
}

template <typename T>
void Stack<T>::PrintStack()
{
    for (int i = 0; i <= top; i++)
        cout << elements[i] << '\t';
    cout << endl;
}

template <typename T>
void Stack<T>::Push(const T &data)
{
    assert(!IsFull());
    elements[++top] = data;
} // 压栈

template <typename T>
T Stack<T>::Pop()
{
    assert(!IsEmpty());
    return elements[top--];
} // 弹出

template <typename T>
T Stack<T>::GetElem(int i)
{
    assert(i <= top && i >= 0);
    return elements[i];
} // 获取元素

template <typename T>
void Stack<T>::StackFull()
{
    if (IsFull())
    {
        T *tempList = new T[maxSize];
        for (int i = 0; i < maxSize; i++)
            tempList[i] = elements[i];
        delete[] elements;
        maxSize *= 2;
        elements = new T[maxSize];
        for (int i = 0; i < maxSize; i++)
            elements[i] = tempList[i];
        delete[] tempList;
    }
}

int main()
{
    int i;
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[10];
    Stack<int> istack(10);
    for (i = 0; i < 10; i++)
        istack.Push(a[i]);
    istack.PrintStack();
    if (istack.IsFull())
    {
        cout << "栈满" << endl;
        istack.StackFull();
        cout << "栈已经扩展" << endl;
    }
    istack.Push(10);
    istack.PrintStack();
    cout << "此时栈的大小为" << istack.GetSize() << endl;
    
    return 0;
}