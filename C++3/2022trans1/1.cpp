#include<iostream>
#include<ctime>
using namespace std;

template<typename T>
void sorting(T a[],int size){
    for(int i=0;i<size;i++){
        for(int j=size-1;j>i;j--){
            if(a[j]>a[i])
                swap(a[j],a[i]);
        }
    }
}

template<typename T>
int BinaryS(T a[],int size,T target){
    int left=0;
    int right=size-1;
    int mid;
    while(left<=right){
        mid=left+(right-left)/2;
        if(a[mid]==target){
            return mid;
        }
        else if(a[mid]>target){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return -1;
}

int main(){
    srand(time(0));
    int a[10];
    char b[10];
    cin>>b;
    for (int i = 0; i < 10; i++)
    {
        a[i]=rand()%100;
    }
    sorting(a,10);
    sorting(b,10);
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    cout<<BinaryS(a,10,3)<<endl;
    cout<<BinaryS(b,10,'a')<<endl;
    return 0;
}