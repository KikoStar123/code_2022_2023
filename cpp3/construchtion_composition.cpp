#include<iostream>
using namespace std;

class Date{
    private:
        int year, month, day;
    public:
        
        Date(int y=2014,int m=1,int d=1) : year(y), month(m), day(d){}
        void print() const {
            cout << year << "-" << month << "-" << day;
        }   

        friend ostream& operator<<(ostream& os,const Date& date){
            os<<date.year<<"-"<<date.month<<"-"<<date.day;
            return os;

        }


};

class FinalTest{
    private:
        string name;
        Date date;
    public:
        FinalTest(string n,int y,int m,int d) : name(n), date(y,m,d){}
        FinalTest(string n,Date date=Date(2014,1,1)) : name(n), date(date){}
        void print() const {
            cout << name <<":"<<date<<endl;
        }

        void setDue(Date d){
            date = d;
        }
            
};


int main(){

    FinalTest item1("C++ Test",Date(2014,6,2));
    item1.print();
    FinalTest item2("Java");
    item2.print();
    item2.setDue(Date(2014,6,10));
    item2.print();
    return 0;

}