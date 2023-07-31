#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

class Shopping_list;

class Goods // 商品类
{
private:
    string id;         // 商品代号
    string goods_name; // 商品名称
    float price;       // 价格
    int num;           // 数量
public:
    Goods(string = "***", string = "***", float = 0, int = 0); // 缺省构造函数
    void Registe(string, string, float, int);                  // 设置函数,重新设置各成员的值
    friend istream &operator>>(istream &in, Goods &g);         // 提取运算符重载
    friend ostream &operator<<(ostream &out, Goods &g);        // 插入运算符重载
    friend class Shopping_list;                                // 设立友元类
};

Goods::Goods(string i, string na, float pr, int n) : id(i), goods_name(na)
{
    price = pr, num = n;
}

void Goods::Registe(string i, string na, float pr, int n)
{
    id = i;
    goods_name = na;
    price = pr;
    num = n;
}

istream &operator>>(istream &in, Goods &g)
{ // 在此补充本段代码,如果从键盘输入时，在屏幕给出提示，否则直接提取数据
    if (&in == &cin)
    {
        cout << "依次输入商品代号，商品名称，价格和数量，用空格分隔，回车符确认：" << endl;
        cin >> g.id >> g.goods_name >> g.price >> g.num;
    }
    else
        in >> g.id >> g.goods_name >> g.price >> g.num;
    return in;
}

ostream &operator<<(ostream &out, Goods &g)
{
    out << setw(20) << g.id << setw(20) << g.goods_name << setw(20) << g.price << setw(20) << g.num;
    return out;
}

class Shopping_list // 购物菜单类
{
private:
    Goods *gs;   // 用于建立堆区数组，存放商品信息
    int nums;    // 堆区数组中的元素个数（商品种类数）
    float value; // 购物所需总金额
public:
    Shopping_list();                                            // 无参量的构造函数
    Shopping_list(const Shopping_list &m);                      // 拷贝构造函数，实现“深拷贝”
    int Find(Goods &x);                                         // 查询在堆数组中是否包含商品对象x
    void Append(Goods &x);                                      // 添加商品对象x
    Shopping_list &operator=(Shopping_list &m);                 // 复制运算符重载
    ~Shopping_list();                                           // 析构函数
    float Get_value();                                          // 获取总金额的接口函数
    Shopping_list &operator+=(Shopping_list &m);                // 实现将两个购物菜单对象合并为一个购物菜单对象
    void Readfile(const char *filename);                        // 从磁盘文件中读取一个购物菜单对象的数据
    void Savefile(const char *filename);                        // 将一个购物菜单对象保存到磁盘文件中
    friend ostream &operator<<(ostream &out, Shopping_list &m); // 插入运算符重载，实现在屏幕上输出购物菜单对象
};

