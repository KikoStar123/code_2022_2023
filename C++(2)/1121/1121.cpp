#include <iostream>
using namespace std;

template <typename T>
class List;
template <typename T>
class Node
{
    T info;
    Node<T> *link;

public:
    Node();
    Node(const T &data);
    void InsertAfter(Node<T> *P);
    Node<T> *RemoveAfter();
    T GetInfo();
    friend class List<T>;
};

template <typename T>
Node<T>::Node()
{
    link = NULL;
}

template <typename T>
Node<T>::Node(const T &data)
{
    info = data;
    link = NULL;
}

template <typename T>
void Node<T>::InsertAfter(Node<T> *p)
{
    p->link = link;
    link = p;
}

template <typename T>
Node<T> *Node<T>::RemoveAfter()
{
    Node<T> *tempP = link;
    if (link == NULL)
        tempP = NULL;
    else
        link = tempP->link;
    return tempP;
}

template <typename T>
T Node<T>::GetInfo()
{
    return info;
}

template <typename T>
class List
{
private:
    Node<T> *head, *tail;

public:
    void MakeEmpty()
    {
        Node<T> *tempP;
        while (head->link != NULL)
        {
            tempP = head->link;
            head->link = tempP->link;
            delete tempP;
        }
        tail = head;
    }
    List()
    {
        head = tail = new Node<T>;
    }
    ~List()
    {
        MakeEmpty();
        delete head;
    }
    List(List &S);           // 复制构造函数
    void operator=(List &S); // 重载赋值运算符
    int Length();            // 链表元素长度
    Node<T> *GetLast(T);
    void PrintList();
    void InsertRear(Node<T> *p);    // 在表尾添加一个节点
    void InsertFront(Node<T> *p);   // 在表头插入一个节点
    void InsertOrder(Node<T> *p);   // 向前生成链表
    Node<T> *CreatNode(T data);     // 创建孤立节点
    void DeleteNode(Node<T> *p);    // 删除指定节点
    void DeleteSpecialNode(T data); // 删除指定值的节点
    void reverse();                 // 链表的倒序
};

template <typename T>
int List<T>::Length()
{
    Node<T> *tempP = head->link;
    int count = 0;
    while (tempP != NULL)
    {
        tempP = tempP->link;
        count++;
    }
    return count;
}

template <typename T>
void List<T>::PrintList()
{
    Node<T> *tempP = head->link;
    while (tempP != NULL)
    {
        cout << tempP->info << ' ';
        tempP = tempP->link;
    }
    cout << endl;
}

template <typename T>
void List<T>::InsertRear(Node<T> *p)
{
    p->link = tail->link;
    tail->link = p;
    tail = p;
} // 在表尾添加一个节点

template <typename T>
void List<T>::InsertFront(Node<T> *p)
{
    p->link = head->link;
    head->link = p;
    if (tail == head)
        tail = p;
} // 在表头插入一个节点

template <typename T>
void List<T>::InsertOrder(Node<T> *p)
{
    Node<T> *tempP = head->link;
    Node<T> *tempQ = head;
    while (tempP != NULL)
    {
        if (p->info < tempP->info)
            break;
        tempQ = tempP;
        tempP = tempP->link;
    }
    tempQ->InsertAfter(p);
    if (tail == tempQ)
        tail = tempQ->link;
} // 升序生成链表

template <typename T>
Node<T> *List<T>::CreatNode(T data)
{
    Node<T> *tempP = new Node<T>(data);
    return tempP;
} // 创建孤立节点

template <typename T>
Node<T> *List<T>::GetLast(T i)
{
    int length = Length();
    Node<T> *tempP = head;
    if (i > length)
        return NULL;
    for (int j = 0; j < length - i + 1; ++j)
        tempP = tempP->link;
    return tempP;
}

template <typename T>
void List<T>::DeleteNode(Node<T> *p)
{
    Node<T> *tempP = head->link;
    Node<T> *tempQ = head;
    while (tempP != NULL && tempP != p)
    {
        tempQ = tempP;
        tempP = tempP->link;
    }
    if (tempP == NULL)
        return;
    tempQ->link = tempP->link;
    delete tempP;
    return;
} // 删除指定节点

