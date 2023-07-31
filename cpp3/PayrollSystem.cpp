#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;


class Date{
    public:
        int day,year;
        string month;
        Date(string month="January",int day=1,int year=1){
            this->month=month;
            this->day=day;
            this->year=year;
        }
        friend ostream& operator<<(std::ostream& os,Date const& date){
            os<<date.month<<" "<<date.day<<" "<<date.year;
            return os;
        }
};

class Employee{

    protected:
        string name;
        string SSN;
        Date date;
    public:
        Employee(string name="",string SSN="000-00-0000",Date date=Date("January",1,1)){
            this->name=name;
            this->SSN=SSN;
            this->date=date;
        }

        virtual void print() const{
            cout<<"Birthday: "<<date<<endl;
            cout<<"social security number: "<<SSN<<endl;
            
        }

        bool isBirthday() const{
            Date Ntime;
            time_t nowtime;
        struct tm* ptm;
        time(&nowtime);
        ptm = localtime(&nowtime);
        string month;

    switch(ptm->tm_mon+1){
        case 1:
            month="January";
            break;
        case 2:
            month="February";
            break;
        case 3:
            month="March";
            break;
        case 4:
            month="April";
            break;
        case 5:
            month="May";
            break;
        case 6:
            month="June";
            break;
        case 7:
            month="July";
            break;
        case 8:
            month="August";
            break;
        case 9:
            month="September";
            break;
        case 10:
            month="October";
            break;
        case 11:
            month="November";
            break;
        case 12:
            month="December";
            break;
    }

    Ntime=Date(month,ptm->tm_mday,ptm->tm_year+1900);

            if(date.year==Ntime.year && date.month==Ntime.month&& date.day==Ntime.day){
                return true;
            }
            return false;
        }

        virtual ~Employee(){}

};

class Salaried:public Employee{
    private:
        double worktime;
        double weekly_salary;
        double earned;
        bool IB;
        
    public:
        Salaried(string name="",string SSN="000-00-0000",Date date=Date("January",1,1),double worktime=0):
        Employee(name,SSN,date){
            this->worktime=worktime;
            weekly_salary=800.00;
            earned=worktime*weekly_salary;
            if(isBirthday()){
                earned+=100;
                IB=true;
                }else{
                    IB=false;
                }
        }

        virtual void print() const{
            cout<<"salaried employee:"<<name<<endl;
            Employee::print();
            cout<<"weekly salary:"<<fixed<<setprecision(2)<<weekly_salary<<endl;
            if(IB)
                cout<<"HAPPY BIRTHDAY"<<endl;
            cout<<"earned: "<<" $"<<earned<<endl;
        }

        virtual ~Salaried(){
            cout<<"deleting object of class SalariedEmployee"<<endl;
        }

        
};

class hourly:public Employee{
    private:
        double hourly_wage;
        double earned;
        double worktime;
        bool IB;

    public:
        hourly(string name="",string SSN="000-00-0000",Date date=Date("January",1,1),double worktime=0):
        Employee(name,SSN,date){
            this->hourly_wage=16.75;
            this->worktime=worktime;
            earned=hourly_wage*worktime;
            if(isBirthday()){
                earned+=100;
                IB=true;
                }else{
                    IB=false;
                }
        }

        virtual void print() const{
            cout<<"hourly employee:"<<name<<endl;
            Employee::print();
            cout<<"hourly wage:"<<fixed<<setprecision(2)<<hourly_wage<<"; "<<"hours worked:"<<fixed<<setprecision(2)<<worktime<<endl;
            if(IB)
                cout<<"HAPPY BIRTHDAY"<<endl;
            cout<<"earned: "<<" $"<<earned<<endl;
        }

        virtual ~hourly(){
                    cout<<"deleting object of class hourlyEmployee"<<endl;
                }
        };


class commission:public Employee{
    private:
        double GS;
        double rate;
        double earned;
        bool IB;
    public:
        commission(string name="",string SSN="000-00-0000",Date date=Date("January",1,1),double GS=0):
        Employee(name,SSN,date)
        {
            this->GS=GS;
            this->rate=0.06;
            earned=GS*rate;
            if(isBirthday()){
                earned+=100;
                IB=true;
                }else{
                    IB=false;
                }
        }

        virtual void print() const{
            cout<<"commission employee:"<<name<<endl;
            Employee::print();
            cout<<"gross sales:"<<fixed<<setprecision(2)<<GS<<endl;
            cout<<"commission rate:"<<fixed<<setprecision(2)<<rate<<endl;
            if(IB)
                cout<<"HAPPY BIRTHDAY"<<endl;
            cout<<"earned: "<<" $"<<earned<<endl;
        }

        virtual ~commission(){
                    cout<<"deleting object of class commissionEmployee"<<endl;
                }
};

class base_salaried_commission:public Employee{
    private:
        double GS;
        double rate;
        double earned;
        double base_salary;
        bool IB;
    public:
        base_salaried_commission(string name="",string SSN="000-00-0000",Date date=Date("January",1,1),double GS=0):
        Employee(name,SSN,date){
            this->GS=GS;
            this->rate=0.04;
            this->base_salary=300.00;
            earned=GS*rate+base_salary;
            if(isBirthday()){
                earned+=100;
                IB=true;
                }else{
                    IB=false;
                }
        }

        virtual void print() const{
            cout<<"base salaried commission employee:"<<name<<endl;
            Employee::print();
            cout<<"gross sales:"<<fixed<<setprecision(2)<<GS<<endl;
            cout<<"commission rate:"<<fixed<<setprecision(2)<<rate<<endl;
            cout<<"base salary:"<<fixed<<setprecision(2)<<base_salary<<endl;
            if(IB)
                cout<<"HAPPY BIRTHDAY"<<endl;
            cout<<"earned: "<<" $"<<earned<<endl;
        }
};

int main(){

    vector<Employee*> employees(4);
    Salaried A1("John Smith","111-11-1111",Date("June",15,1944),1);
    hourly A2("Karen Price","222-22-2222",Date("April",29,1960),40);
    commission A3("Sue Jones","333-33-3333",Date("September",8,1954),10000.00);
    base_salaried_commission A4("Bob Lewis","111-11-1111",Date("March",2,1965),5000);
    employees[0]=&A1;
    employees[1]=&A2;
    employees[2]=&A3;
    employees[3]=&A4;
    for(int i=0;i<4;i++){
        employees[i]->print();
        cout<<endl;
    }

}