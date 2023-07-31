#include<iostream>
using namespace std;

template<typename T>void myswap(T&x,T&y){
    T temp=x;
    x=y;
    y=temp;
}

int main(){
    int a,b;
    double c,d;
    cin>>a>>b>>c>>d;
    myswap(a,b);
    cout<<a<<" "<<b<<endl;
    myswap(c,d);
    cout<<c<<" "<<d<<endl;
    return 0;
}