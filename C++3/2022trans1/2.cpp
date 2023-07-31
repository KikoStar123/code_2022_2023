#include<iostream>
using namespace std;

class CVector{
    private:
        double a,b;
    public:
        CVector(double x=0.0,double y=0.0){
            a=x;
            b=y;
        }

        double modulus(){
            return sqrt(a*a+b*b);
        }

        double operator*(CVector&other){
            double ta,tb;
            ta=a*other.a;
            tb=b*other.b;
            return ta+tb;

        }

        double costheta(CVector& other){
            return ((*this)*other)/(this->modulus()*other.modulus());
        }

        friend ostream& operator<<(ostream&os,const CVector& v){
            os<<"("<<v.a<<","<<v.b<<")";
            return os;
        }
};

int main(){
    CVector v1(1,0);
    CVector v2(0,1);

    cout<<"v1:"<<v1<<"v2:"<<v2<<endl;
    double costheta1=v1.costheta(v2);
    if(costheta1==1)
    {
        cout<<"v1 and v2 are smiliar"<<endl;
    }

    if(costheta1==0){
        cout<<"v1 and v2 are perpendicular"<<endl;
    }
    return 0;
}