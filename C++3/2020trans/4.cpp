#include<iostream>
using namespace std;

class Set{

    private:
        int* arry;
        int size;
        int max_size;
    public:
        Set(int max_size=0){
            this->max_size=max_size;
            size=0;
            arry=new int[max_size];
        }

        ~Set(){
            delete[] arry;
        }

        int find(int x){
            for(int i=0;i<size;i++){
                if(arry[i]==x){
                    return i;
                }
            }
            return -1;
        }

        void add(int value){
            if(size<max_size&&find(value)==-1){
                arry[size]=value;
                size++;
            }
        }

        void add(int value[],int s){
            for(int i=0;i<s;i++){
                add(value[i]);
            }  
        }

        Set operator+(Set& setlist){
            Set temp(max_size+setlist.max_size);
            temp.add(setlist.arry,setlist.size);
            temp.add(arry,size);
            
            return temp;
        }  

        friend ostream& operator<<(ostream&os,const Set& setlist){
            for(int i=0;i<setlist.size;i++){
                os<<setlist.arry[i]<<" ";
            }
            return os;
        }

        
};

int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int b[10]={4,5,6,7,8,9,10,11,12,13};
    Set A1(20);
    Set A2(20);
    A1.add(a,10);
    A2.add(b,10);
    Set A3=A1+A2;
    cout<<A3<<endl;
    return 0;
}