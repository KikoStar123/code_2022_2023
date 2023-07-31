#include<iostream>
using namespace std;


//please wirte an 冒泡排序 using c++
int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int temp;
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10 - i;j++){
            if(a[j] > a[j + 1]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                }
                }
                }
}

