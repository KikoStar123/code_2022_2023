#include<iostream>
#include<cmath>
using namespace std;

class HugeInter{
int list[40];
int size;
    public:
    void input(char* data);
    void output();
    HugeInter& operator+(HugeInter& other);
    HugeInter& operator-(HugeInter& other);
    bool isEqualto(HugeInter& other);
    bool isNotEqualto(HugeInter& other);
    bool isGreaterThan(HugeInter& other);
    bool isLessThan(HugeInter& other);
    bool isGreaterThanOrEqualTo(HugeInter& other);
    bool isLessThanOrEqualTo(HugeInter& other);
    bool isZero();
    HugeInter(char* data="");
};

HugeInter::HugeInter(char* data){
    for(int i=0; i<40; i++){
        list[i]=0;
    }
    size=strlen(data);
    input(data);
}

void HugeInter::input(char* data){
    while(*data!='\0'){
        int i=0;
        list[i++]=*data-'0';
        data++;
    }
}

void HugeInter::output(){
    for(int i=0;i<size;i++){
        cout<<list[i];
    }
    cout<<endl;
}

HugeInter& HugeInter::operator+(HugeInter& other){
    for(int i=0;i<max(size,other.size);i++){
        int tempnum=list[i]+other.list[i];
        list[i+1]+=tempnum/10;
        list[i]=tempnum%10;
    }
    size=max(size,other.size);
    return *this;
}

HugeInter& HugeInter::operator-(HugeInter& other){
    for(int i=0;i<max(size,other.size);i++){
        int tempnum=list[i]-other.list[i];
        list[i+1]+=tempnum/10;
        list[i]=tempnum%10;
    }
    size=max(size,other.size);
    return *this;
}

int main(){

    return 0;
}