template <typename T>
void List<T>::DeleteSpecialNode(T data)
{
    Node<T> *tempP = head->link;
    Node<T> *tempQ = new Node<T>;
    while (tempP != NULL)
    {
        if (tempP->info == data)
        {
            tempQ = tempP->link;
            DeleteNode(tempP);
            tempP = tempQ;
        }
        else
            tempP = tempP->link;
    }
}

template <typename T>
List<T>::List(List &S)
{
    head = tail = new Node<T>;
    Node<T> *tempP = S.head->link;
    Node<T> *newnode;
    List<T> newlist;
    while (tempP != NULL)
    {
        newnode = CreatNode(tempP->info);
        InsertRear(newnode);
        tempP = tempP->link;
    }
} // 复制构造函数

template <typename T>
void List<T>::operator=(List &S)
{
    MakeEmpty();
    Node<T> *tempP = S.head->link;
    Node<T> *newnode;
    List<T> newlist;
    while (tempP != NULL)
    {
        newnode = CreatNode(tempP->info);
        InsertRear(newnode);
        tempP = tempP->link;
    }
} // 重载赋值运算符

template <typename T>
void List<T>::reverse()
{
    Node<T> *prevNode = head;              // 游标的前一个
    Node<T> *currentNode = prevNode->link; // 指向每一个节点，游标
    Node<T> *nextNode = currentNode->link; // 游标的后一个

    for (currentNode; currentNode != NULL; currentNode = nextNode) // 每次循环对应一个节点
    {
        nextNode = currentNode->link;
        currentNode->link = prevNode;
        prevNode = currentNode;
    }

    Node<T> *tempP = tail;
    while (tempP != head->link)
    {
        tempP = tempP->link;
    }
    tempP->link = NULL;
    head->link = tail;
    tail = tempP;   
}

/*void List<T>::reverse()
{
    Node<T> *prevNode = head;
    Node<T> *currentNode = head->link;
    Node<T> *nextNode = currentNode->link;
    while (nextNode != NULL)
    {
        currentNode->link=nextNode->link;
        nextNode->link=prevNode->link;
        prevNode->link=currentNode;
        nextNode=currentNode->link;
    }
}*/
/*{
    Node<T> *prevNode = NULL;
    Node<T> *currentNode = head;
    Node<T> *nextNode = NULL;
    while (nextNode != NULL)
    {
        nextNode = currentNode->link;
        currentNode->link = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
}*/

int main()
{
    // 1124第一题数据测试
    /*List<int> list1;
    Node<int> *p;
    int data;
    cin >> data;
    while (data != -1)
    {
        p = list1.CreatNode(data);
        list1.InsertRear(p);
        cin >> data;
    }
    /*int target_index;
    Node<int> *target;
    cin >> target_index;
    target = list1.GetLast(target_index);
    // if (target != NULL)
    cout << target->GetInfo();*/

    /*P264 7.3题删除所有指定值节点数据测试
    int t;
    cin >> t;
    list1.DeleteSpecialNode(t);
    list1.PrintList();*/

    // 第二题测试数据
    /*List<int> p1;
    List<int> p2;
    Node<int> *p;
    int data;
    cin >> data;
    while (data != -1)
    {
        p = p1.CreatNode(data);
        p1.InsertRear(p);
        cin >> data;
    }
    cin >> data;
    while (data != -1)
    {
        p = p2.CreatNode(data);
        p2.InsertRear(p);
        cin >> data;
    }

    List<int> p3(p1);
    p2 = p1;
    p1.PrintList();
    p2.PrintList();
    p3.PrintList();*/

    // 第三题测试数据
    List<int> p1;
    Node<int> *p;
    int data;
    cin >> data;
    while (data != -1)
    {
        p = p1.CreatNode(data);
        p1.InsertRear(p);
        cin >> data;
    }
    p1.reverse();
    p1.PrintList();

    return 0;
}
