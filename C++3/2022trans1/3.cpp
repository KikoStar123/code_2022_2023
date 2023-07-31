#include<iostream>
#include<string.h>
using namespace std;

class Date{

    public:
        Date(int year=2022,int month=6,int day=26){
            this->year=year;
            this->month=month;
            this->day=day;
        }

        friend ostream& operator<<(ostream&os,Date& date){
            os<<date.year<<'-'<<date.month<<'-'<<date.day;
            return os;
        }

    

    private:
        int year,month,day;

};

class Items{

    public:
        Items(char*name="",int number=0,double price=0){
            char* tempname=item_name;
            while(*name!='\0'){
                *tempname++=*name++;
            }
            this->price=price;
            this->number=number;
            this->amount=price*double(number);
        }

        friend ostream& operator<<(ostream& os,Items& items){
            os<<"itemName:"<<items.item_name
            <<",number:"<<items.number
            <<",price:"<<items.price
            <<",amount:"<<items.amount;
            return os;
        }

        double getAmount(){
            return this->amount;
        }

    private:
        char item_name[20];
        double price;
        int number;
        double amount;
};

class Customer{

    private:
        string ID;
        Date date;
        Items* items;
        int listcount;
        double totalamount;
    public:
        Customer(string ID,Date date){
            this->ID=ID;
            this->date=date;
            listcount=0;
        }

        void selectItem(char*item_name,int number,double price){
            
            Items* tempitems=new Items[listcount+1];
            for(int i=0;i<listcount;i++){
                tempitems[i]=items[i];
            }
            delete items;
            items=tempitems;
            Items newitem(item_name,number,price);
            items[listcount++]=newitem;
        }

        void total(){
            for(int i=0;i<listcount;i++){
                totalamount+=items[i].getAmount();
            }
        }

        friend ostream& operator<<(ostream&os,Customer& customer){
            os<<"Customer ID:"<<customer.ID<<endl;
            os<<"Purchase date:"<<customer.date<<endl;
            os<<"The purchase items are listed as follows:"<<endl;
            for(int i=0;i<customer.listcount;i++){
                os<<i+1<<":"<<customer.items[i]<<endl;
            }
            customer.total();
            os<<"The total amount of the Purchase items is:"
            <<customer.totalamount;
            return os;
        }

        void print(){
            cout<<*this<<endl;
        }
};

int main(){
    Date d1(2022,6,18);
    Customer c1("1100001",d1);
    c1.selectItem("cup",2,9.2);
    c1.selectItem("jacket",1,50);
    c1.selectItem("steak",3,10);
    c1.print();

    return 0;
}