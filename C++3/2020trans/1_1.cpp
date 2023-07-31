#include<iostream>
#include<cmath>
#include<vector>
#include<string>

using namespace std;

const string unit[]=
{"", "拾", "佰", "仟", "万", "拾万", "佰万", "仟万", "亿", "拾亿", "佰亿", "仟亿"};

const string digit[]={
    "零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"
};

vector<string> list;

string TransToChinese(float number){
    string result;
    bool negetive;
    if(number<0){
        negetive=true;
    }else
        negetive=false;

    long long zhengshu=(long long)number;  
    int fenshu=round((number-zhengshu)*100);
    if(zhengshu==0)
        list.push_back("零");
        
        else{
            int num=zhengshu%10;
            int index=0;
            while(zhengshu!=0){
                num=zhengshu%10;
                if(num!=0){
                    list.push_back(unit[index]);
                    list.push_back(digit[num]);
                }else if(!list.empty()&&list.back()=="零"){
                    list.push_back(digit[0]);
            }
            index++;
            zhengshu/=10;}
        }

        if(negetive){
            list.push_back("负");
        }

        for(auto it=list.rbegin();it!=list.rend();++it){
            result+=*it;
        }

        result+="元";

        int xiaoshu1=fenshu/10;
        int xiaoshu2=fenshu%10;
        if(xiaoshu1!=0){
            result+=digit[xiaoshu1];
            result+="角";
        }
        if(xiaoshu2!=0){
            result+=digit[xiaoshu2];
            result+="分";
        }
        
        return result;
}

int main(){
    float number;
    cin>>number;
    string result;
    result=TransToChinese(number);
    cout<<result<<endl;
    return 0;
        
}