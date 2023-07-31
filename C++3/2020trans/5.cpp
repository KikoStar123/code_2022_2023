#include<iostream>
using namespace std;

template<class T>
class slistNode
{
    public:
    slistNode(){next=NULL;}//初始化
    T data;//值
    slistNode* next;//指向下一个节点的指针
};

template<class T>
class myslist
{
    private:
        unsigned int listlength;
        slistNode<T>* getnode;//临时节点
        slistNode<T>* lastnode;//尾结点
        slistNode<T>* headnode;//头节点
    public:
        myslist();//初始化
        unsigned int length(){
            return listlength;
        }//链表元素的个数
        void add(T x){
            slistNode<T>* newnode=new slistNode<T>;
            newnode->data=x;
            newnode->next=NULL;
            if(listlength==0){
                headnode=newnode;
                lastnode=newnode;
            }
            else{
                lastnode->next=newnode;
                lastnode=newnode;
            }
            listlength++;
        }//表尾添加元素
        void traversal(){
            slistNode<T>* p=headnode;
            while(p!=NULL){
                cout<<p->data<<" ";
                p=p->next;
            }
            cout<<endl;
        }//遍历整个链表并打印
        bool isEmpty(){
            return listlength==0;
        }//判断链表是否为空
        slistNode<T>* find(T x){
            slistNode<T>* p=headnode;
            while(p!=NULL){
                if(p->data==x){
                    return p;
                }
                p=p->next;
            }
            return NULL;
        }//查找第一个值为x的节点,返回节点的地址,找不到返回NULL
        void Delete(T x){
            slistNode<T>* p=headnode;
            slistNode<T>* q=NULL;
            while(p!=NULL){
                if(p->data==x){
                    q=p;
                    break;
                }
                p=p->next;
            }
            if(q!=NULL){
                if(q==headnode){
                    headnode=headnode->next;
                }
                else{
                    q->next=q->next->next;
                }
                delete q;
                listlength--;
            }
        }//删除第一个值为x的节点
        void insert(T x,slistNode<T>* p){
            slistNode<T>* newnode=new slistNode<T>;
            newnode->data=x;
            newnode->next=p->next;
            p->next=newnode;
            listlength++;
        }
        void insertHead(T x){
            slistNode<T>* newnode=new slistNode<T>;
            newnode->data=x;
            newnode->next=NULL;
            if(listlength==0){
                headnode=newnode;
                lastnode=newnode;
            }
            else{
                headnode->next=newnode;
                headnode=newnode;
            }
            listlength++;
        }

};
// Task 1: Create a template class Queue inheriting from the myslist class
template<class T>
class Queue : public myslist<T> {
public:
    void enqueue(T x) {
        this->add(x); // Adding an element to the end of the queue using the add() function from myslist
    }
    
    void dequeue() {
        if (!this->isEmpty()) {
            this->Delete(this->headnode->next->data); // Deleting the first element of the queue using the Delete() function from myslist
        }
    }
    
    T front() {
        if (!this->isEmpty()) {
            return this->headnode->next->data; // Returning the value of the first element in the queue
        }
        throw std::runtime_error("Queue is empty."); // Throw an exception if the queue is empty
    }
    
    unsigned int size() {
        return this->length(); // Returning the number of elements in the queue using the length() function from myslist
    }
};

// Task 2: Create a template class Queue using composition
template<class T>
class QueueComposition {
private:
    myslist<T> list;
public:
    void enqueue(T x) {
        list.add(x); // Adding an element to the end of the queue using the add() function from myslist
    }
    
    void dequeue() {
        if (!list.isEmpty()) {
            list.Delete(list.headnode->next->data); // Deleting the first element of the queue using the Delete() function from myslist
        }
    }
    
    T front() {
        if (!list.isEmpty()) {
            return list.headnode->next->data; // Returning the value of the first element in the queue
        }
        throw std::runtime_error("Queue is empty."); // Throw an exception if the queue is empty
    }
    
    unsigned int size() {
        return list.length(); // Returning the number of elements in the queue using the length() function from myslist
    }
};

// Task 3: Create a template function and demonstrate its usage
template<typename T>
void demonstrateQueue() {
    Queue<T> charQueue;
    charQueue.enqueue('a');
    charQueue.enqueue('b');
    charQueue.enqueue('c');
    
    std::cout << "Char Queue: ";
    while (charQueue.size() > 0) {
        std::cout << charQueue.front() << " ";
        charQueue.dequeue();
    }
    std::cout << std::endl;
    
    Queue<T> intQueue;
    intQueue.enqueue(1);
    intQueue.enqueue(2);
    intQueue.enqueue(3);
    
    std::cout << "Int Queue: ";
    while (intQueue.size() > 0) {
        std::cout << intQueue.front() << " ";
        intQueue.dequeue();
    }
    std::cout << std::endl;
}

int main() {
    demonstrateQueue<char>(); // Demonstrating with a char queue
    demonstrateQueue<int>(); // Demonstrating with an int queue
    
    return 0;}
