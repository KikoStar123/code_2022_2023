#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Student{
    public:
        Student(string strId,string strName){
            this->strId=strId;
            this->strName=strName;
        }

        friend ostream& operator<<(ostream& os ,Student const& s){
            os<<s.strId<<" "<<s.strName;
            return os;
        }

        virtual bool getbResult()const =0;

        virtual void print(){}

    protected:
        string strId;
        string strName;

};

class UStudent:public Student {
    public:
        UStudent(string strId,string strName,double dCredits,bool bResult)
        :Student(strId,strName)
        {
            this->dCredits=dCredits;
            this->bResult=bResult;
        }

        friend ostream& operator<<(ostream&os,UStudent & s){  
            os<<s.strId<<" "<<s.strName<<" ";
            os<<s.dCredits<<" "<<s.bResult<<" ";
            return os;
        }

        bool getbResult()const { return this->bResult; }

        void print(){
            cout<<*this<<endl;
            ofstream a("studentGraduate.data",ios::app);
            a<<*this<<endl;
            a.close();
        }

    protected:
        double dCredits;
        bool bResult;
};

class GStudent:public UStudent {
    public:
        GStudent(string strId,string strName,
        double dCredits,bool bResult,bool bTeaching,bool bResearch):
        UStudent(strId,strName,dCredits,bResult)
        {
            this->bTeaching=bTeaching;
            this->bResearch=bResearch;
        }

        friend ostream& operator<<(ostream&os,GStudent & s){  
            os<<s.strId<<" "<<s.strName<<" ";
            os<<s.dCredits<<" "<<s.bResult<<" ";
            os<<s.bTeaching<<" "<<s.bResearch<<" ";
            return os;
        }

        bool getbResult()const { return this->bResult; }

        void print(){
            cout<<*this<<endl;
            ofstream a("studentGraduate.data",ios::app);
            a<<*this<<endl;
            a.close();
        }

    protected:
        bool bTeaching;
        bool bResearch;
};

int main(){
    
    vector<Student*>s(4);
    s[0]=new UStudent("1001","Donald",156,1);
    s[1]=new UStudent("1002","Vivion",142,0);
    s[2]=new GStudent("1003","Crris",36,1,1,1);
    s[3]=new GStudent("2004","Cindy",38,1,1,1);

    for(int i=0; i<4; i++){
        if(s[i]->getbResult()){
            s[i]->print();
        }
    }
    return 0;
}