Shopping_list::Shopping_list() // 无参量的构造函数
{
    gs = NULL;
    nums = 0;
    value = 0;
}
Shopping_list::Shopping_list(const Shopping_list &m) // 拷贝构造函数，实现“深拷贝”
{                                                    // 在此补充本段代码,实现“深拷贝”
}
int Shopping_list::Find(Goods &x) // 查询在堆数组中是否包含商品对象x
{                                 // 在此补充本段代码,查询在堆数组中是否包含对象x，如果包含x，返回所在堆区数组中的下标；否则返回-1。
    for (int i = 0; i < nums; i++)
    {
        if (gs[i].id == x.id)
            return i;
    }
    return -1;
}
void Shopping_list::Append(Goods &x) // 添加商品对象x
{                                    /*在此补充本段代码,添加商品对象x，如果x是一种新商品，就扩大堆区数组，加入新商品，并变更组成的种类数目和总金额；否则只需要更变原商品的数量和总金额。*/
    if (!gs)
    {
        gs = new Goods[1];
        gs[0] = x;
        nums += 1;
        value += x.price * x.num;
    }
    else
    {
        int temp1 = Find(x);
        if (temp1 != -1)
        {
            gs[temp1].num++;
            value += gs[temp1].price;
            return;
        }
        else
        {
            Goods *templist = new Goods[nums];
            for (int i = 0; i < nums; i++)
            {
                templist[i].Registe(gs[i].id, gs[i].goods_name, gs[i].price, gs[i].num);
            }
            delete[] gs;
            gs = new Goods[nums + 1];
            for (int i = 0; i < nums; i++)
            {
                gs[i] = templist[i];
            }
            gs[nums] = x;
            nums++;
            delete[] templist;
            value += x.price * x.num;
        }
    }
}
Shopping_list &Shopping_list::operator=(Shopping_list &m) // 复制运算符重载
{                                                         // 在此补充本段代码
}
Shopping_list::~Shopping_list() // 析构函数
{                               // 在此补充本段代码
}
float Shopping_list::Get_value() // 获取总金额的接口函数
{                                // 在此补充本段代码
    return value;
}
Shopping_list &Shopping_list::operator+=(Shopping_list &m) // 实现将两个购物菜单对象合并为一个购物菜单对象
{                                                          // 在此补充本段代码
    value = m.value + value;
    Goods *templist = new Goods[nums + m.nums];
    for (int i = 0; i < nums; i++)
    {
        templist[i] = gs[i];
    }
    for (int i = 0; i < m.nums; i++)
    {
        templist[nums + i] = m.gs[i];
    }
    int tempnums = nums + m.nums;
    Goods EmptyGoods;
    int RightCount = tempnums;
    for (int i = 0; i < tempnums - 1; i++)
    {
        for (int j = i + 1; j < tempnums; j++)
        {
            if (templist[i].goods_name == "***")
                continue;
            if (templist[i].id == templist[j].id)
            {
                templist[i].num += templist[j].num;
                templist[j] = EmptyGoods;
                RightCount--;
            }
        }
    }
    Goods *templist2 = new Goods[RightCount];
    int j = 0;
    for (int i = 0; i < tempnums; i++)
    {
        if (templist[i].goods_name != "***")
            templist2[j++] = templist[i];
    }
    delete[] templist;
    delete[] gs;
    gs = templist2;
    nums = RightCount;
}
void Shopping_list::Readfile(const char *filename) // 从磁盘文件中读取一个购物菜单对象的数据
{
    if (gs)
        delete[] gs;
    int i;
    char ch[100] = "****";
    ifstream in(filename);
    in >> nums;
    gs = new Goods[nums];
    in.getline(ch, 99);
    in.getline(ch, 99);
    for (i = 0; i < nums; i++)
    {
        in >> gs[i];
    }
    in.getline(ch, 99, ':');
    in >> value;
    in.close();
}
void Shopping_list::Savefile(const char *filename) // 将一个购物菜单对象保存到磁盘文件中
{                                                  // 在此补充本段代码
    ofstream out(filename);
    out << nums << "种商品" << endl;
    out << setw(20) << "商品代号" << setw(20) << "商品名称" << setw(20) << "价格" << setw(20) << "数量" << endl;
    for (int i = 0; i < nums; i++)
    {
        out << gs[i] << endl;
    }
    out << "共计总金额：" << value << endl;
    out.close();
}
ostream &operator<<(ostream &out, Shopping_list &m) // 插入运算符重载，实现在屏幕上输出购物菜单对象
{                                                   // 在此补充本段代码
    cout << m.nums << "种商品" << endl;
    cout << setw(20) << "商品代号" << setw(20) << "商品名称" << setw(20) << "价格" << setw(20) << "数量" << endl;
    for (int i = 0; i < m.nums; i++)
    {
        cout << m.gs[i] << endl;
    }
    cout << "共计总金额：" << m.value << endl;
    return out;
}

int main()
{
    int i;
    Goods g[4];
    g[0].Registe("0001", "方便面", 9.8, 4);
    g[1].Registe("0002", "暖水瓶", 19.9, 1);
    g[2].Registe("0003", "矿泉水", 1.2, 10);
    cin >> g[3];
    Shopping_list s[3];
    for (i = 0; i < 3; i++)
        s[0].Append(g[i]);
    for (i = 1; i < 4; i++)
        s[1].Append(g[i]);
    cout << s[0] << s[1];
    s[0] += s[1];
    s[0].Savefile("list.dat");
    s[2].Readfile("list.dat");
    cout << s[2];
    return 0;
}
