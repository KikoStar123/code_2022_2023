#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}


class RationalNumber{
    private:
        int fenzi;
        int fenmu;
    public:
        RationalNumber(){
            fenzi=0;
            fenmu=1;
            Reduce();
        }
        RationalNumber(int fenzi,int fenmu){
            this->fenzi=fenzi;
            this->fenmu=fenmu;
            Reduce();
        }
        
        RationalNumber Reduce(){
            int gcd1=gcd(fenzi,fenmu);
            fenzi=fenzi/gcd1;
            fenmu=fenmu/gcd1;
            return *this;
        }

        RationalNumber operator+(RationalNumber other){
            RationalNumber temp;
            temp.fenmu=fenmu*other.fenmu;
            temp.fenzi=fenzi*other.fenmu+fenmu*other.fenzi;
            temp.Reduce();
            return temp;
        }

        RationalNumber operator-(RationalNumber other){
            RationalNumber temp;
            temp.fenmu=fenmu*other.fenmu;
            temp.fenzi=fenzi*other.fenmu-fenmu*other.fenzi;
            temp.Reduce();
            return temp;
        }

        RationalNumber operator*(RationalNumber other){
            RationalNumber temp;
            temp.fenmu=fenmu*other.fenmu;
            temp.fenzi=fenzi*other.fenzi;
            temp.Reduce();
            return temp;
        }

        RationalNumber operator/(RationalNumber other){
            RationalNumber temp;
            temp.fenmu=fenmu*other.fenzi;
            temp.fenzi=fenzi*other.fenmu;
            temp.Reduce();
            return temp;
        }

        double getdoublevalue(){
            return (double)fenzi/fenmu;
        }
        
        bool operator>(RationalNumber other){
            return (this->getdoublevalue()>other.getdoublevalue());
        }

        bool operator<(RationalNumber other){
            return (this->getdoublevalue()<other.getdoublevalue());
        }

        bool operator>=(RationalNumber other){
            return (this->getdoublevalue()>=other.getdoublevalue());
        }

        bool operator<=(RationalNumber other){
            return (this->getdoublevalue()<=other.getdoublevalue());
        }

        bool operator==(RationalNumber other){
            return (this->getdoublevalue()==other.getdoublevalue());
        }

        bool operator!=(RationalNumber other){
            return !((*this)==other);
        }

        int getfenzi(){
            return fenzi;
        }

        int getfenmu(){
            return fenmu;
        }

        void swapfenzifenmu(){
            fenzi=0-fenzi;
            fenmu=0-fenmu;
        }

        void printRational(){
            std::cout<<fenzi<<"/"<<fenmu;
        }

        friend ostream& operator<<(ostream& os, RationalNumber other){
            if(other.getfenzi()*other.getfenmu()<0){
                other.swapfenzifenmu();
            }
            if(other.fenmu!=1)
                os<<other.fenzi<<"/"<<other.fenmu;
                else{
                    os<<other.fenzi;
                }
            return os;
        }
};

int main(){
    RationalNumber c( 7, 3 ), d( 3, 9 ), x;
    c.printRational();
std::cout << " + " ;
d.printRational();
std::cout << " = ";
x = c + d; // test overloaded operators + and = x.printRational();
std::cout<<x;
std::cout << '\n';
c.printRational();
std::cout << " - " ;
d.printRational();
std::cout << " = ";
x = c - d; 
std::cout<<x;
// test overloaded operators - and = x.printRational();
 
std::cout << '\n';
c.printRational();
std::cout << " * " ;
d.printRational();
std::cout << " = ";
x = c * d; // endl
std::cout<<x;
std::cout << '\n';
c.printRational();
std::cout << " / " ;
d.printRational();
std::cout << " = ";
x = c / d; // test overloaded operators / and = x.printRational();
std::cout<<x;
std::cout << '\n';
c.printRational();
std::cout << " is:\n";
// test overloaded greater than operator
std::cout << ( ( c > d ) ? " > " : " <= " );
d.printRational();
std::cout << " according to the overloaded > operator\n";
// test overloaded less than operator
std::cout << ( ( c < d ) ? " < " : " >= " );
d.printRational();
std::cout << " according to the overloaded < operator\n";
// test overloaded greater than or equal to operator
std::cout << ( ( c >= d ) ? " >= " : " < " );
d.printRational();
std::cout << " according to the overloaded >= operator\n";
// test overloaded less than or equal to operator
std::cout << ( ( c <= d ) ? " <= " : " > " );
d.printRational();
std::cout << " according to the overloaded <= operator\n";
// test overloaded equality operator
std::cout << ( ( c == d ) ? " == " : " != " );
d.printRational();
std::cout << " according to the overloaded == operator\n";
// test overloaded inequality operator
std::cout << ( ( c != d ) ? " != " : " == " );
d.printRational();
std::cout << " according to the overloaded != operator" << endl; return 0;
return 0;
 } // end main