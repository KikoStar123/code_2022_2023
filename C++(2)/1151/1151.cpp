#include <iostream>
using namespace std;

typedef char Datatype;

struct node
{
    Datatype info;
    node *link;
}; // 节点定义

node *creatdown()
{
    Datatype data;
    node *head, *tail, *p;
    head = new node;
    tail = head;
    data = cin.get();
    while (data != '\n')
    {
        p = new node;
        p->info = data;
        tail->link = p;
        tail = p;
        data = cin.get();
    }
    tail->link = NULL;
    return head;
} // 向下生成链表

void insert_before(node *head, node *q, Datatype data)
{
    node *curr = head;
    while (curr->link != q && curr != NULL)
        curr = curr->link;
    if (curr == NULL)
        return;
    else
    {
        node *p = new node;
        p->info = data;
        p->link = curr->link;
        curr->link = p;
    }
}

void insert_after(node *q, Datatype data)
{
    node *p = new node;
    p->info = data;
    p->link = q->link;
    q->link = p;
}

void delete_before(node *head, node *q)
{
    node *prev = NULL;
    node *curr = head;
    while (curr->link != q && curr != NULL)
    {
        prev = curr;
        curr = curr->link;
    }
    if (curr == NULL)
        return;
    else
    {
        prev->link = q;
        delete curr;
    }
}

void delete_after(node *q)
{
    node *p;
    p = q->link;
    q->link = p->link;
    delete p;
}

void print(node *head)
{
    node *p;
    p = head->link;
    while (p)
    {
        cout << p->info;
        p = p->link;
    }
}

node *search_t(node *head, Datatype target)
{
    node *tmp = head->link;
    while (tmp->info != target && tmp != NULL)
        tmp = tmp->link;
    return tmp;
}

int main()
{
    node *A = creatdown();
    print(A);
    cout << endl;

    Datatype target;
    cout << "请输入插入/删除位置:";
    cin >> target;

    delete_before(A, search_t(A, target));
    cout << "删除目标之前的元素 链表的遍历：";
    print(A);
    cout << endl;

    delete_after(search_t(A, target));
    cout << "删除目标之后的元素 链表的遍历：";
    print(A);
    cout << endl;

    Datatype data;
    cout << "请输入插入内容：";
    cin >> data;

    insert_before(A, search_t(A, target), data);
    cout << "插入到目标之前 链表的遍历：";
    print(A);
    cout << endl;

    insert_after(search_t(A, target), data);
    cout << "插入到目标之后 链表的遍历：";
    print(A);
    cout << endl;

    return 0;
}