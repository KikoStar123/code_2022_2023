#include<iostream>
#include<iomanip>
using namespace std;

class Time{
    private:
        int hour;
        int min;
        int sec;
    public:
        Time(int h=0,int m=0,int s=0){
            hour=h;
            min=m;
            sec=s;
        }

        void tick(){
            sec++;
            if(sec==60){
                sec=0;
                min++;
            }
            if(min==60){
                min=0;
                hour++;
            }
            if(hour>=24){
                hour=0;
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const Time& time) {
        os << std::setfill('0') << std::setw(2) << time.hour << ":"
           << std::setw(2) << time.min << ":" << std::setw(2) << time.sec;
        return os;
    }
};

int main(){
    Time t1(23,59,58);
    for(int i=0;i<10;i++){
        t1.tick();
        cout<<t1<<endl;
    }
    return 0;
}