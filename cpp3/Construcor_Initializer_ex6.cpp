#include<iostream>
#include<cmath>
#define PI 3.14
using namespace std;

class Position{
    private:
        double x, y;
    public:
        Position(double x=0, double y=0){
            this->x = x;
            this->y = y;
        }
        double getX(){
            return x;
        }
        double getY(){
            return y;
        }
        ~Position(){}

};

class Shape{
string name;
    public:
        Shape(string name="NA"){
            this->name=name;
        }

        virtual void print(){
            cout<<name<<":"<<endl;
        }

        virtual double area(){
            cout<<"area:"<<0<<endl;
            return 0;
        }
        ~Shape(){}
};

class Circle:public Shape{
    protected:
        double radius;
        Position center;
        string name;
    public:
        
    Circle(string name="Circle",Position cc=Position(0,0),double radius=0):Shape(name){
        center=cc;
        this->name=name;
        this->radius=radius;
    }

    virtual double area(){
        return PI*radius*radius;
    }

    virtual void print(){
        cout<<"name:"<<name<<endl;
        cout<<"radius:"<<radius<<endl;
        cout<<"center:"<<center.getX()<<","<<center.getY()<<endl;
        cout<<"area:"<<area()<<endl;
    }

    ~Circle(){}

};

class Triangle:public Shape{
    protected:
        double a,b,c;
        string name;
    public:
        Triangle(string name="Triangle",double a=0,double b=0,double c=0){
            this->a=a;
            this->b=b;
            this->c=c;
            this->name=name;
        }

        virtual double area(){
            double s=(a+b+c)/2;
            return sqrt(s*(s-a)*(s-b)*(s-c));
        }

        virtual void print(){
            cout<<"name:"<<name<<endl;
            cout<<"a:"<<a<<endl;
            cout<<"b:"<<b<<endl;
            cout<<"c:"<<c<<endl;
            cout<<"area:"<<area()<<endl;
        }

        ~Triangle(){}
};

class Rectangle:public Shape{
    protected:
        double a,b;
        Position LB;
        string name;
    public:
        Rectangle(string name="Rectangle",Position leftbottom=Position(0,0),double a=0,double b=0){
            this->a=a;
            this->b=b;
            LB=leftbottom;
            this->name=name;
        }

        virtual double area(){
            return a*b;
        }

        virtual void print(){
            cout<<"name:"<<name<<endl;
            cout<<"a:"<<a<<endl;
            cout<<"b:"<<b<<endl;
            cout<<"leftbottom:"<<LB.getX()<<","<<LB.getY()<<endl;
            cout<<"area:"<<area()<<endl;
        }
        ~Rectangle(){}
};

class Square:public Rectangle{
    private:
        Circle incircle;
    public:
        Square(string name="Incircle",Position leftbottom=Position(0,0),double a=0,double b=0)
        :Rectangle("Rectangle",leftbottom,a,b){
            incircle=Circle(name,Position(LB.getX()+a/2,LB.getY()+b/2),min(a,b)/2);
        }
        
        virtual double area(){
            return incircle.area();
        }
        
        virtual void print(){
            incircle.print();
        }
        
        ~Square(){}
        
};

int main(){
    Circle A1("Circ",Position(0,0),3.5);
    Triangle B1("Tri",3,4,5);
    Rectangle C1("Rect",Position(0,0),3,4);
    Square D1("Square",Position(0,0),3,4);

    A1.print();
    B1.print();
    C1.print();
    D1.print();
    return 0;
}