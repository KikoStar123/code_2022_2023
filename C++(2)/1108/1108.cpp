/*
 * @Author: KIKOSTAR 842544563@outlook.com
 * @Date: 2023-03-16 20:48:46
 * @LastEditors: KIKOSTAR 842544563@outlook.com
 * @LastEditTime: 2023-03-16 20:49:01
 * @FilePath: \CODE\C++(2)\1108\1108.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
using namespace std;

template<typename T>void printarray(T arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

int main(){
    int a[5]={1,2,3,4,5};
    double b[3] = {1.1,2.2,3.3};
    printarray(a,5);
    cout<<endl;
    printarray(b,3);
    return 0;
}