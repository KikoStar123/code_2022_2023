#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class DoubleQueue;
template <typename T>
class Node
{
    T info;
    Node *link;

public:
    Node(T data = 0, Node *l = NULL)
    {
        info = data;
        link = l;
    }
    friend class DoubleQueue;
};

template <typename T>
class DoubleQueue
{
    Node<T> *front, rear;

public:
    DoubleQueue();
    ~DoubleQueue();
    void MakeEmpty();
};

int main()
{

    return 0;
}