#include<iostream>
#include<ctime>
using namespace std;

template<typename T>
void sort(T*list,int size){
    for(int i=0;i<size-1;i++){
        for(int j=size-1;j>i;j--){
            if(list[j]<list[i])
                swap(list[j],list[i]);
        }
    }
}

template<typename T>
int binary_search(T*list,int size,T target){
    int left=0;
    int right=size-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(target==list[mid]){
            return mid;
        }
        if(target>list[mid]){
            left=mid+1;
        }else{
            right=mid-1;
        }
        return -1;
            
    }
}

int main(){
    srand(time(0));
    int a[10];
    char b[10];
    
    for(int i=0;i<10;i++){
        a[i]=rand()%101;
        cin>>b[i];
    }
    sort(a,10);
    sort(b,10);
    int target1=3;
    char target2='a';
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    cout<<binary_search(a,10,target1)<<endl;
    cout<<binary_search(b,10,target2)<<endl;


    return 0;
}